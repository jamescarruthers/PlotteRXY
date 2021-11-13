# PlotterXY
A machine designed to be your second plotter after an AxiDraw or vintage plotter.

# Why?
I really enjoyed the flexibility of my AxiDraw, and the speed of my Roland DPX-2200. I wanted something of a halfway house, with the pen flexibility of the AxiDraw and the speed and size of the Roland.

I set myself a few design requirements; enclosed inside a frame, scalable to any size including "massive" and a solenoid for fast pen lift.

I chose CoreXY pretty much just because I thought it was cool. It probably limits the scalability a bit as I expect belt droop might be an issue for _really_ huge plotters.

It uses an off-the-shelf FYSETC E4 controller board, which also has the benefit of being wifi enabled and has a web GUI built in.

The toolchain is fairly simple; SVG ingested in to VPYPE and it's G-code plugin. The G-code is uploaded through the web browser.

# How?

The build is fairly simple, you'll need access to a 3D printer to print off the various parts. Most of the parts are symetrical, so it's a fairly simple list of parts.

The rest of the parts you'll need are here; https://docs.google.com/spreadsheets/d/1bjWigQsAcE3DGmHS4qicfL3H79G1RvEPnRx3VYNnScU/

There is a build guide in the hardware folder.
