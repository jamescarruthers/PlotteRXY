Install vpype:
https://github.com/abey79/vpype

Install vpype-gcode
https://github.com/plottertools/vpype-gcode/

See the section "Defining Your Own Profiles" and use the file above. You will need to rename it .vpype.toml

You should then be able to run: "vpype read input.svg gwrite output.gcode" to create a gcode file.

You may need to adjust the S and G commands to accomodate the weight of the pen or the pen lift mechanism. S controls the PWM and G the delay time in seconds. Ideally adjust these numbers to the lowest values possible.
