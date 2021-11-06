#define SHORT_BUILD_VERSION "2.0.9.2 for Luxuri 0.9.x"

//Common
#define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 92.6, 92.6 }
#define NUM_Z_STEPPER_DRIVERS 2   // (1-4) Z options change based on how many
#define DUAL_X_CARRIAGE
#define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE  
#define USE_ZMAX_PLUG
#define MIN_SOFTWARE_ENDSTOPS
#define MIN_SOFTWARE_ENDSTOP_X
#define MIN_SOFTWARE_ENDSTOP_Y
#define MIN_SOFTWARE_ENDSTOP_Z
#define Z_MIN_ENDSTOP_INVERTING true
#define TOOLCHANGE_NO_RETURN
#define HOST_ACTION_COMMANDS
#define HAS_STATUS_MESSAGE 1
#define LIN_ADVANCE
#define LIN_ADVANCE_K 0
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
#define verS3 ""
#define QUICK_HOME 

#if ENABLED(MachineTLD3P)
  #define verS1 "Tenlog TL-D3 Pro"
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 92.6, 92.6 }
  #define NUM_Z_STEPPER_DRIVERS 2   // (1-4) Z options change based on how many
  #define DUAL_X_CARRIAGE
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE  
  #define BED_CENTER_AT_155_155
  #define X_BED_SIZE        310
  #define Y_BED_SIZE        310
  #define TOOL_CHANGE_AREA  14
  #define X_MIN_POS -50
  #define X_MAX_POS 305
  #define X1_MIN_POS X_MIN_POS   // Set to X_MIN_POS
  #define X1_MAX_POS X_MAX_POS  // Set a maximum so the first X-carriage can't hit the parked second X-carriage
  #define X2_MIN_POS 10
  #define X2_MAX_POS 354
  #define X2_HOME_POS X2_MAX_POS // Default X2 home position. Set to X2_MAX_POS.
  #define X2_HOME_DIR    1       // Set to 1. The second X-carriage always homes to the maximum endstop position
  #define Y_MIN_POS 3
  #define Y_MIN_ENDSTOP_INVERTING false  
  #define Y_MAX_POS Y_BED_SIZE + TOOL_CHANGE_AREA
  #define Z_MIN_POS 0
  #define Z_MIN_PROBE_ENDSTOP_INVERTING false
  #define Z_MAX_POS 350
  #define DEFAULT_DUPLICATION_X_OFFSET 150
  #define USE_ZMAX_PLUG
  #define MIN_SOFTWARE_ENDSTOPS
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
  #define TOOLCHANGE_NO_RETURN
  #define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }
#elif ENABLED(MachineTLD5)
  #define verS1 "Tenlog TL-D5"
  #undef verS3
  #define verS3 ""
  #define X_BED_SIZE        510
  #define Y_BED_SIZE        510
  #define TOOL_CHANGE_AREA  0
  #define X_MIN_POS -50
  #define X_MAX_POS 505
  #define X1_MIN_POS X_MIN_POS   // Set to X_MIN_POS
  #define X1_MAX_POS X_MAX_POS  // Set a maximum so the first X-carriage can't hit the parked second X-carriage
  #define X2_MIN_POS 10
  #define X2_MAX_POS 555.6
  #define X2_HOME_POS X2_MAX_POS // Default X2 home position. Set to X2_MAX_POS.
  #define Y_MIN_POS 3
  #define Y_MAX_POS Y_BED_SIZE + TOOL_CHANGE_AREA
  #define Z_MAX_POS 350
  #define DEFAULT_DUPLICATION_X_OFFSET 250
  #define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }
#endif 
#if ENABLED(BTTSKRPRO)
  #undef verS3
  #define verS3 "BTTSKRPRO"
  #define POWER_OFF_PIN 32 // This is not functional but is needed due to MarlinCore.h being modified for the TL-D3 Power Switch
  #define POWER_OFF_STATE HIGH // This is not functional but is needed due to MarlinCore.h being modified for the TL-D3 Power Switch
  #define USE_CONTROLLER_FAN
#endif
#if ENABLED(OCTOPUS)
  #undef verS3
  #define verS3 "OCTOPUS"
  #define POWER_OFF_STATE HIGH // This is not functional but is needed due to MarlinCore.h being modified for the TL-D3 Power Switch
#endif
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
  //#define STEALTHCHOP_E
#elif ENABLED(Driver2208_UART)
  #define verS2 "2208_UART"
  #define DriverType TMC2208
	#define INVERT_X_DIR false
  #define INVERT_Y_DIR true
	#define INVERT_Z_DIR false  
	#define INVERT_E0_DIR false
	#define INVERT_E1_DIR true
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  //#define STEALTHCHOP_E
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
  //#define STEALTHCHOP_E
  //#define MONITOR_DRIVER_STATUS
  //#define TMC_DEBUG
#elif ENABLED(Driver2209BTT)
  #define verS2 "2209BTT"
  #define DriverType TMC2209
  #define INVERT_Z_DIR false
  #define INVERT_Z2_VS_Z_DIR false
  #define INVERT_X2_VS_X_DIR false
  #define INVERT_E0_DIR true
  #define INVERT_E1_DIR true
  #define X_MIN_ENDSTOP_INVERTING true
  #define Z_MIN_ENDSTOP_INVERTING true
  #define Z_MAX_ENDSTOP_INVERTING true
  #define X_MAX_ENDSTOP_INVERTING true
  #define TMC_DEBUG
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  //#define STEALTHCHOP_E
  #if ENABLED(BTTSKRPRO)
    #define STARTUP_COMMANDS "M569 S0 I1 X Y Z T1 E \n M569 S0 X Y Z \n M412 S0" // Enable stealthchop for all steppers except extruders
    #define INVERT_X_DIR true
    #define INVERT_Y_DIR false
  #elif ENABLED(OCTOPUS)
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

#define TITAN_Y_OFFSET 5
#define TITAN_X_RIGHT_SPACING 3
#define TITAN_X_LEFT_SPACING 6
#if ENABLED(TitanExtruder)
  #undef X_MIN_POS
  #undef X2_MIN_POS
  #undef X_MAX_POS
  #undef X2_MAX_POS
  #undef DEFAULT_AXIS_STEPS_PER_UNIT
  #undef Y_MIN_POS
  #define X_MIN_POS -47
  #define X2_MIN_POS 10 + TITAN_X_LEFT_SPACING
  #define X_MAX_POS 305 + TITAN_X_RIGHT_SPACING
  #define X2_MAX_POS 353 + TITAN_X_RIGHT_SPACING
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 382.17, 382.17 }
#elif ENABLED(BMGExtruder)
  #undef DEFAULT_AXIS_STEPS_PER_UNIT
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 413, 413 }
#endif

#define OPTICALY_Y_OFFSET 4
#if ENABLED(OpticalY)
  #undef Y_MIN_ENDSTOP_INVERTING
  #define Y_MIN_ENDSTOP_INVERTING true
#endif

#if ENABLED(TitanExtruder) || ENABLED(OpticalY)
  #undef TOOL_CHANGE_AREA
  #undef Y_MIN_POS
#endif
#if ENABLED(TitanExtruder) && ENABLED(OpticalY)
  #define Y_MIN_POS 3 + TITAN_Y_OFFSET + OPTICALY_Y_OFFSET
  #define TOOL_CHANGE_AREA 14 + TITAN_Y_OFFSET - OPTICALY_Y_OFFSET
#elif ENABLED(TitanExtruder)
  #define Y_MIN_POS 3 + TITAN_Y_OFFSET
  #define TOOL_CHANGE_AREA 14 + TITAN_Y_OFFSET
#elif ENABLED(OpticalY) 
  #define Y_MIN_POS 3 + OPTICALY_Y_OFFSET
  #define TOOL_CHANGE_AREA 14 - OPTICALY_Y_OFFSET
#endif

#if ENABLED(TGCustom_2209_Titan)
  #define verS2 "2209_Titan_TGCustom"
  #define DriverType TMC2209_STANDALONE
  #define INVERT_X_DIR true
  #define INVERT_Y_DIR false
  #define INVERT_Z_DIR true
  #define INVERT_E0_DIR false
  #define INVERT_E1_DIR true
  #undef X2_MIN_POS
  #define X2_MIN_POS     15
#endif

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

#if ENABLED(BL_Touch)
  #ifndef OCTOPUS
    #undef Z_MIN_ENDSTOP_INVERTING
    #define Z_MIN_ENDSTOP_INVERTING false
  #endif
  #define HAS_PROBE
  #define BLTOUCH
  #if ENABLED(BMGExtruder)
    #define NOZZLE_TO_PROBE_OFFSET { -1.75, -42, -2.3837 }
    #undef HOMING_FEEDRATE_MM_M
    #define HOMING_FEEDRATE_MM_M { (70*60), (70*60), (8*60) }
    #define Z_HOMING_HEIGHT  4 
    #define Z_AFTER_HOMING  2 
  #else
    #define NOZZLE_TO_PROBE_OFFSET { 7, -47, -2.5 }
  #endif
  #define AUTO_BED_LEVELING_UBL
  #define PROBING_MARGIN 15
  #define MESH_INSET 15 
  #define GRID_MAX_POINTS_X 10
  #define G26_MESH_VALIDATION
  #define Z_CLEARANCE_BETWEEN_PROBES  3 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     2 // Z Clearance between multiple probes
  //#define MULTIPLE_PROBING 2
  //#define EXTRA_PROBING    1
  //BLTouch Options. For details read BLTouch section in Configuration_adv.h
  //Settings for BLTOUCH Classic 1.2, 1.3 or BLTouch Smart 1.0, 2.0, 2.2, 3.0, 3.1, and most clones
  #define BLTOUCH_DELAY 200 // Default: 375, min 200
  #define BLTOUCH_FORCE_SW_MODE // Default: Off
  //Settings for BLTouch Smart 3.0 and 3.1
  #define BLTOUCH_SET_5V_MODE // Default: Off
  #define BLTOUCH_FORCE_MODE_SET // Default: Off
  //#define BLTOUCH_HS_MODE // Default: Off
  #define BLTOUCH_LCD_VOLTAGE_MENU // Default: Off
#elif ENABLED(EZabl)
  #define HAS_PROBE
  #define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probes
  #define FIX_MOUNTED_PROBE
  #if ENABLED(BMGExtruder)
    #define NOZZLE_TO_PROBE_OFFSET { +29, -46, -1.2 }
  #else
    #define NOZZLE_TO_PROBE_OFFSET { -25, -55, -2 }
  #endif
  #undef  Z_MIN_PROBE_ENDSTOP_INVERTING
  #define Z_MIN_PROBE_ENDSTOP_INVERTING true
  #undef HOMING_FEEDRATE_MM_M
    #define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }
  #define USE_PROBE_FOR_Z_HOMING
  #define MULTIPLE_PROBING 2
  #define EXTRA_PROBING    1
  #define Z_HOMING_HEIGHT  7 
  #define Z_AFTER_HOMING  2 
  #define PROBING_HEATERS_OFF
  #define WAIT_FOR_BED_HEATER
  #define AUTO_BED_LEVELING_UBL
  //#define AUTO_BED_LEVELING_BILINEAR
  #define GRID_MAX_POINTS_X 10
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
  #define EXTRAPOLATE_BEYOND_GRID
  #define PROBING_MARGIN 45
  #define MESH_INSET 50 
  //#define ABL_BILINEAR_SUBDIVISION
#elif ENABLED(IRPROBE)
  #if ENABLED(BMGExtruder)
    #define NOZZLE_TO_PROBE_OFFSET { +27.40, -18.90, 0 }
    #undef HOMING_FEEDRATE_MM_M
    #define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }
    #define Z_HOMING_HEIGHT  5 
    #define Z_AFTER_HOMING  2 
  #else
    #define NOZZLE_TO_PROBE_OFFSET { 7, -47, -2.5 }
  #endif
  #define HAS_PROBE
  #define FIX_MOUNTED_PROBE
  #define AUTO_BED_LEVELING_UBL
  #define PROBING_MARGIN 15
  #define MESH_INSET 15 
  #define GRID_MAX_POINTS_X 10
  #define G26_MESH_VALIDATION
  #define Z_CLEARANCE_BETWEEN_PROBES  2 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     2 // Z Clearance between multiple probes
  //#define MULTIPLE_PROBING 2
  //#define EXTRA_PROBING    1
#endif

#if ENABLED(HAS_PROBE)
  #undef USE_ZMAX_PLUG
  #undef MIN_SOFTWARE_ENDSTOP_Z  
  #define XY_PROBE_FEEDRATE (50*60)
  #if ENABLED(BTTSKRPRO)
    #undef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
    #undef Z_MIN_PROBE_PIN
    #define Z_MIN_PROBE_PIN                   PA2
  #elif ENABLED(OCTOPUS)
    #if ENABLED(LCD_BTT_TFT)
      #define BAUDRATE 115200 // Set serial 1 TFT port baudrate
    #else
      #define BAUDRATE 9600 // Set serial 1 TFT port baudrate
    #endif
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
#endif

#if ENABLED(BTTSFR)
  #define FILAMENT_RUNOUT_DISTANCE_MM 7
  #define FILAMENT_MOTION_SENSOR
  #define M114_DETAIL         // Use 'M114` for details to check planner calculations
#endif

// Dynamic Variables
#define CUSTOM_MACHINE_NAME verS1 verS2 verS3 
#if ENABLED(BTTSKRPRO)
  #define NUM_RUNOUT_SENSORS   2 
  #define FIL_RUNOUT_STATE HIGH
  #define FIL_RUNOUT_PULLUP
  #define FIL_RUNOUT2_STATE HIGH
  #define FIL_RUNOUT2_PULLUP
#elif ENABLED(OCTOPUS)
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

#if ENABLED(A9EXT)
  #define E0_DRIVER_TYPE A4988
  #define E1_DRIVER_TYPE A4988
  #define LIN_ADVANCE
  #define LIN_ADVANCE_K 0
  #undef INVERT_E0_DIR
	#undef INVERT_E1_DIR
	#define INVERT_E0_DIR false
	#define INVERT_E1_DIR true
#else
  #define E0_DRIVER_TYPE DriverType
  #define E1_DRIVER_TYPE DriverType
#endif
