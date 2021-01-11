#define SHORT_BUILD_VERSION "bugfix-2.0.x lux-0.7"

#if ENABLED(MachineTLD3P)
  #define verS1 "Tenlog TL-D3 Pro"
  #define X_BED_SIZE        310
  #define Y_BED_SIZE        310
  #define TOOL_CHANGE_AREA  24 
  #define Z_MIN_POS 0
  #define Y_MAX_POS Y_BED_SIZE + TOOL_CHANGE_AREA
  #define Z_MAX_POS 350
  #define X2_HOME_DIR    1       // Set to 1. The second X-carriage always homes to the maximum endstop position
  #define DEFAULT_DUPLICATION_X_OFFSET 155

  #if ENABLED(Titan)
    #define Y_MIN_POS 3
    #define X_MIN_POS -41 // Travel limits (mm) after homing, corresponding to endstop positions.
    #define X_MAX_POS 307
    #define X2_MIN_POS     17      // Set a minimum to ensure the  second X-carriage can't hit the parked first X-carriage
    #define X2_MAX_POS   371       // Set this to the distance between toolheads when both heads are homed
    #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 792, 382.17, 382.17 }
  #else
    #define Y_MIN_POS 0
    #define X_MIN_POS -48 // Travel limits (mm) after homing, corresponding to endstop positions.
    #define X_MAX_POS 305
    #define X2_MIN_POS     10      // Set a minimum to ensure the  second X-carriage can't hit the parked first X-carriage
    #define X2_MAX_POS   353       // Set this to the distance between toolheads when both heads are homed
    #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 792, 92.6, 92.6 }
  #endif

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

#if ENABLED(POWER_LOSS_TRIGGER_BY_PIN)
  #define verS3 "PLR"
#endif

#define X_HOME_DIR -1
#define Z_HOME_DIR -1

#if ENABLED(ReverseYHome)
  #define Y_HOME_DIR 1
  #define USE_YMAX_PLUG
#else
  #define Y_HOME_DIR -1
#endif

#if ENABLED(BL_Touch)
  #define Z_MULTI_ENDSTOPS false
  #define BLTOUCH
  #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
  #define Z_SAFE_HOMING
  #define Z_STEPPER_AUTO_ALIGN
  #define PROBING_MARGIN 50
  #define NOZZLE_TO_PROBE_OFFSET { -47, -23, -1.6 }
  #define AUTO_BED_LEVELING_UBL
  #define RESTORE_LEVELING_AFTER_G28
#endif

#define CUSTOM_MACHINE_NAME verS1 " " verS2 " " verS3

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