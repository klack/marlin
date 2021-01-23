#define SHORT_BUILD_VERSION "bugfix-2.0.x lux-0.7"

#if ENABLED(MachineTLD3P)
  #define verS1 "Tenlog TL-D3 Pro"
  #define Z_MIN_POS 0
  #define Z_MAX_POS 350
  #define X2_HOME_DIR    1       // Set to 1. The second X-carriage always homes to the maximum endstop position
  #define DEFAULT_DUPLICATION_X_OFFSET 155
  #define USE_ZMAX_PLUG
  #define MIN_SOFTWARE_ENDSTOPS
  #define NUM_Z_STEPPER_DRIVERS 2   // (1-4) Z options change based on how many
  #define Z_MIN_PROBE_ENDSTOP_INVERTING false
  #if ENABLED(MIN_SOFTWARE_ENDSTOPS)
    #define MIN_SOFTWARE_ENDSTOP_X
    #define MIN_SOFTWARE_ENDSTOP_Y
    #define MIN_SOFTWARE_ENDSTOP_Z
  #endif
  #define X_BED_SIZE        310
  #define Y_BED_SIZE        310
  #if ENABLED(OpticalY)
    #define TOOL_CHANGE_AREA  10
  #else
    #define TOOL_CHANGE_AREA  24
  #endif
  #define Y_MAX_POS Y_BED_SIZE + TOOL_CHANGE_AREA
  #define BED_CENTER_AT_155_155
  #define TOOLCHANGE_NO_RETURN
  #define DEFAULT_MAX_FEEDRATE          { 80, 80, 3, 25, 25 }
  #define HOMING_FEEDRATE_Z  (4*60) 
  #define Z_CLEARANCE_BETWEEN_PROBES  5
#endif

#if ENABLED(DriverA4988)
  #define verS2 "A4988"
  #define DriverType A4988
  #define INVERT_X_DIR true
  #define INVERT_Y_DIR false
  #define INVERT_Z_DIR true
  #define INVERT_E0_DIR false
  #define INVERT_E1_DIR true
#endif

#if ENABLED(Driver2208)
  #define verS2 "2208"
  #define DriverType TMC2208_STANDALONE
	#define INVERT_X_DIR false   
  #define INVERT_Y_DIR true 
	#define INVERT_Z_DIR false   
	#define INVERT_E0_DIR true  
	#define INVERT_E1_DIR false  
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

#if ENABLED(TitanExtruder)
  #undef X2_MIN_POS
  #define X2_MIN_POS     16
  #define Y_MIN_POS 11
  #define X_MIN_POS -47 // Travel limits (mm) after homing, corresponding to endstop positions.
  #define X_MAX_POS 306
  #define X2_MAX_POS   371       // Set this to the distance between toolheads when both heads are homed
  #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 800, 382.17, 382.17 }
#else
  #undef X2_MIN_POS
  #define X2_MIN_POS     10      // Set a minimum to ensure the  second X-carriage can't hit the parked first X-carriage
  #define Y_MIN_POS 7
  #define X_MIN_POS -47 // Travel limits (mm) after homing, corresponding to endstop positions.
  #define X_MAX_POS 305
  #define X2_MAX_POS   353       // Set this to the distance between toolheads when both heads are homed
  #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 800, 92.6, 92.6 }
#endif

#if ENABLED(POWER_LOSS_TRIGGER_BY_PIN)
  #define verS3 "PLR"
#endif

#if ENABLED(OpticalY)
  #define Y_MIN_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
#else
  #define Y_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#endif

#if ENABLED(BL_Touch)
  #define HAS_PROBE
  #define BLTOUCH
  #define NOZZLE_TO_PROBE_OFFSET { 7, -47, -2.5 }
  #define PROBING_MARGIN 15
  #define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
  #define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probe
  #define Z_PROBE_LOW_POINT          -2 
#endif
#if ENABLED(EZabl)
  #undef  DEFAULT_MAX_FEEDRATE
  #define DEFAULT_MAX_FEEDRATE          { 80, 80, 15, 25, 25 }
  #define HAS_PROBE
  #define FIX_MOUNTED_PROBE
  #define NOZZLE_TO_PROBE_OFFSET { -25, -55, 0 }
  #define Z_CLEARANCE_DEPLOY_PROBE 5
  #undef Z_CLEARANCE_BETWEEN_PROBES
  #define Z_CLEARANCE_BETWEEN_PROBES 3
  #define Z_CLEARANCE_MULTI_PROBE 3
  #define Z_AFTER_PROBING           5 // Z position after probing is done
  #define Z_AFTER_HOMING 5
  #define Z_PROBE_LOW_POINT          -5
  #undef  Z_MIN_PROBE_ENDSTOP_INVERTING
  #define Z_MIN_PROBE_ENDSTOP_INVERTING true
  #undef HOMING_FEEDRATE_Z
  #define HOMING_FEEDRATE_Z  (8*60) 
  #define MULTIPLE_PROBING 2
  #define EXTRA_PROBING    1
  #define PROBING_MARGIN 50
#endif

#if ENABLED(HAS_PROBE)
  #undef USE_ZMAX_PLUG
  #undef MIN_SOFTWARE_ENDSTOP_Z
  #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
  #define Z_MIN_PROBE_REPEATABILITY_TEST
  #define Z_SAFE_HOMING
  #define Z_STEPPER_AUTO_ALIGN
  #define RESTORE_LEVELING_AFTER_G28
  #define AUTO_BED_LEVELING_UBL
#else
	#if NUM_Z_STEPPER_DRIVERS > 1
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
#endif

#if ENABLED(BTTSFR)
  #define FILAMENT_RUNOUT_DISTANCE_MM 7
  #define FILAMENT_MOTION_SENSOR
  #define M114_DETAIL         // Use 'M114` for details to check planner calculations
#endif

#define CUSTOM_MACHINE_NAME verS1 " " verS2 " " verS3

// Enables action host prompts.  Action prompts send a message to the connected host for display in the host console or to perform a host action.
// This allows for Octoprint to receive "Filament Runout" prompts and pause printing. 
// https://marlinfw.org/docs/gcode/M118.html
// https://docs.octoprint.org/en/master/bundledplugins/action_command_prompt.html
#define HOST_ACTION_COMMANDS
#define HOST_PROMPT_SUPPORT

// Common
#define DUAL_X_CARRIAGE
#define X1_MIN_POS X_MIN_POS   // Set to X_MIN_POS
#define X1_MAX_POS X_BED_SIZE  // Set a maximum so the first X-carriage can't hit the parked second X-carriage
#define X2_HOME_POS X2_MAX_POS // Default X2 home position. Set to X2_MAX_POS.
#define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE

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

