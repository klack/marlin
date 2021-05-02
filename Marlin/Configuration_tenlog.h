#define SHORT_BUILD_VERSION "2.0.7.2 for Luxuri 0.8.x"

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
#define TOOLCHANGE_NO_RETURN
#define HOST_ACTION_COMMANDS
// #define HOST_PROMPT_SUPPORT  
#define LIN_ADVANCE
#define LIN_ADVANCE_K 0
#define BABYSTEP_HOTEND_Z_OFFSET 

#define Y_MIN_ENDSTOP_INVERTING false  
#define Z_MIN_PROBE_ENDSTOP_INVERTING false
#define X2_HOME_DIR    1       // Set to 1. The second X-carriage always homes to the maximum endstop position
#define Z_MIN_POS 0
#define TEMP_SENSOR_BED 1
#define THERMAL_PROTECTION_BED_PERIOD        20 // Seconds
#define WATCH_BED_TEMP_PERIOD                60 // Seconds
#define SAFETY_Z_UNPARK 2.00 // 26/04/2021 Murdock avoid bed clips (Height to raise. Set to 0 for disable).
#define SAFETY_Y_UNPARK 15.00 // 26/04/2021 Murdock avoid bed clips (Distance to move on Y axis for avoid bed clips).


#if ENABLED(MachineTLD3P)
  #define verS1 "Tenlog TL-D3 Pro"
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
  #define Y_MIN_POS 3
  #define Y_MAX_POS Y_BED_SIZE + TOOL_CHANGE_AREA
  #define Z_MAX_POS 350
  #define DEFAULT_DUPLICATION_X_OFFSET 150
#elif ENABLED(MachineTLD5)
  #define verS1 "Tenlog TL-D5"
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
  #undef LIN_ADVANCE
  #undef LIN_ADVANCE_K
  #define verS2 "2208"
  #define DriverType TMC2208_STANDALONE
	#define INVERT_X_DIR false
  #define INVERT_Y_DIR true
	#define INVERT_Z_DIR false
	#define INVERT_E0_DIR true
	#define INVERT_E1_DIR false
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
#endif

#define TITAN_Y_OFFSET 5
#define TITAN_X_RIGHT_SPACING 3
#define TITAN_X_LEFT_SPACING 6
#if ENABLED(TitanExtruder)
  #undef X2_MIN_POS
  #undef X_MAX_POS
  #undef X2_MAX_POS
  #undef DEFAULT_AXIS_STEPS_PER_UNIT
  #undef Y_MIN_POS
  #define X2_MIN_POS 10 + TITAN_X_LEFT_SPACING
  #define X_MAX_POS 305 + TITAN_X_RIGHT_SPACING
  #define X2_MAX_POS 353 + TITAN_X_RIGHT_SPACING
  #define DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 800, 382.17, 382.17 }
  #define Y_MIN_POS 3 + TITAN_Y_OFFSET
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
  #define verS3 "PLR"
#else
  #define verS3 ""
#endif

#if ENABLED(BL_Touch)
  #define HAS_PROBE
  #define BLTOUCH
  #define NOZZLE_TO_PROBE_OFFSET { 7, -47, -2.5 }
  #define AUTO_BED_LEVELING_UBL
  #define PROBING_MARGIN 15
#elif ENABLED(EZabl)
  #define HAS_PROBE
  #define FIX_MOUNTED_PROBE
  #define NOZZLE_TO_PROBE_OFFSET { -25, -55, -2 }
  #undef  Z_MIN_PROBE_ENDSTOP_INVERTING
  #define Z_MIN_PROBE_ENDSTOP_INVERTING true
  #define MULTIPLE_PROBING 2
  #define Z_HOMING_HEIGHT  7 
  #define Z_AFTER_HOMING  2 
  #define AUTO_BED_LEVELING_BILINEAR
  #define ENABLE_LEVELING_FADE_HEIGHT
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)
  #define GRID_MAX_POINTS_X 7
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
  #define EXTRAPOLATE_BEYOND_GRID
  #define PROBING_MARGIN 30
  #define ABL_BILINEAR_SUBDIVISION
  //#define BILINEAR_SUBDIVISIONS 5
#endif

#if ENABLED(HAS_PROBE)
  #undef USE_ZMAX_PLUG
  #undef MIN_SOFTWARE_ENDSTOP_Z
  #define BABYSTEP_ZPROBE_OFFSET          // Combine M851 Z and Babystepping
  #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
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

#if ENABLED(AC_Bed)
  #undef THERMAL_PROTECTION_BED_PERIOD
  #undef WATCH_BED_TEMP_PERIOD
  #undef TEMP_SENSOR_BED
  #define THERMAL_PROTECTION_BED_PERIOD 10
  #define WATCH_BED_TEMP_PERIOD 20
  #define TEMP_SENSOR_BED 11
#endif

// Dynamic Variables
#define CUSTOM_MACHINE_NAME verS1 " " verS2 " " verS3
#define X_DRIVER_TYPE  DriverType
#define Y_DRIVER_TYPE  DriverType
#define Z_DRIVER_TYPE  DriverType
#define X2_DRIVER_TYPE DriverType
#define Y2_DRIVER_TYPE DriverType
#define Z2_DRIVER_TYPE DriverType
#define Z3_DRIVER_TYPE DriverType
#define Z4_DRIVER_TYPE DriverType
#define E0_DRIVER_TYPE DriverType
#define E1_DRIVER_TYPE DriverType
