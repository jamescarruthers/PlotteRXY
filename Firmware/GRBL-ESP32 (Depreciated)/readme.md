PlotterXY uses Grbl_ESP32: https://github.com/bdring/Grbl_Esp32

1. Download Grbl_ESP32. Follow the instructions.
2. Copy the PlotterXY_E4.h file to the machines folder and adjust the config.h to point towards it. See the section "Customize "Grbl_Esp32/src/Machine.h"" in the installation part of the wiki.
3. Compile and upload to the FYSETC E4 board. (remember that the board needs power!)

Connections:
* X-MOT: X stepper motor
* Y-MOT: Y stepper motor
* X-MIN: X limit switch
* Y-MIN: Y limit switch (on the z-axis gantry)
* HEATER: Solenoid

You will also need to use two jumpers to enable TMC2209 UART:

![Jumpers](https://github.com/FYSETC/FYSETC-E4/raw/main/images/E4%E9%A9%B1%E5%8A%A8%E8%B7%B3%E7%BA%BF.png)

You will need to adjust the DEFAULT_X_MAX_TRAVEL and DEFAULT_Y_MAX_TRAVEL to reflect the size of your plotter. It's safer to do this after the firmware is compiled and uploaded, and you can use the jog function to move the gantry in to the 0,0 position.

Before switching on the first time, move the gantry in to the centre of the work area. Turn on and connect to the web UI. Click on the clear alarm button. Use the jog function to check that the gantry moves in the right direction. If it doesn't, then adjust the stepper motor direction in config.
