/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once
/**
 * Tenlog D3 Hero pins. 
 */

#define REQUIRE_MEGA2560
#include "env_validate.h"

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Tenlog supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif
/**
 * Tenlog D3 Pro PLR pins. 
 */

#define BOARD_INFO_NAME      "Tenlog"
#define DEFAULT_MACHINE_NAME "Tenlog D3 Pro w/ Powerloss Resume"

//
// Limit Switches
//

#define X_MIN_PIN          3
#define X_MAX_PIN          2
#define Y_MIN_PIN          14
#define Y_MAX_PIN          -1
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#if ENABLED(BL_Touch)
  #undef Z_MAX_PIN
  #define Z_MAX_PIN          -1
  #define SERVO0_PIN         19
#else
  
#endif

//
// Steppers
//
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define E0_STEP_PIN        57  
#define E0_DIR_PIN         58  
#define E0_ENABLE_PIN      59  

#define E1_STEP_PIN        26
#define E1_DIR_PIN         28
#define E1_ENABLE_PIN      24

#define Z2_STEP_PIN        65
#define Z2_DIR_PIN         66
#define Z2_ENABLE_PIN      64

#define X2_STEP_PIN        36
#define X2_DIR_PIN         34
#define X2_ENABLE_PIN      30

//
// Temperature Sensors
//
#define TEMP_0_PIN          15   // Analog Input
#define TEMP_1_PIN          13   // Analog Input
#define TEMP_BED_PIN        14   // Analog Input

//
// Heaters
//
#define HEATER_0_PIN        11
#define HEATER_1_PIN        10
#define HEATER_BED_PIN      8

//
// Fans
//
#define FAN_PIN             9
#define FAN2_PIN            5

//
// PSU and Powerloss Recovery
//
#ifdef PSU_CONTROL
   #define PS_ON_PIN               40
   #define PSU_ACTIVE_STATE HIGH      // Set 'LOW' for ATX, 'HIGH' for X-Box
#endif

#ifdef POWER_LOSS_TRIGGER_BY_PIN
  #define POWER_OFF_PIN 32
  #define POWER_OFF_STATE HIGH
#endif

//
// Filament Runout Sensor
//

#ifdef FILAMENT_RUNOUT_SENSOR
  
  #define FIL_RUNOUT_PIN       15
  #define FIL_RUNOUT_STATE     LOW        // Pin state indicating that filament is NOT present.
#endif

//
// Misc. Functions
//
#define SD_DETECT_PIN      49
#define SDSS               53

#define LCD_PINS_RS                    -1
#define LCD_PINS_ENABLE                -1

#define LCD_PINS_D4                   -1
#define LCD_PINS_D5                   -1
#define LCD_PINS_D6                   -1
#define LCD_PINS_D7                   -1

//#define BEEPER_PIN                    23
//#define BEEPER_OFF LOW 
//#define BEEPER_ON HIGH

#define BTN_ENC                       -1
#define BTN_EN1                       -1
#define BTN_EN2                       -1
