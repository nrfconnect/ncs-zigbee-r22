.. _release_notes:

Release notes
#############

.. contents::
   :local:
   :depth: 2

All the notable changes to the |addon| for the |NCS| are listed here.
See also the `Release notes for the nRF Connect SDK`_ and the :ref:`zboss_changelog`

.. include:: /includes/zigbee_r22_note.txt

The |addon| v\ |addon_version| is compatible with |NCS| v\ |ncs_version| and uses the ZBOSS stack version |zboss_version|.
For a full list of |addon| releases, related |NCS| and ZBOSS stack and NCP host package versions, view the following table:

+-------------------+------------------+-----------------------+---------------------+
| |addon| version   | |NCS| version    | ZBOSS stack version   | NCP host version    |
+===================+==================+=======================+=====================+
| 1.0.1             | 2.9.0            | 3.11.8.0              | 2.2.7               | 
+-------------------+------------------+-----------------------+---------------------+
| 1.0.0             | 2.9.0            | 3.11.7.0              | 2.2.6               | 
+-------------------+------------------+-----------------------+---------------------+

.. _zigbee_release:

|addon| v1.0.1 - 15/07/2025
***************************

This is a production-ready release of |addon|.
 
* Updated:

  * Fixed security vulnerability.
  * Fixed build issues when FACTORY_RESET is disabled.
  * Improved transmission handling in scenarios where acknowledgments are not received.
  * Adjusted the NVRAM partition size to optimize performance on the nRF52833 platform.

|addon| v1.0.0 - 07/03/2025
***************************
This is a production-ready release of |addon|.
 
* Updated:
 
  * Fixed the logging of negative temperatures in the :ref:`Thingy:53: Zigbee weather station <zigbee_weather_station_app_include>` application.
  * Fixed an issue where an assert occurs on an empty record during NVRAM migration after upgrading to ZBOSS from NCS 2.7.0 or higher.
  * Fixed a fatal error after changing the ``ZB_DEV_REJOIN_TIMEOUT_MS`` setting.
  * Fixed the process for setting the endpoint field in the ZCL device callback.
