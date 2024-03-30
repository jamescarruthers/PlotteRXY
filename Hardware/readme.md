*The 2040 Y-axis is depreciated at this time.* Only print one Y-axis folder - depending on what extrusion profile you are using for your y-axis. Unless you are making a giant A0 or larger plotter then use the 2020 sized version. Note that this design hasn't been tested above A1 size.

# How long should my extrusions be?

Let's say you want to build an A2 machine; 600 x 420 (rounded up)

X extrusion = width + 240 = 600 + 240 = 840mm

Y extrusion = length + 180 = 420 + 180 = 600mm

Y axis = Y extrusion - 13 = 587mm

These numbers have a bit of excess to allow a bit of movement around the outside of the plot area.

![Naming diagram](./diagram.png)

# Hardware build guide

1. Print out a corner pulley mount and check that it fits snuggly into your v-slot extrusion. If it doesn't you might need to recalibrate your printer.
2. Print out all the parts. The number at the end of the filename is the quantity you'll need — so Pulley_2.3mf means you need 2.
3. Layout out the extrusion and printed parts on a table according to the diagram above, work out where you will need to insert t-nuts. This is important because once you start assembly certain t-nuts are impossible to insert without loosening and/or disassembling.
4. Build up the z-axis gantry and slide it on to the y-axis. The wheels should have shims and spacers on either side.
5. Build up the y-axis carriages and attach them to the y-axis extrusion. All pulleys sit on a single shim and have two shims between the F605 bearings. Keep the screws that hold it to the y-axis loose for now.
6. Install the end caps and servo mounts to the extusions so you have an open sided C shape. Note the orientation of the servo mounts, they are opposite ways up with the flat part in the middle of the extrusion.
7. Slide the whole y-axis assembly on to the extrusion.
8. Install the pulley mounts, end caps and attach the final extrusion to close the frame.
9. Adjust all the mount screws until the frame is square. Adjust the eccentric nuts. The y-axis should slide left to right freely. Tighten the screws that hold the y-axis in place.
10. Install all the pulleys. They pulleys should sit on a single shim spacer, with two shims in between the two bearings.
11. Install the servos in to the servo mounts, being sure to vertically align the toothed pulley with the pulleys on the mount. Depending on the pulley you may need to use one of the stepper spacers between the motor and the mount to align the belt so that it sits in the middle of the teeth on the pulley.
12. Install belts and attach to the belt tension plate. They should not be tight at this stage — but should not droop. Leave at least 80mm of extra belt so that you can adjust it later.

![Belt path](./Images/IMG_5494.jpeg)
![Belt path](./Images/IMG_5495.jpeg)

13. Use the tensioners to get the belt tight. It should not be super tight, but the belt should not droop.
14. Attach the belt tension plate to the z-axis gantry.
15. Move the y-axis towards and up against the corner pulley mounts. Check that the y-axis is square by ensuring the gap between the rounded part of the y-axis carriages have equal space against the corner pulley mounts. Each y-axis carriage should sit flat against the corner pulleys. If they're not, then this means each belt has uneven tension. Use the belt tensioners to adjust, they should only need minimal movement.
16. Build up pen lift and install on to gantry.
