/*
 * ZBOSS Zigbee 3.0
 *
 * Copyright (c) 2012-2022 DSR Corporation, Denver CO, USA.
 * www.dsr-zboss.com
 * www.dsr-corporation.com
 * All rights reserved.
 *
 *
 * Use in source and binary forms, redistribution in binary form only, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 2. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 3. This software, with or without modification, must only be used with a Nordic
 *    Semiconductor ASA integrated circuit.
 *
 * 4. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* PURPOSE: HA devices configuration
*/

#ifndef ZB_HA_DEVICE_CONFIG_H
#define ZB_HA_DEVICE_CONFIG_H 1

#if defined ZB_ENABLE_HA || defined DOXYGEN

/** @cond DOXYGEN_HA_SECTION */

/*! @defgroup ha_config_params HA Device types */
/*! @{
 */

/** @brief HA Device identifiers. */
enum zb_ha_standard_devs_e
{
  /*! General On/Off switch */
  ZB_HA_ON_OFF_SWITCH_DEVICE_ID       = 0x0000,
  /*! Level Control Switch  */
  ZB_HA_LEVEL_CONTROL_SWITCH_DEVICE_ID = 0x0001,
  /*! General On/Off output */
  ZB_HA_ON_OFF_OUTPUT_DEVICE_ID       = 0x0002,
  /*! Level Controllable Output */
  ZB_HA_LEVEL_CONTROLLABLE_OUTPUT_DEVICE_ID = 0x0003,
  /*! Scene Selector */
  ZB_HA_SCENE_SELECTOR_DEVICE_ID      = 0x0004,
  /*! Configuration Tool */
  ZB_HA_CONFIGURATION_TOOL_DEVICE_ID  = 0x0005,
  /*! Remote Control */
  ZB_HA_REMOTE_CONTROL_DEVICE_ID      = 0x0006,
  /*! Combined Interface */
  ZB_HA_COMBINED_INTERFACE_DEVICE_ID  = 0x0007,
  /*! Range Extender */
  ZB_HA_RANGE_EXTENDER_DEVICE_ID      = 0x0008,
  /*! Mains Power Outlet */
  ZB_HA_MAINS_POWER_OUTLET_DEVICE_ID  = 0x0009,
  /*! Door lock client */
  ZB_HA_DOOR_LOCK_DEVICE_ID           = 0x000A,
  /*! Door lock controller */
  ZB_HA_DOOR_LOCK_CONTROLLER_DEVICE_ID = 0x000B,
  /*! Simple Sensor device */
  ZB_HA_SIMPLE_SENSOR_DEVICE_ID       = 0x000C,
  /*! Consumption Awareness Device */
  ZB_HA_CONSUMPTION_AWARENESS_DEVICE_ID = 0x000D,
  /*! Home Gateway */
  ZB_HA_HOME_GATEWAY_DEVICE_ID        = 0x0050,
  /*! Smart plug */
  ZB_HA_SMART_PLUG_DEVICE_ID          = 0x0051,
  /*! White Goods */
  ZB_HA_WHITE_GOODS_DEVICE_ID         = 0x0052,
  /*! Meter Interface */
  ZB_HA_METER_INTERFACE_DEVICE_ID     = 0x0053,
  /* Lightning */
  /*! On/Off Light Device */
  ZB_HA_ON_OFF_LIGHT_DEVICE_ID        = 0x0100,
  /*! Dimmable Light Device */
  ZB_HA_DIMMABLE_LIGHT_DEVICE_ID      = 0x0101,
  /*! Color Dimmable Light Device */
  ZB_HA_COLOR_DIMMABLE_LIGHT_DEVICE_ID = 0x0102,
  /*! Dimmer Switch Device */
  ZB_HA_DIMMER_SWITCH_DEVICE_ID       = 0x0104,
  /*! Color Dimmer Switch Device */
  ZB_HA_COLOR_DIMMER_SWITCH_DEVICE_ID = 0x0105,
  /*! Shade */
  ZB_HA_SHADE_DEVICE_ID               = 0x0200,
  /*! Shade controller */
  ZB_HA_SHADE_CONTROLLER_DEVICE_ID    = 0x0201,
  /*! Window Covering client*/
  ZB_HA_WINDOW_COVERING_DEVICE_ID     = 0x0202,
  /*! Window Covering controller */
  ZB_HA_WINDOW_COVERING_CONTROLLER_DEVICE_ID = 0x0203,
  /* HVAC */
  /*! Heating/Cooling Unit device */
  ZB_HA_HEATING_COOLING_UNIT_DEVICE_ID = 0x0300,
  /*! Thermostat Device */
  ZB_HA_THERMOSTAT_DEVICE_ID          = 0x0301,
  /*! Temperature Sensor */
  ZB_HA_TEMPERATURE_SENSOR_DEVICE_ID  = 0x0302,
  /* IAS */
  /*! IAS Control and Indicating Equipment */
  ZB_HA_IAS_CONTROL_INDICATING_EQUIPMENT_ID = 0x0400,
  /*! IAS Ancillary Control Equipment */
  ZB_HA_IAS_ANCILLARY_CONTROL_EQUIPMENT_ID = 0x0401,
  /*! IAS Zone */
  ZB_HA_IAS_ZONE_ID                   = 0x0402,
  /*! IAS Warning Device */
  ZB_HA_IAS_WARNING_DEVICE_ID         = 0x0403,
  /*! Custom HA device for test */
  ZB_HA_TEST_DEVICE_ID                = 0xfff0,
  /*! Custom Tunnel device (should declared in private profile) */
  ZB_HA_CUSTOM_TUNNEL_DEVICE_ID       = 0xfff1,
  /*! Custom Attributes Device */
  ZB_HA_CUSTOM_ATTR_DEVICE_ID         = 0xfff2
};


/** @cond DOXYGEN_INTERNAL_DOC */
/* Define supported devices here */
#ifdef ZB_ALL_DEVICE_SUPPORT

#define ZB_HA_DEFINE_DEVICE_ON_OFF_SWITCH
#define ZB_HA_DEFINE_DEVICE_ON_OFF_OUTPUT
#define ZB_HA_DEFINE_DEVICE_DOOR_LOCK
#define ZB_HA_DEFINE_DEVICE_DOOR_LOCK_CONTROLLER
#define ZB_HA_DEFINE_DEVICE_SIMPLE_SENSOR
#define ZB_HA_DEFINE_DEVICE_COMBINED_INTERFACE
#define ZB_HA_DEFINE_DEVICE_SCENE_SELECTOR
#define ZB_HA_DEFINE_DEVICE_CONFIGURATION_TOOL
#define ZB_HA_DEFINE_DEVICE_MAINS_POWER_OUTLET
#define ZB_HA_DEFINE_DEVICE_RANGE_EXTENDER
#define ZB_HA_DEFINE_DEVICE_LEVEL_CONTROL_SWITCH
#define ZB_HA_DEFINE_DEVICE_LEVEL_CONTROLLABLE_OUTPUT
#define ZB_HA_DEFINE_DEVICE_WINDOW_COVERING
#define ZB_HA_DEFINE_DEVICE_WINDOW_COVERING_CONTROLLER
#define ZB_HA_DEFINE_DEVICE_SHADE
#define ZB_HA_DEFINE_DEVICE_SHADE_CONTROLLER
  /* HVAC */
#define ZB_HA_DEFINE_DEVICE_TEMPERATURE_SENSOR
/* IAS*/
#define ZB_HA_DEFINE_DEVICE_IAS_CONTROL_INDICATING_EQUIPMENT
#define ZB_HA_DEFINE_DEVICE_IAS_ANCILLARY_CONTROL_EQUIPMENT
#define ZB_HA_DEFINE_DEVICE_IAS_ZONE
#define ZB_HA_DEFINE_DEVICE_IAS_WARNING_DEVICE

#define ZB_HA_DEFINE_DEVICE_CUSTOM_ATTR
#define ZB_HA_DEFINE_DEVICE_DIMMABLE_LIGHT
#define ZB_HA_DEFINE_DEVICE_DIMMER_SWITCH

#define ZB_HA_DEFINE_DEVICE_SMART_PLUG
#define ZB_HA_DEFINE_DEVICE_THERMOSTAT

#define ZB_HA_DEFINE_DEVICE_TEST_DEVICE

/************** Custom Devices ******************/
/* Define device support for custom security sensor */
#define ZB_HA_DEFINE_DEVICE_CUSTOM_SECURITY_SENSOR
/* this device definition - for coordinator (CIE) role, need for test
 * only - remove it in release build */
#define ZB_HA_DEFINE_DEVICE_CUSTOM_SECURITY_CONTROL
/* Define device support for Low Cost Gateway */
#define ZB_HA_DEFINE_DEVICE_GATEWAY
#define ZB_HA_DEFINE_DEVICE_CUSTOM_DIMMABLE_LIGHT
/* Linky */
#define ZB_HA_DEFINE_DEVICE_ERL_INTERFACE_DEVICE
#define ZB_HA_DEFINE_DEVICE_ERL_GW



#define ZB_ZCL_SUPPORT_CLUSTER_DRLC 1
#define ZB_ZCL_SUPPORT_CLUSTER_PRICE 1
#define ZB_ZCL_SUPPORT_CLUSTER_TUNNELING 1
#define ZB_ZCL_SUPPORT_CLUSTER_MESSAGING 1

#define ZB_ZCL_SUPPORT_CLUSTER_METER_IDENTIFICATION 1

/* Define optional common clusters. These clusters are common to all devices
 * and expected to be part of the build if ZB_ALL_DEVICE_SUPPORT is declared.
 * For example, application 'multi_ep' expects "Alarms" cluster to be present.
 *
 * Clusters with reporting capability are omitted since common part implies
 * client role which receives attribute reports. It is not necessary to enable
 * ZB_ZCL_SUPPORT_* during stack build. It will be enough for applications to
 * define corresponding ZB_ZCL_SUPPORT_* during application's build because
 * only headers should be included, no *.c files.
 *
 * Also, common manufacturer-specific clusters are ignored here.
 */
#define ZB_ZCL_SUPPORT_CLUSTER_POWER_CONFIG           1
#define ZB_ZCL_SUPPORT_CLUSTER_ALARMS                 1
#define ZB_ZCL_SUPPORT_CLUSTER_ELECTRICAL_MEASUREMENT 1
#define ZB_ZCL_SUPPORT_CLUSTER_POLL_CONTROL           1

/* Define clusters which are not used by any device but expected to be
 * supported in ZBOSS stack when ZB_ALL_DEVICE_SUPPORT is defined.
 *
 * The main intention of ZB_ALL_DEVICE_SUPPORT define is to compile in ZBOSS
 * stack as much HA-related functionality as possible so declaring support for
 * clusters not being used by any device but used by some sample seems to be
 * fine.
 */
#define ZB_ZCL_SUPPORT_CLUSTER_DEHUMIDIFICATION_CONTROL 1
#define ZB_ZCL_SUPPORT_CLUSTER_OCCUPANCY_SENSING        1

#endif /* ZB_ALL_DEVICE_SUPPORT */

//#define ZB_HA_DEFINE_DEVICE_SMART_PLUG

/*********************** HA devices to cluster configuration **********************/

#ifdef ZB_HA_DEFINE_DEVICE_ON_OFF_SWITCH
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF_SWITCH_CONFIG 1

#endif /* ZB_HA_DEFINE_DEVICE_ON_OFF_OUTPUT */


#ifdef ZB_HA_DEFINE_DEVICE_ON_OFF_OUTPUT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1

#endif /* ZB_HA_DEFINE_DEVICE_ON_OFF_OUTPUT */

#ifdef ZB_HA_DEFINE_DEVICE_BASIC_LIGHT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#endif /* ZB_HA_DEFINE_DEVICE_BASIC_LIGHT */


#ifdef ZB_HA_DEFINE_DEVICE_DOOR_LOCK
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC      1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES     1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS     1
#define ZB_ZCL_SUPPORT_CLUSTER_DOOR_LOCK  1

#endif /* ZB_HA_DEFINE_DEVICE_DOOR_LOCK */


#ifdef ZB_HA_DEFINE_DEVICE_DOOR_LOCK_CONTROLLER
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC      1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES     1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS     1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY   1
#define ZB_ZCL_SUPPORT_CLUSTER_DOOR_LOCK  1

#endif /* ZB_HA_DEFINE_DEVICE_DOOR_LOCK_CONTROLLER */


#ifdef ZB_HA_DEFINE_DEVICE_SIMPLE_SENSOR
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC      1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES     1
#define ZB_ZCL_SUPPORT_CLUSTER_BINARY_INPUT 1
#endif /* ZB_HA_DEFINE_DEVICE_SIMPLE_SENSOR */


#ifdef ZB_HA_DEFINE_DEVICE_COMBINED_INTERFACE
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF_SWITCH_CONFIG 1
#endif /* ZB_HA_DEFINE_DEVICE_COMBINED_INTERFACE */


#ifdef ZB_HA_DEFINE_DEVICE_SCENE_SELECTOR
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#endif /* ZB_HA_DEFINE_DEVICE_SCENE_SELECTOR */


#ifdef ZB_HA_DEFINE_DEVICE_CONFIGURATION_TOOL
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#endif /* ZB_HA_DEFINE_DEVICE_CONFIGURATION_TOOL */


#ifdef ZB_HA_DEFINE_DEVICE_MAINS_POWER_OUTLET
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1

#endif /* ZB_HA_DEFINE_DEVICE_MAINS_POWER_OUTLET */


#ifdef ZB_HA_DEFINE_DEVICE_RANGE_EXTENDER
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#endif /* ZB_HA_DEFINE_DEVICE_RANGE_EXTENDER */


#ifdef ZB_HA_DEFINE_DEVICE_LEVEL_CONTROL_SWITCH
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL 1
#endif /* ZB_HA_DEFINE_DEVICE_LEVEL_CONTROL_SWITCH */


#ifdef ZB_HA_DEFINE_DEVICE_LEVEL_CONTROLLABLE_OUTPUT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL 1

#endif /* ZB_HA_DEFINE_DEVICE_LEVEL_CONTROLLABLE_OUTPUT */


#ifdef ZB_HA_DEFINE_DEVICE_WINDOW_COVERING
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_WINDOW_COVERING   1

#endif /* ZB_HA_DEFINE_DEVICE_WINDOW_COVERING */

#ifdef ZB_HA_DEFINE_DEVICE_CUSTOM_ATTR
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_WINDOW_COVERING   1
#define ZB_ZCL_SUPPORT_CLUSTER_CUSTOM_ATTR 1
#endif /* ZB_HA_DEFINE_DEVICE_CUSTOM_ATTR */

#ifdef ZB_HA_DEFINE_DEVICE_DIMMABLE_LIGHT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL 1
#endif /* ZB_HA_DEFINE_DEVICE_DIMMABLE_LIGHT */

#ifdef ZB_HA_DEFINE_DEVICE_DIMMABLE_LIGHT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL 1
#endif /* ZB_HA_DEFINE_DEVICE_DIMMER_SWITCH */

#ifdef ZB_HA_DEFINE_DEVICE_WINDOW_COVERING_CONTROLLER
#define ZB_HA_DEFINE_DEVICE_WINDOW_COVERING_CONTROLLER
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_WINDOW_COVERING   1
#endif /* ZB_HA_DEFINE_DEVICE_WINDOW_COVERING_CONTROLLER */

#ifdef ZB_HA_DEFINE_DEVICE_SHADE
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_SHADE_CONFIG   1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL   1
#endif /* ZB_HA_DEFINE_DEVICE_SHADE */

#ifdef ZB_HA_DEFINE_DEVICE_SHADE_CONTROLLER
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL   1
#endif /* ZB_HA_DEFINE_DEVICE_SHADE_CONTROLLER */

  /* HVAC */

#ifdef ZB_HA_DEFINE_DEVICE_TEMPERATURE_SENSOR
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC      1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY   1
#define ZB_ZCL_SUPPORT_CLUSTER_TEMP_MEASUREMENT 1
#endif /* ZB_HA_DEFINE_DEVICE_TEMPERATURE_SENSOR */

/* IAS*/

#ifdef ZB_HA_DEFINE_DEVICE_IAS_CONTROL_INDICATING_EQUIPMENT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC        1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY     1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ACE      1
//#define ZB_ZCL_SUPPORT_CLUSTER_IAS_WD       1
//#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE     1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES       1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS       1
#endif /* ZB_HA_DEFINE_DEVICE_IAS_CONTROL_INDICATING_EQUIPMENT */

#ifdef ZB_HA_DEFINE_DEVICE_IAS_ANCILLARY_CONTROL_EQUIPMENT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC        1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY     1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE     1
//#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ACE      1
#endif /* ZB_HA_DEFINE_DEVICE_IAS_ANCILLARY_CONTROL_EQUIPMENT */

#ifdef ZB_HA_DEFINE_DEVICE_IAS_ZONE
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC        1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY     1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE     1
#endif /* ZB_HA_DEFINE_DEVICE_IAS_ZONE */

#ifdef ZB_HA_DEFINE_DEVICE_IAS_WARNING_DEVICE
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC        1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY     1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_WD       1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE     1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES       1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS       1
#endif /* ZB_HA_DEFINE_DEVICE_IAS_WARNING_DEVICE */

#ifdef ZB_HA_DEFINE_DEVICE_CUSTOM_SECURITY_SENSOR
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC        1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY     1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE     1
#define ZB_ZCL_SUPPORT_CLUSTER_TEMP_MEASUREMENT 1

#define ZB_ZCL_SUPPORT_CLUSTER_POWER_CONFIG 1
#define ZB_ZCL_SUPPORT_CLUSTER_POLL_CONTROL 1
#define ZB_ZCL_SUPPORT_CLUSTER_DIAGNOSTICS  1
#define ZB_ZCL_SUPPORT_CLUSTER_OTA_UPGRADE  1
#define ZB_ZCL_SUPPORT_CLUSTER_ILLUMINANCE_MEASUREMENT  1
#define ZB_ZCL_SUPPORT_CLUSTER_REL_HUMIDITY_MEASUREMENT 1
#endif /* ZB_HA_DEFINE_DEVICE_CUSTOM_SECURITY_SENSOR  */

#ifdef ZB_HA_DEFINE_DEVICE_CUSTOM_SECURITY_CONTROL
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC        1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY     1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE     1
//#define ZB_ZCL_SUPPORT_CLUSTER_POLL_CONTROL 1
#endif /* ZB_HA_DEFINE_DEVICE_CUSTOM_SECURITY_CONTROL */

#ifdef ZB_HA_DEFINE_DEVICE_THERMOSTAT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC                1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY             1
#define ZB_ZCL_SUPPORT_CLUSTER_THERMOSTAT           1
#define ZB_ZCL_SUPPORT_CLUSTER_THERMOSTAT_UI_CONFIG 1
#define ZB_ZCL_SUPPORT_CLUSTER_FAN_CONTROL  1
#define ZB_ZCL_SUPPORT_CLUSTER_ELECTRICAL_MEASUREMENT 1
#endif /* ZB_HA_DEFINE_DEVICE_THERMOSTAT */

#ifdef ZB_HA_DEFINE_DEVICE_GATEWAY
/*
 * Gateway supports many clusters, but in the client role and in general it's
 * not necessary to define their support with ZB_ZCL_SUPPORT_CLUSTER_xxx.
 * Such defines are necessary only for clusters in the server role.
 * The only exception is poll control cluster for now.
 */
#define ZB_ZCL_SUPPORT_CLUSTER_POLL_CONTROL              1
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC                     1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY                  1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ZONE                  1
#define ZB_ZCL_SUPPORT_CLUSTER_TIME                      1
#define ZB_ZCL_SUPPORT_CLUSTER_DIAGNOSTICS               1
#define ZB_ZCL_SUPPORT_CLUSTER_OTA_UPGRADE               1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS_CLIENT             1
#define ZB_ZCL_SUPPORT_CLUSTER_EN50523_APPLIANCE_EVENTS_AND_ALERTS 1
#define ZB_ZCL_SUPPORT_CLUSTER_POWER_CONFIG              1
#define ZB_ZCL_SUPPORT_CLUSTER_REL_HUMIDITY_MEASUREMENT  1
#define ZB_ZCL_SUPPORT_CLUSTER_TEMP_MEASUREMENT          1
#define ZB_ZCL_SUPPORT_CLUSTER_PRESSURE_MEASUREMENT      1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF                    1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES                    1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS                    1
#define ZB_ZCL_SUPPORT_CLUSTER_METERING                  1
#define ZB_ZCL_SUPPORT_CLUSTER_IAS_ACE                   1
/*
 * Gateway uses EZ mode only for Gemtek smartplug, which is
 * currently excluded from build.
 */
/* #define ZB_HA_SUPPORT_EZ_MODE                         1 */
#endif /* ZB_HA_DEFINE_DEVICE_GATEWAY */

/* Custom device should not be declared as a part of HA, keep it
 * here foe simplicity */
#ifdef ZB_PROFILE_DEFINE_DEVICE_CUSTOM_TUNNEL
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC                1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY             1
#define ZB_ZCL_SUPPORT_CLUSTER_TUNNEL               1
#endif

#ifdef ZB_HA_DEFINE_DEVICE_SMART_PLUG
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC                1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY             1
#define ZB_ZCL_SUPPORT_CLUSTER_METERING             1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF               1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS               1
/* FIXME: Are Scenes really needed? */
/* #define ZB_ZCL_SUPPORT_CLUSTER_SCENES               1 */
#define ZB_ZCL_SUPPORT_CLUSTER_DIAGNOSTICS          1
#define ZB_ZCL_SUPPORT_CLUSTER_OTA_UPGRADE          1
#endif /* ZB_HA_DEFINE_DEVICE_SMART_PLUG */


#ifdef ZB_HA_DEFINE_DEVICE_CUSTOM_DIMMABLE_LIGHT
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC    1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#define ZB_ZCL_SUPPORT_CLUSTER_SCENES   1
#define ZB_ZCL_SUPPORT_CLUSTER_GROUPS   1
#define ZB_ZCL_SUPPORT_CLUSTER_ON_OFF   1
#define ZB_ZCL_SUPPORT_CLUSTER_LEVEL_CONTROL 1
#define ZB_ZCL_SUPPORT_CLUSTER_COLOR_CONTROL 1
#endif /* ZB_HA_DEFINE_DEVICE_CUSTOM_DIMMABLE_LIGHT */

#if defined  ZB_HA_DEFINE_DEVICE_ERL_INTERFACE_DEVICE || defined ZB_HA_DEFINE_DEVICE_ERL_GW
#define ZB_ZCL_SUPPORT_CLUSTER_BASIC                  1
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY               1
#define ZB_ZCL_SUPPORT_CLUSTER_TIME                   1
#define ZB_ZCL_SUPPORT_CLUSTER_METER_IDENTIFICATION   1
#define ZB_ZCL_SUPPORT_CLUSTER_ELECTRICAL_MEASUREMENT 1
#define ZB_ZCL_SUPPORT_CLUSTER_DIAGNOSTICS            1
#define ZB_ZCL_SUPPORT_CLUSTER_METERING               1
#define ZB_ZCL_SUPPORT_CLUSTER_MESSAGING              1
#define ZB_ZCL_SUPPORT_CLUSTER_DAILY_SCHEDULE         1
#endif /* defined  ZB_HA_DEFINE_DEVICE_ERL_INTERFACE_DEVICE || defined ZB_HA_DEFINE_DEVICE_ERL_GW */

/* BDB uses identify */
#if defined ZB_BDB_MODE && !defined ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY
#define ZB_ZCL_SUPPORT_CLUSTER_IDENTIFY 1
#endif

/** @endcond */

/** @} */ /* ha_api */

/** @endcond */ /* DOXYGEN_HA_SECTION */

#ifdef ZB_ZCL_SUPPORT_CLUSTER_DIAGNOSTICS
/* need to define it here because that .h file can be included after zb_config.h */
#ifndef ZB_MAC_DIAGNOSTICS
#define ZB_MAC_DIAGNOSTICS
#endif
#ifndef ZDO_DIAGNOSTICS
#define ZDO_DIAGNOSTICS
#endif
#endif

#endif /* ZB_ENABLE_HA */

#if defined ZB_ZCL_SUPPORT_CLUSTER_DIAGNOSTICS && ! defined ZDO_DIAGNOSTICS
#error Define ZDO_DIAGNOSTICS in vendor file if you need Diagnostic cluster!
#endif

#endif /* ZB_HA_DEVICE_CONFIG_H */
