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

// #ifdef POWER_LOSS_RECOVERY
//    #define POWER_LOSS_PIN          32
//    #define POWER_LOSS_STATE        HIGH
// #endif


#define POWER_OFF_PIN 32
#define POWER_OFF_STATE HIGH

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

#define LCD_PINS_RS                    6
#define LCD_PINS_ENABLE                7

#define LCD_PINS_D4                   23
#define LCD_PINS_D5                   25
#define LCD_PINS_D6                   27
#define LCD_PINS_D7                   29
#define BEEPER_PIN                    37
#define BTN_ENC                       35
#define BTN_EN1                       31
#define BTN_EN2                       33