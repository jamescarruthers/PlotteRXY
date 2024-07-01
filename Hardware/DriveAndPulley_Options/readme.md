There are a few different options for drive and pulley configurations depending on what you want to achieve.

V2 is suggested for new builds as it's a much neater layout, allowing one end of the plotter to be free of belt and any kind of wiring. It also drives the middle of the belt, rather than more towards one end.

Note that there is no upgrade path from V2 to 4WD. If you want 4WD use V1. There's nothing wrong with V1, it just drove the "wrong" part of the belt - which happens to be the right part for 4WD.

## V1 Original

* 2 x V1 stepper mount
* 2 x V1 pulley mount

![V1](./../images/V1.png)

## V1 with 4-wheel-drive

* 2 x V1 stepper mount
* 2 x V1 stepper mount AWD

![V1AWD](./../images/4WD.png)

## > Note: V2 is currently untested - use at your own risk

## V2

* 2 x V2 stepper mount
* 2 x V2 pulley mount

![V2](./../images/V2.png)


## V2 with central drive

* 1 x central drive
* 4 x V2 pulley mount

![V2 central drive](./../images/Central.png)

This configuration mounts the two steppers together, place it in the middle of the rail.


## 4-wheel-drive tensioning procedure

Use the following procedure to make sure the pulley teeth are synchronised.

1. Power off the plotter.
2. Disconnect the two 4WD steppers from the controller board and loosen the two grub screws on both the 4WD pulleys.
3. Adjust the tension on both belts.
4. Power the plotter on.
5. Ensure the 4WD pulleys are engaged with the belt.
6. Tighten the grub screws on the 4WD pulleys, ensuring that they are not tightened against the flat of the D shaft. The pulley should not move as you tighten the grub screws.
7. Power the plotter off.
8. Reconnect the 4WD steppers.
9. Power the plotter on.

## Thoughts on drive position

Our aim is to drive a belt somewhere in the middle so that we have equal lengths on either side. A long belt is going to be more prone to vibration.

Below is a diagram showing the middle of the belt at different extents.

The red line shows the range and the red arrow shows the middle of the range. This is the ideal position for the driven pulley. We are constrained by putting the motor in a corner - luckily, a corner is not far away.

For 4-wheel-drive we would want to position motors at either end of the range.

![V2 central drive](./../images/drivePosition.png)

