.. _zigbee_setup:

Requirements and setup
######################

This page outlines the requirements that you need to meet before you start working with the production ready release of |addon| and Zigbee R22 protocol.

Hardware requirements
*********************

The |addon| supports the nRF52840, nRF52833 and nRF5340 SoCs.

For the :ref:`zigbee_quickstart`, you need three development kits of the following types:

.. include:: /includes/device_table_single.txt

You can mix different development kits.

Software requirements
*********************

For libraries and code for |addon|, see the `ncs-zigbee-r22 repository <Zigbee R22 add-on_>`_.

To work with the |addon|, you need to install the |NCS|, including all its prerequisites and the |NCS| toolchain.
Follow the `Installing the nRF Connect SDK`_ instructions, with the following exception:

.. tabs::

   .. group-tab:: |nRFVSC|

      In the **Get the nRF Connect SDK code** part of the install instructions:

      In Step 4, select :guilabel:`Browse nRF Connect SDK Add-on Index` instead of selecting the SDK version, then select :guilabel:`Zigbee`, and select v\ |addon_version| of the |addon|, which also installs |NCS| v\ |ncs_version|.

   .. group-tab:: command line

      In the **Get the nRF Connect SDK code** part of the install instructions:

      In Step 4, use the following command to initialize west with |addon| v\ |addon_version|, which also initializes |NCS| v\ |ncs_version|:

      .. code-block:: console

         west init -m "http://github.com/nrfconnect/ncs-zigbee-r22" --mr main


To create an application, use :ref:`zigbee_template_sample` sample as a starting point.