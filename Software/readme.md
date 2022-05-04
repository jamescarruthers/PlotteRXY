Install vpype:
https://github.com/abey79/vpype

Install vpype-gcode
https://github.com/plottertools/vpype-gcode/

Understand how to use the supplied toml file here; https://vpype.readthedocs.io/en/latest/cookbook.html?highlight=vpype.toml#creating-a-custom-configuration-file

You should then be able to run: "vpype read input.svg gwrite output.gcode" to create a gcode file.

You may need to adjust the S and G commands to accomodate the weight of the pen or the pen lift mechanism. S controls the PWM and G the delay time in seconds. Ideally adjust these numbers to the lowest values possible.
