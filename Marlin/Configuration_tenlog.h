//Helper functions
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define SHORT_BUILD_VERSION "2.0.9.2 for Luxuri 0.9.x"

//Common
#define NUM_Z_STEPPER_DRIVERS 2   // (1-4) Z options change based on how many
#define DUAL_X_CARRIAGE
#define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE  
#define USE_ZMAX_PLUG
#define MIN_SOFTWARE_ENDSTOPS
#define MIN_SOFTWARE_ENDSTOP_X
#define MIN_SOFTWARE_ENDSTOP_Y
#define MIN_SOFTWARE_ENDSTOP_Z
#define Z_MIN_ENDSTOP_INVERTING true
#define Y_MIN_ENDSTOP_INVERTING false  
#define Z_MIN_PROBE_ENDSTOP_INVERTING false
#define X2_HOME_DIR    1       // Set to 1. The second X-carriage always homes to the maximum endstop position
#define Z_MIN_POS 0
#define TEMP_SENSOR_BED 1
#define BED_MAXTEMP      100
#define THERMAL_PROTECTION_BED_PERIOD        20 // Seconds
#define WATCH_BED_TEMP_PERIOD                60 // Seconds
#define SAFETY_Z_UNPARK 4.00 // 26/04/2021 Murdock avoid bed clips (Height to raise. Set to 0 for disable).
#define SAFETY_Y_UNPARK 15.00 // 26/04/2021 Murdock avoid bed clips (Distance to move on Y axis for avoid bed clips).
#define BABYSTEP_HOME_Z_OFFSET
#define BABYSTEP_HOTEND_Z_OFFSET
#define TOOLCHANGE_NO_RETURN
#define HOST_ACTION_COMMANDS
#define HAS_STATUS_MESSAGE 1
#define LIN_ADVANCEsirius xm
#define LIN_ADVANCE_K 0
#define verS3 ""
#define QUICK_HOME 

//Base Machine
#if ENABLED(MachineTLD3P)
  #define verS1 "Tenlog TL-D3 Pro"
  #define BED_CENTER_AT_155_155
  #define LUX_MEASURED_X_BED_SIZE 310
  #define LUX_MEASURED_Y_BED_SIZE 310
  #define DEFAULT_DUPLICATION_X_OFFSET 155
  #define Z_MAX_POS 350
#elif ENABLED(MachineTLD5)
  #define verS1 "Tenlog TL-D5"
  #define LUX_MEASURED_X_BED_SIZE 510
  #define LUX_MEASURED_Y_BED_SIZE 510
  #define DEFAULT_DUPLICATION_X_OFFSET 250
  #define Z_MAX_POS 350
#endif

//Board
#if ENABLED(OCTOPUS)
  #undef verS3
  #define verS3 "OCTOPUS"
  #define POWER_OFF_STATE HIGH // This is not functional but is needed due to MarlinCore.h being modified for the TL-D3 Power Switch
#endif

//Screen
#if ENABLED(LCDmini12864) || ENABLED(LCD_BTT_TFT)
  #define AUTO_REPORT_POSITION
  #define M115_GEOMETRY_REPORT
  #define M114_DETAIL  
  #define PROBE_OFFSET_WIZARD
  #define PROBE_OFFSET_WIZARD_START_Z 0
  #define PROBE_OFFSET_WIZARD_XY_POS { X_CENTER, Y_CENTER }
  #define LCD_INFO_MENU
  #define STATUS_MESSAGE_SCROLLING
  #define LCD_SHOW_E_TOTAL
  #define SHOW_REMAINING_TIME 
  #define PRINT_PROGRESS_SHOW_DECIMALS
  #define BOOT_MARLIN_LOGO_ANIMATED
  #define MARLIN_BRICKOUT
  #define MARLIN_INVADERS
  #define MARLIN_SNAKE
  #define SOUND_MENU_ITEM
  #define AUTO_REPORT_POSITION
  #define M115_GEOMETRY_REPORT
  #define M114_DETAIL  
  #define SERIAL_FLOAT_PRECISION 4
  #define FILAMENT_LOAD_UNLOAD_GCODES
  #define PARK_HEAD_ON_PAUSE 
#endif
#if ENABLED(LCDmini12864)
  #define RGB_LED
  #define NEOPIXEL_LED
  #define LED_CONTROL_MENU
  #define FYSETC_MINI_12864_2_1
#endif
#if ENABLED(LCD_BTT_TFT)
  #define SDCARD_CONNECTION            ONBOARD
  #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
#endif

//Drivers
#if ENABLED(DriverA4988)
  #define verS2 "A4988"
  #define DriverType A4988
  #define INVERT_X_DIR true
  #define INVERT_Y_DIR false
  #define INVERT_Z_DIR true
  #define INVERT_E0_DIR false
  #if ENABLED(TitanExtruder)
    #define INVERT_E1_DIR false
  #else
    #define INVERT_E1_DIR true
	#endif
#elif ENABLED(Driver2208)
  #define verS2 "2208"
  #define DriverType TMC2208_STANDALONE
	#define INVERT_X_DIR false
  #define INVERT_Y_DIR true
	#define INVERT_Z_DIR false  
	#define INVERT_E0_DIR true
	#define INVERT_E1_DIR false
  #undef LIN_ADVANCE 
  #undef LIN_ADVANCE_K
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
#elif ENABLED(Driver2208_UART)
  #define verS2 "2208_UART"
  #define DriverType TMC2208
	#define INVERT_X_DIR falsesirius xm
  #define INVERT_Y_DIR true
	#define INVERT_Z_DIR false  
	#define INVERT_E0_DIR false
	#define INVERT_E1_DIR true
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  #define TMC_DEBUG
  #define MONITOR_DRIVER_STATUS
#elif ENABLED(Driver2209)
  #define verS2 "2209"
  #define DriverType TMC2209_STANDALONE
	#define INVERT_X_DIR false
  #define INVERT_Y_DIR true
	#define INVERT_Z_DIR false
	#define INVERT_E0_DIR true
  #if ENABLED(TitanExtruder)
    #define INVERT_E1_DIR true
  #else
    #define INVERT_E1_DIR false
	#endif
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
#elif ENABLED(Driver2209BTT)
  #define verS2 "2209BTT"
  #define DriverType TMC2209
  #define INVERT_Z_DIR false
  #define INVERT_Z2_VS_Z_DIR false
  #define INVERT_X2_VS_X_DIR false
  #define INVERT_E0_DIR true
  #define INVERT_E1_DIR true
  #define X_MIN_ENDSTOP_INVERTING true
  #define Z_MAX_ENDSTOP_INVERTING true
  #define X_MAX_ENDSTOP_INVERTING true
  #define TMC_DEBUG
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  #if ENABLED(OCTOPUS)
    #define STARTUP_COMMANDS "M569 S0 I1 T1 E \n M569 S0 E \n M412 S0" // Disable stealthchop for extruders
    #define INVERT_X_DIR false
    #define INVERT_Y_DIR true
  #endif
#endif
#if ENABLED(Driver2209BTT)
  #define X_CURRENT       580 
  #define X2_CURRENT       580 
  #define Y_CURRENT       580 
  #define Y2_CURRENT       580 
  #define Z_CURRENT       580 
  #define Z2_CURRENT       580 
  #define E0_CURRENT       580 
  #define E1_CURRENT       580 
#else
  #define X_CURRENT       800 
  #define X2_CURRENT       800 
  #define Y_CURRENT       800 
  #define Y2_CURRENT       800 
  #define Z_CURRENT       800 
  #define Z2_CURRENT       800 
  #define E0_CURRENT       800 
  #define E1_CURRENT       800 
#endif

//Extruder Type
#if ENABLED(TitanExtruder)
  #define LUX_EXTRUDER_X_SPACING_RIGHT 3 //Change to nozzle to right side measurement
  #define LUX_EXTRUDER_X_SPACING_LEFT 3 
  #define LUX_EXTRUDER_Y_OFFSET 8
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 382.17, 382.17 }
  #define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }
#elif ENABLED(BMGExtruderV2)
  #undef X2_MIN_POS
  #undef X_MAX_POS
  #undef X2_MAX_POS
  #undef DEFAULT_AXIS_STEPS_PER_UNIT
  #undef Y_MIN_POSsirius xm
  #undef X_MIN_POS 
  #undef X1_MIN_POS
  #define X_MIN_POS   -53
  #define X2_MIN_POS  5
  #define X_MAX_POS   300
  #define X2_MAX_POS  362
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 413, 413 }
  #define HOMING_FEEDRATE_MM_M { (70*60), (70*60), (8*60) }
#elif ENABLED(BMGExtruderV3)
  #undef X_MIN_POS
  #undef X2_MIN_POS
  #undef X_MAX_POS
  #undef X2_MAX_POS
  #undef DEFAULT_AXIS_STEPS_PER_UNIT
  #undef NOZZLE_PARK_POINT
  #define X_MIN_POS   -53
  #define X2_MIN_POS  5
  #define X_MAX_POS   300
  #define X2_MAX_POS  362
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 413, 413 }
  #define HOTEND_OFFSET_X { 0.0, (X2_MAX_POS) } // (mm) relative X-offset for each nozzle
  //#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) relative Y-offset for each nozzle
  #define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) relative Z-offset for each nozzle
  #define HOMING_FEEDRATE_MM_M { (70*60), (70*60), (8*60) }
#else //Default Extruder
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 92.6, 92.6 }
  #define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }
#endif

//Endstop Type
#if ENABLED(OpticalY)
  #undef  Y_MIN_ENDSTOP_INVERTING
  #define Y_MIN_ENDSTOP_INVERTING true
  #define LUX_ENDSTOP_Y_OFFSET 4
#else //Manual switch
  #define LUX_ENDSTOP_Y_OFFSET 0
#endif

//Hotend
#if ENABLED(AllMetalHotend)
  #define HEATER_0_MAXTEMP 310
  #define HEATER_1_MAXTEMP 310
#else
  #define HEATER_0_MAXTEMP 275
  #define HEATER_1_MAXTEMP 275
#endif

//Bed
#if ENABLED(ACBed)
  #undef THERMAL_PROTECTION_BED_PERIOD
  #undef WATCH_BED_TEMP_PERIOD
  #undef TEMP_SENSOR_BED
  #undef BED_MAXTEMP
  #define BED_MAXTEMP 145
  #define THERMAL_PROTECTION_BED_PERIOD 10
  #define WATCH_BED_TEMP_PERIOD 20
  #define TEMP_SENSOR_BED 11
#endif


//Power Loss Recovery
#if ENABLED(POWER_LOSS_TRIGGER_BY_PIN)
  #undef verS3
  #define verS3 "PLR"
#endif

#if ENABLED(ACBed)
  #undef THERMAL_PROTECTION_BED_PERIOD
  #undef WATCH_BED_TEMP_PERIOD
  #undef TEMP_SENSOR_BED
  #undef BED_MAXTEMP
  #define BED_MAXTEMP 145
  #define THERMAL_PROTECTION_BED_PERIOD 10
  #define WATCH_BED_TEMP_PERIOD 20
  #define TEMP_SENSOR_BED 11
#endif

//Probe
#if ENABLED(BL_Touch)
  #ifndef OCTOPUS
    #undef Z_MIN_ENDSTOP_INVERTING
    #define Z_MIN_ENDSTOP_INVERTING false
  #endif
  #define HAS_PROBE
  #define BLTOUCH
  #if ENABLED(BMGExtruderV2)
    #define NOZZLE_TO_PROBE_OFFSET { -1.75, -42, -1.125 }
    #define Z_HOMING_HEIGHT  4 
    #define Z_AFTER_HOMING  2
  #elif ENABLED(BMGExtruderV3)
    #define NOZZLE_TO_PROBE_OFFSET { -1.75, -42, -2.3837 }
    #define Z_HOMING_HEIGHT  4 
    #define Z_AFTER_HOMING  2
  #else
    #define NOZZLE_TO_PROBE_OFFSET { 7, -47, -2.5 }
  #endif
  #define AUTO_BED_LEVELING_UBL
  #define PROBING_MARGIN 15
  #define MESH_INSET 15 
  #define GRID_MAX_POINTS_X 15
  #define G26_MESH_VALIDATION
  #define Z_CLEARANCE_BETWEEN_PROBES  3 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     2 // Z Clearance between multiple probes
  //BLTouch Options. For details read BLTouch section in Configuration_adv.h
  //Settings for BLTOUCH Classic 1.2, 1.3 or BLTouch Smart 1.0, 2.0, 2.2, 3.0, 3.1, and most clones
  #define BLTOUCH_DELAY 200 // Default: 375, min 200
  #define BLTOUCH_FORCE_SW_MODE // Default: Off
  //Settings for BLTouch Smart 3.0 and 3.1
  #define BLTOUCH_SET_5V_MODE // Default: Off
  #define BLTOUCH_FORCE_MODE_SET // Default: Off
  //#define BLTOUCH_HS_MODE // Default: Off
  #define BLTOUCH_LCD_VOLTAGE_MENU // Default: Off
#endif

#if ENABLED(HAS_PROBE)
  #undef USE_ZMAX_PLUG
  #undef MIN_SOFTWARE_ENDSTOP_Z  
  #define XY_PROBE_FEEDRATE (50*60)
  #if ENABLED(OCTOPUS)
    #undef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
    #undef Z_MIN_PROBE_PIN
    #define Z_MIN_PROBE_PIN                   PB7
    #define USE_PROBE_FOR_Z_HOMING
  #else
    #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
  #endif
  #undef MIN_SOFTWARE_ENDSTOP_Z
  #define Z_MIN_PROBE_REPEATABILITY_TEST
  #define Z_SAFE_HOMING
  #if ENABLED(Z_SAFE_HOMING)
    #define Z_SAFE_HOMING_X_POINT X_CENTER  // X point for Z homing
    #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // Y point for Z homing
  #endif
  #define Z_STEPPER_AUTO_ALIGN
  #define RESTORE_LEVELING_AFTER_G28
#elif NUM_Z_STEPPER_DRIVERS > 1
  #define Z_MULTI_ENDSTOPS
  #if ENABLED(Z_MULTI_ENDSTOPS)
    #define Z2_USE_ENDSTOP          _ZMAX_
    #define Z2_ENDSTOP_ADJUSTMENT   0
    #if NUM_Z_STEPPER_DRIVERS >= 3
      #define Z3_USE_ENDSTOP        _YMAX_
      #define Z3_ENDSTOP_ADJUSTMENT 0
    #endif
    #if NUM_Z_STEPPER_DRIVERS >= 4
      #define Z4_USE_ENDSTOP        _ZMAX_
      #define Z4_ENDSTOP_ADJUSTMENT 0
    #endif
  #endif
#define X_DRIVER_TYPE  DriverType
#define Y_DRIVER_TYPE  DriverType
#endif

//Filament Sensor
#if ENABLED(BTTSFR)
  #define FILAMENT_RUNOUT_DISTANCE_MM 7
  #define FILAMENT_MOTION_SENSOR
  #define M114_DETAIL         // Use 'M114` for details to check planner calculations
#endif

// Dynamic Variables
#define CUSTOM_MACHINE_NAME verS1 verS2 verS3 
#if ENABLED(OCTOPUS)
  #define NUM_RUNOUT_SENSORS   2 
  #define FIL_RUNOUT_STATE HIGH
  #define FIL_RUNOUT_PULLUP
  #define FIL_RUNOUT2_STATE HIGH
  #define FIL_RUNOUT2_PULLUP
#else 
  #define NUM_RUNOUT_SENSORS   1
#endif
#define X_DRIVER_TYPE  DriverType
#define Y_DRIVER_TYPE  DriverType
#define Z_DRIVER_TYPE  DriverType
#define X2_DRIVER_TYPE DriverType
#define Y2_DRIVER_TYPE DriverType
#define Z2_DRIVER_TYPE DriverType
#define Z3_DRIVER_TYPE DriverType
#define Z4_DRIVER_TYPE DriverType

/*
INPUT PARAMETERS:LUX_EXTRUDER_X_SPACING_LEFT
LUX_ENDSTOP_Y_OFFSET
*/

// DEFAULT VALS:
#define LUX_DEFAULT_Y_MIN_POS 3
#define LUX_DEFAULT_X_MIN_POS -50
#define LUX_DEFAULT_X2_MIN_POS 10

#define X_MIN_POS -46 //Also the distance from endstop to nozzle    //LUX_DEFAULT_X_MIN_POS +(LUX_EXTRUDER_X_SPACING_LEFT)
#define X_MAX_POS LUX_MEASURED_X_BED_SIZE

#define Y_MIN_POS 0 //LUX_EXTRUDER_Y_OFFSET +(LUX_ENDSTOP_Y_OFFSET)
#define Y_MAX_POS 300 //LUX_MEASURED_Y_BED_SIZE +(LUX_EXTRUDER_Y_OFFSET + LUX_ENDSTOP_Y_OFFSET)

#define X2_MIN_POS 18 //LUX_DEFAULT_X2_MIN_POS +(LUX_EXTRUDER_X_SPACING_LEFT)
#define X2_MAX_POS 372 //LUX_MEASURED_X_BED_SIZE + 44 //??

#define X_BED_SIZE 310 //LUX_MEASURED_X_BED_SIZE
#define Y_BED_SIZE 300 //LUX_MEASURED_Y_BED_SIZE -(Y_MIN_POS)

#define X1_MIN_POS X_MIN_POS   // Set to X_MIN_POS
#define X1_MAX_POS X_MAX_POS  // Set a maximum so the first X-carriage can't hit the parked second X-carriage
#define X2_HOME_POS X2_MAX_POS // Default X2 home position. Set to X2_MAX_POS.

#define NOZZLE_PARK_POINT { (X_MIN_POS), (Y_BED_SIZE), 20 }  //??

// Output bed size info
#pragma message "X2_MAX_POS: " STR(X2_MAX_POS)
// #pragma message "Y_MIN_POS: " STR(Y_MIN_POS)  " Y_MAX_POS: " STR(Y_MAX_POS)  " Y_BED_SIZE: " STR(Y_BED_SIZE)
// #pragma message "X_MIN_POS: " STR(X_MIN_POS)  " X_MAX_POS: " STR(X_MAX_POS)  " X_BED_SIZE: " STR(X_BED_SIZE)