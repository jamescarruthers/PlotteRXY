Install vpype:
https://github.com/abey79/vpype

Install vpype-gcode
https://github.com/plottertools/vpype-gcode/

Understand how to use the supplied toml file here; https://vpype.readthedocs.io/en/latest/cookbook.html?highlight=vpype.toml#creating-a-custom-configuration-file – hint; you need to rename "vpype.toml" to ".vpype.toml" and put it in your user folder.

You should then be able to run: "vpype read input.svg gwrite output.gcode" to create a gcode file.

You might want to try "vpype read input.svg linemerge -t 0.1 linesimplify -t 0.1 reloop linesort -t gwrite output.gcode" to create more efficient plots.

You may want to adjust the pen drop time in the .toml file "G4 P0.250" – the P setting adjusts how long the plotter waits for the pen to drop before starting the line. "G4 P0.250" means "pause for 0.250 seconds".

By default the profile used to output is for the solenoid pen lift. You can change the default profile in the .toml file.

To use the stepper pen lift change the profile using -p and use rxy_step5, rxy_step10 or rxy_step20. The number represents the amount of lift in mm.

"vpype read input.svg gwrite -p rxy_step5 output.gcode"
