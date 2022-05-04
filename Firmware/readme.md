PlotterXY uses FluidNC: https://github.com/bdring/FluidNC

1. Install FluidNC on your FYSETC E4.
2. Upload the yaml config file to your board.
3. Restart the machine.

Before switching on the first time, move the gantry in to the centre of the work area. Turn on and connect to the web UI. Click on the clear alarm button. Use the jog function to check that the gantry moves in the right direction. If it doesn't, then adjust the direction_pin in the config file from high to low.

You will need to adjust the max_travel_mm and mpos_mm values in the config file for both the x and y axes to reflect the size of your plotter. The mpos_mm value should match the max_travel_mm. It's best to home the machine with the default settings, and then use a tape measure to get the dimensions. When homing move the z-gantry somewhere close to the top right, a couple of centimetres away from the limit swiches. Start off configuring it with a smaller size and then check out the movement of the machine with the jog function to make sure that the z-axis doesn't crash in to the right and bottom extrusions when you move it to 0,0.
