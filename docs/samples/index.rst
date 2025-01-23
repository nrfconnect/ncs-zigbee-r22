.. _zigbee_samples:

Samples
#######

The |addon| for the |NCS| provides the following samples showcasing the Zigbee R23 protocol.
All samples are placed in the :file:`samples` directory in the Zigbee repository.
You can build the samples for various boards and configure them for different usage scenarios.

.. include:: /includes/zigbee_deprecation.txt

In addition to their basic functionalities, you can expand the samples with variants and extensions.
The following table lists variants and extensions available for each Zigbee sample:

.. list-table::
    :widths: auto
    :header-rows: 1

    * - Variant or extension
      - Light bulb
      - Light switch
      - Network coordinator
      - NCP
      - Shell
      - Template
    * - FEM support
      - ✔
      - ✔
      - ✔
      - ✔
      - ✔
      - ✔
    * - Sleepy End Device behavior
      - :ref:`*** <zigbee_ug_sed>`
      - ✔
      -
      -
      - :ref:`** <zigbee_ug_sed>`
      - :ref:`** <zigbee_ug_sed>`
    * - Multiprotocol Bluetooth LE
      - `*** <Multiprotocol support_>`_
      - ✔
      - `*** <Multiprotocol support_>`_
      -
      - `*** <Multiprotocol support_>`_
      - `*** <Multiprotocol support_>`_
    * - Zigbee FOTA
      - :ref:`** <ug_zigbee_configuring_components_ota>`
      - ✔
      - :ref:`** <ug_zigbee_configuring_components_ota>`
      -
      - :ref:`** <ug_zigbee_configuring_components_ota>`
      - :ref:`** <ug_zigbee_configuring_components_ota>`
    * - Endpoint logger
      - :ref:`** <ug_zigbee_configuring_components_logger_ep>`
      - :ref:`** <ug_zigbee_configuring_components_logger_ep>`
      - :ref:`** <ug_zigbee_configuring_components_logger_ep>`
      -
      - ✔
      - :ref:`** <ug_zigbee_configuring_components_logger_ep>`
    * - ZCL scene helper
      - ✔
      - :ref:`*** <ug_zigbee_configuring_components_scene_helper>`
      - :ref:`*** <ug_zigbee_configuring_components_scene_helper>`
      -
      - :ref:`*** <ug_zigbee_configuring_components_scene_helper>`
      - :ref:`*** <ug_zigbee_configuring_components_scene_helper>`

Read the table symbols in the following manner:

* ``✔`` - Using this variant or extension either requires changes in Kconfig through the provided overlay file or the variant or extension is already enabled by default in the sample.
  See the sample documentation for detailed configuration steps for these variants and extensions.
* ``**`` - Implementing this variant or extension requires minimal changes in the sample source code and Kconfig options.
  Click the link for implementation details.
* ``***`` - Implementing this variant or extension requires several changes in both selected Kconfig options and source files, and may require adding new source files to the sample (for example, command implementation).
  Click the link for implementation details.
* No symbol - The variant or extension is not available for the given sample.

Some variants and extensions might also require additional hardware and software, such as mobile applications for testing purposes.

General information about samples in the |NCS|
   * If you are working with embedded devices, it is a good practice to first test your setup by programming an unchanged sample to your development kit.
   * Some samples in the nRF Connect SDK are currently not designed to work out-of-tree.
     You may need to manually configure your sample to work correctly in the nRF Connect for VS Code extension.
   * All samples in the |NCS| use `Fatal error handler`_ library and are configured to perform a system reset if a fatal error occurs.
     This behavior is different from how fatal errors are handled in the Zephyr samples.
     You can change the default behavior by updating the configuration option ``CONFIG_RESET_ON_FATAL_ERROR``.
   * All samples in the |NCS| are tested and verified in accordance with their `maturity level <Software maturity levels_>_`.

.. toctree::
   :maxdepth: 1
   :caption: Subpages
   :glob:

   */README
