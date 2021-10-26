PlotterXY uses Grbl_ESP32: https://github.com/bdring/Grbl_Esp32

1. Download Grbl_ESP32. Follow the instructions.
2. Copy the PlotterXY_E4.h file to the machines folder and adjust the config.h to point towards it. See the section "Customize "Grbl_Esp32/src/Machine.h""
3. Compile and upload to the FYSETC E4 board. (remember that the board needs power!)

You will need to adjust the DEFAULT_X_MAX_TRAVEL and DEFAULT_Y_MAX_TRAVEL to reflect the size of your plotter. It's safer to do this after the firmware is compiled and uploaded, and you can use the jog function to move the gantry in to the 0,0 position.
