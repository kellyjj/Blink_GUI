/*
 * i2cController.c
 * 
 *   this file, will be used for a library on the i2c controller I will have to 
 *  	use for my project.  
 * 
 * 		will have to spawn some threads.  this has to be real time
 * 
 */


#include "i2cController.h"
#include <string.h>


GtkEntry 	*EnteredDelay;
GtkToggleButton *TurnOffLed;

int ControllerPinBase = 100;
int ControllerMemAddress = 0x20;  /* this is the base address for the controller to exist */
/*  these are the bits we will flip to controll the circuits 
 *   they start off with pin 22 go up to pin 28 (gpa7),  which maps to gpa0 in wiring pi.  
 */
int GPA0 = 100;  
int GPA1 = 101;
int GPA2 = 102;
int GPA4 = 103;

/* turn off or on the bit */
int OFF = 0;
int ON = 1;

int blink_delay = 100;  /* how long we going ot wait */

void *BlinkTheLEDS()
{
	int currentDelay =100;
	int cnt = 0;
	
	
	do
	{
		const char *chardelay = gtk_entry_get_text(EnteredDelay);
		//const char *chardelay = "200";
		
		sscanf(chardelay,"%d",&currentDelay);
		
		if (gtk_toggle_button_get_active (TurnOffLed))
		{
	
			if ((cnt % 2)==0)
			{
				digitalWrite(GPA0,ON);
				delay(currentDelay);
				
			}
			else 
			{
				digitalWrite(GPA0,OFF);
				delay(currentDelay);
			}
		
			cnt++;
		}
		else 
		{
			digitalWrite(GPA0,OFF);
		}
			
	} while (currentDelay >0);
	
	digitalWrite(GPA0,OFF);

	
	return NULL;
}

void i2c_init(GtkEntry *delayBox,GtkToggleButton *thebutton)
{
	/*  this will be used to init the i2c controller.
	 */
	 
	 EnteredDelay = delayBox;
	 TurnOffLed = thebutton;
	 
	 if (wiringPiSetup()>-1)
	 {
		mcp23017Setup(ControllerPinBase,ControllerMemAddress);  /* this sets up the serial controller our config */
		
		/* turning our pins to output */
		pinMode(GPA2,OUTPUT);

		/* Make sure theyre all turned off */
		digitalWrite(GPA0,OFF);
			
		/* Create worker thread */
		pthread_create(&BlinkThreads,NULL,BlinkTheLEDS,"processing...");
		
	 }
}
