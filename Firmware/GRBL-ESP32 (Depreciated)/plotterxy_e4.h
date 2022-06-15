#pragma once
// clang-format off

/*
    fysetc_e4.h
    https://github.com/FYSETC/FYSETC-E4

    2020-12-03 B. Dring

    This is a machine definition file to use the FYSETC E4 3D Printer controller
    This is a 4 motor controller. This is setup for XYZA, but XYYZ, could also be used.
    There are 5 inputs
    The controller has outputs for a Fan, Hotbed and Extruder. There are mapped to
    spindle, mist and flood coolant to drive an external relay.

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

//#define USE_FWD_KINEMATICS  // Report in cartesian, not the actual motor positions
//#define USE_MACHINE_INIT    // This machine requires custom initialization
//#define USE_CUSTOM_HOMING   // Special 2 motor motion is required to home each axis 

// $Homing/Cycle0=Y
// $Homing/Cycle1=X



#define MACHINE_NAME            "PLOTTERXY E4"

#define N_AXIS 2

#define CUSTOM_CODE_FILENAME    "../Custom/CoreXY.cpp" // This file has the function needed for CoreXY
#define USE_KINEMATICS      // there are kinematic equations for this machine

#define DEFAULT_HARD_LIMIT_ENABLE 1
#define DEFAULT_SOFT_LIMIT_ENABLE 1

#define DEFAULT_HOMING_ENABLE           1
#define DEFAULT_HOMING_DIR_MASK         0
#define DEFAULT_HOMING_FEED_RATE        200.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        4000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          10.0 // mm
#define DEFAULT_HOMING_CYCLE_0  bit(Y_AXIS)
#define DEFAULT_HOMING_CYCLE_1  bit(X_AXIS)

#define DEFAULT_X_STEPS_PER_MM  80.0
#define DEFAULT_Y_STEPS_PER_MM  80.0

#define DEFAULT_X_MAX_RATE      8000.0      // mm/min
#define DEFAULT_Y_MAX_RATE      8000.0      // mm/min
#define DEFAULT_X_ACCELERATION  8000.0      //mm/sec^2
#define DEFAULT_Y_ACCELERATION  8000.0      //mm/sec^2

#define TRINAMIC_RUN_MODE       TrinamicMode :: StealthChop
#define TRINAMIC_HOMING_MODE    TrinamicMode :: StealthChop

#define TMC_UART                UART_NUM_1
#define TMC_UART_RX             GPIO_NUM_21
#define TMC_UART_TX             GPIO_NUM_22   

// X
#define X_TRINAMIC_DRIVER       2209
#define X_STEP_PIN              GPIO_NUM_27
#define X_DIRECTION_PIN         GPIO_NUM_26
#define X_RSENSE                0.11f
#define X_DRIVER_ADDRESS        1
#define DEFAULT_X_MICROSTEPS    16
#define DEFAULT_X_CURRENT       1.8
#define DEFAULT_X_HOLD_CURRENT  1.0

// Y
#define Y_TRINAMIC_DRIVER       2209
#define Y_STEP_PIN              GPIO_NUM_33
#define Y_DIRECTION_PIN         GPIO_NUM_32
#define Y_RSENSE                0.11f
#define Y_DRIVER_ADDRESS        3
#define DEFAULT_Y_MICROSTEPS    16
#define DEFAULT_Y_CURRENT       1.8
#define DEFAULT_Y_HOLD_CURRENT  1.0


// Z
//#define X_TRINAMIC_DRIVER       2209
//#define X_STEP_PIN              GPIO_NUM_14
//#define X_DIRECTION_PIN         GPIO_NUM_12
//#define X_RSENSE                0.22f
//#define X_DRIVER_ADDRESS        0
//#define DEFAULT_X_MICROSTEPS    16

// A
//define Y_TRINAMIC_DRIVER       2209
//#define Y_STEP_PIN              GPIO_NUM_16
//#define Y_DIRECTION_PIN         GPIO_NUM_17
//#define Y_RSENSE                0.22f
//#define Y_DRIVER_ADDRESS        2
//#define DEFAULT_Y_MICROSTEPS    16

//#define X_LIMIT_PIN             GPIO_NUM_34
//#define Y_LIMIT_PIN             GPIO_NUM_35
#define X_LIMIT_PIN             GPIO_NUM_34 // labelled X-MIN
#define Y_LIMIT_PIN             GPIO_NUM_35 // labelled Y-MIN
//#define Z_LIMIT_PIN             GPIO_NUM_15
//#define A_LIMIT_PIN             GPIO_NUM_36   // Labeled TB
//#define PROBE_PIN               GPIO_NUM_39  // Labeled TE

#define DEFAULT_X_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.

#define DEFAULT_X_HOMING_MPOS DEFAULT_X_MAX_TRAVEL // stays up after homing
#define DEFAULT_Y_HOMING_MPOS DEFAULT_Y_MAX_TRAVEL // stays up after homing

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_25

#define SPINDLE_TYPE            SpindleType::PWM
//#define SPINDLE_OUTPUT_PIN      GPIO_NUM_13  // labeled Fan
//#define COOLANT_MIST_PIN        GPIO_NUM_2   // Labeled Hotbed
//#define COOLANT_FLOOD_PIN       GPIO_NUM_4   // Labeled Heater
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_2
#define SPINDLE_PWM_BASE_FREQ   30000
#define DEFAULT_SPINDLE_FREQ    30000

#define DEFAULT_SPINDLE_RPM_MIN 0.0 
#define DEFAULT_SPINDLE_RPM_MAX 100.0

