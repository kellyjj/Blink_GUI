# Blink_GUI
some glade code for controling leds from raspberry
use at your own risk.  this is the start for my start nx-01 model project.   use the code if you want, at your own risk

this code is so I can have a example of how to control a mpc2017 from my raspberry pi 3.
this makes use of the wiring PI library.  
this makes use of the gtk library.
this makes use of the i2ccontroller library.

this is the build command gcc -Wall -o "%e" "%f" "i2cController.c"  "pi_gpio.c"  $(pkg-config --cflags --libs gtk+-3.0) -rdynamic -lwiringPi -lpthread

this is the compile command  gcc -Wall -c "%f" $(pkg-config --cflags --libs gtk+-3.0) -rdynamic  -lwiringPi -lpthread

this was written in geany IDE

the files are:

Blink_GUI.glade  (this is the xml file for the windows)
main.c            this is the main function.  where all the fun starts
i2cController.c   this is the source file for the code that interacts with tmy mpc2017 through the i2c pins on raspberry pi
i2cController.h   this is the header file for the i2ccontroller source code.
pi_gpio.c         this is the source file for the normal gpio pins.  may not get filled out, since I might controll everything
                  through the mpc2017 
