Install vpype:
https://github.com/abey79/vpype

Install vpype-gcode
https://github.com/plottertools/vpype-gcode/

Understand how to use the supplied toml file here; https://vpype.readthedocs.io/en/latest/cookbook.html?highlight=vpype.toml#creating-a-custom-configuration-file

You should then be able to run: "vpype read input.svg gwrite output.gcode" to create a gcode file.

You might want to try "vpype read input.svg linemerge -t 0.1 reloop linesimplify --tolerance 0.05 linesort output.gcode" to create more efficient plots.

You may want to adjust the pen drop time in the .toml file "G4 P0.250" – the P setting adjusts how long the plotter waits for the pen to drop before starting the line. "G4 P0.250" means "pause for 0.250 seconds".
