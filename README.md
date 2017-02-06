# La Fortuna AVR Board #

This is my working repo of gathered libraries and learning sample code for COMP2215 - Computer Systems II - at The University of Southampton (ECS).

### Directories ###
* `lib`: Libraries/Helpers for using various hardware on the La Fortuna.
* `blink`: LED blink.
* `lcd_helloworld`: Hello world displaying text and rectangles on screen.

### Building and Uploading ###
From Linux, running either `make` or `sudo make` (which uses the included makefile) from within the project directory will compile and upload to the La Fortuna if you have the cross-compilation toolchain installed correctly.
