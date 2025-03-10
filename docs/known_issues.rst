.. _known_issues:

Known issues
############

.. contents::
   :local:
   :depth: 2

.. include:: /includes/zigbee_r22_note.txt

A known issue can list one or both of the following entries:

* **Affected platforms:**

  If a known issue does not have any specific platforms listed, it is valid for all hardware platforms.

* **Workaround:**

  Some known issues have a workaround.
  Sometimes, they are discovered later and added over time.

|addon| v1.0.0
**************

**KRKNWK-19894: The Device Firmware Upgrade (DFU) from the nRF Connect SDK v2.5.X or older to a newer version may cause fatal error or abnormal behavior**
  
  .. toggle::
  
    The issue occurs when the device initially uses firmware built with the |NCS| v2.5.X or earlier, and has the ZCL Reporting feature configured (which means it reports selected attributes).
    Subsequently, the DFU is performed where the new firmware is built based on the |NCS| v2.6.0 or later.

    During the upgrade, the NVRAM content is preserved.
    However, part of this content has a structure that is incompatible with the new firmware, leading to abnormal behavior.

    The attribute reporting stops working correctly.
    The device frequently sends the Report Attributes command, but the messages are corrupted (empty).
    This condition of the device likely prevents remote reconfiguration.
    In some cases of cluster configuration, the firmware may encounter a fatal error every time it starts.

    **Workaround:** After upgrading the device, perform an NVRAM erase (complete or specifically targeting the part with the ``ZB_NVRAM_ZCL_REPORTING_DATA`` ID).
    This method prevents abnormal behavior, but it leads to the loss of configuration data, requiring you to reconfigure the device.
   
**NCSIDB-1336: Zigbee Router device cannot rejoin after missing Network Key update or rotation**

  .. toggle::

    If a Zigbee Router device does not receive a Network Key update or rotation messages (such as because of an ongoing reset or being powered off), it will not rejoin to a Zigbee Coordinator and will use old keys for communication.

    The Zigbee R22 Core Specification, section 4.3.6.1 says that "A device that is operating in a network and has missed a network key update may also use these procedures to receive the latest network key", referring to the procedure to get a new network key.
    Since it uses the word MAY, not SHOULD, it means the ZBOSS stack implementation does not violate the specification.
    In addition, BDB 3.0 does not describe a procedure that can be used by a Zigbee Router device to verify if the security keys it uses are still valid.

    **Workaround:** You can extend a Zigbee Router device application to handle this scenario.
    This is done by handling the ``ZB_NLME_STATUS_INDICATION`` status that contains the ``ZB_NWK_COMMAND_STATUS_BAD_KEY_SEQUENCE_NUMBER`` status.
    It is not advised to proceed with a rejoin immediately after the first ``ZB_NWK_COMMAND_STATUS_BAD_KEY_SEQUENCE_NUMBER``, because this could make the network vulnerable to attackers trying to force a rejoin without knowing the network key.

    The signal handling logic is as follows:

    .. code-block:: c

      void zboss_signal_handler(zb_bufid_t bufid)
      {
              zb_zdo_app_signal_hdr_t *sig_hndler = NULL;
              zb_zdo_app_signal_type_t sig = zb_get_app_signal(bufid, &sig_hndler);

              /* Update network status LED. */
              zigbee_led_status_update(bufid, ZIGBEE_NETWORK_STATE_LED);



              switch (sig) {

      case ZB_NLME_STATUS_INDICATION:
              zb_zdo_signal_nlme_status_indication_params_t *nlme_status_ind = ZB_ZDO_SIGNAL_GET_PARAMS(sig_hndler, zb_zdo_signal_nlme_status_indication_params_t);


      if (nlme_status_ind->nlme_status.status ==  ZB_NWK_COMMAND_STATUS_BAD_KEY_SEQUENCE_NUMBER) {
                                      // optional check connection
                                      // optional rejoin if necessary
      }
      break;

      default:
              /* Call default signal handler. */
              ZB_ERROR_CHECK(zigbee_default_signal_handler(bufid));
              break;

              }
      }

    After receiving several (for example, five) status messages with a bad key sequence number, check if the device is connected to the network, such as by calling the :c:func:`zb_zdo_simple_desc_req` function.
    If the returned message status is not ``ZB_ZDP_STATUS_SUCCESS``, initiate the rejoin procedure by calling the :c:func:`zb_bdb_initiate_tc_rejoin` function.
    The device will switch the key and successfully rejoin network, whether the network is open or closed.

**KRKNWK-14024: Fatal error when the network coordinator factory resets in the Identify mode**

  .. toggle::

    A fatal error occurs when the :ref:`Zigbee network coordinator <zigbee_network_coordinator_sample>` triggers factory reset in the Identify mode.

    **Workaround:** Modify your application, so that the factory reset is requested only after the Identify mode ends.

**KRKNWK-12937: Activation of Sleepy End Device must be done at the very first commissioning procedure for Zigbee light switch sample**

  .. toggle::

    After programming the :ref:`Zigbee light switch <zigbee_light_switch_sample>` sample and its first commissioning, Zigbee End Device joins the Zigbee network as a normal End Device. Pressing **Button 3** does not switch the device to the Sleepy End Device configuration.

    **Workaround:** Keep **Button 3** pressed during the first commissioning procedure.

**KRKNWK-12615: Get Group Membership Command returns all groups the node is assigned to**

  .. toggle::

    Get Group Membership Command returns all groups the node is assigned to regardless of the destination endpoint.

**KRKNWK-12115: Simultaneous commissioning of many devices can cause the Coordinator device to assert**

  .. toggle::

    The Zigbee Coordinator device can assert when multiple devices are being commissioned simultaneously.
    In some cases, the device can end up in the low memory state as the result.

    **Workaround:** To lower the likelihood of the Coordinator device asserting, increase its scheduler queue and buffer pool by completing the following steps:

    1. Create your own custom memory configuration file by creating an empty header file for your application, similar to :file:`include/zb_mem_config_custom.h` header file in the :ref:`Zigbee light switch <zigbee_light_switch_sample>` sample.
    #. Copy the contents of :file:`zb_mem_config_max.h` memory configuration file to the memory configuration header file you have just created.
       The Zigbee Network Coordinator sample uses the contents of the memory configuration file by default.
    #. In your custom memory configuration file, locate the following code:

      .. code-block:: c

          /* Now if you REALLY know what you do, you can study zb_mem_config_common.h and redefine some configuration parameters, like:
          #undef ZB_CONFIG_SCHEDULER_Q_SIZE
          #define ZB_CONFIG_SCHEDULER_Q_SIZE 56
          */

    #. Replace the code you have just located with the following code:

      .. code-block:: c

          /* Increase Scheduler queue size. */
          undef ZB_CONFIG_SCHEDULER_Q_SIZE
          define ZB_CONFIG_SCHEDULER_Q_SIZE XYZ
          /* Increase buffer pool size. */
          undef ZB_CONFIG_IOBUF_POOL_SIZE
          define ZB_CONFIG_IOBUF_POOL_SIZE XYZ

    #. To increase the scheduler queue size, replace ``XYZ`` next to ``ZB_CONFIG_SCHEDULER_Q_SIZE`` with the value of your choice, ranging from ``48U`` to ``256U``.
    #. To increase the buffer pool size, replace ``XYZ`` next to ``ZB_CONFIG_IOBUF_POOL_SIZE`` with the value of your choice, ranging from ``48U`` to ``127U``.

**KRKNWK-12017: Zigbee End Device does not recover from broken rejoin procedure**

  .. toggle::

    If the Device Announcement packet is not acknowledged by the End Device's parent, joiner logic is stopped and the device does not recover.

    **Workaround:** Complete the following steps to detect when the rejoin procedure breaks and reset the device:

    1. Introduce helper variable ``joining_signal_received``.
    #. Extend ``zigbee_default_signal_handler()`` by completing the following steps:

      a. Set ``joining_signal_received`` to ``true`` in the following signals: ``ZB_BDB_SIGNAL_DEVICE_FIRST_START``, ``ZB_BDB_SIGNAL_DEVICE_REBOOT``, ``ZB_BDB_SIGNAL_STEERING``.
      #. If ``leave_type`` is set to ``ZB_NWK_LEAVE_TYPE_REJOIN``, set ``joining_signal_received`` to ``false`` in the ``ZB_ZDO_SIGNAL_LEAVE`` signal.
      #. Handle the ``ZB_NLME_STATUS_INDICATION`` signal to detect when End Device failed to transmit packet to its parent, reported by signal's status ``ZB_NWK_COMMAND_STATUS_PARENT_LINK_FAILURE``.

    See the following snippet for an example:

    .. code-block:: c

      /* Add helper variable that will be used for detecting broken rejoin procedure. */
      /* Flag indicating if joining signal has been received since restart or leave with rejoin. */
      bool joining_signal_received = false;
      /* Extend the zigbee_default_signal_handler() function. */
      case ZB_BDB_SIGNAL_DEVICE_FIRST_START:
          ...
          joining_signal_received = true;
          break;
      case ZB_BDB_SIGNAL_DEVICE_REBOOT:
          ...
          joining_signal_received = true;
          break;
      case ZB_BDB_SIGNAL_STEERING:
          ...
          joining_signal_received = true;
          break;
      case ZB_ZDO_SIGNAL_LEAVE:
          if (status == RET_OK) {
              zb_zdo_signal_leave_params_t *leave_params = ZB_ZDO_SIGNAL_GET_PARAMS(sig_hndler, zb_zdo_signal_leave_params_t);
              LOG_INF("Network left (leave type: %d)", leave_params->leave_type);

              /* Set joining_signal_received to false so broken rejoin procedure can be detected correctly. */
              if (leave_params->leave_type == ZB_NWK_LEAVE_TYPE_REJOIN) {
                  joining_signal_received = false;
              }
          ...
          break;
      case ZB_NLME_STATUS_INDICATION: {
          zb_zdo_signal_nlme_status_indication_params_t *nlme_status_ind =
              ZB_ZDO_SIGNAL_GET_PARAMS(sig_hndler, zb_zdo_signal_nlme_status_indication_params_t);
          if (nlme_status_ind->nlme_status.status == ZB_NWK_COMMAND_STATUS_PARENT_LINK_FAILURE) {

              /* Check for broken rejoin procedure and restart the device to recover. */
              if (stack_initialised && !joining_signal_received) {
                  zb_reset(0);
              }
          }
          break;
      }

**KRKNWK-7723: OTA upgrade process restarting after client reset**

  .. toggle::

    After the reset of OTA Upgrade Client, the client will start the OTA upgrade process from the beginning instead of continuing the previous process.