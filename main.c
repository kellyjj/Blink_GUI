/*
 * main.c
 * 
 * Copyright 2017  <pi@EndWorld>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 * 
 * this program will be used to test controlling circuts with my c code on my pi
 * the code will be controled through a form.  this will be important for when the model comes together
 * 
 * the main function will be where I spawn the form.
 * 
 * gcc -Wall -o "%e" "%f" $(pkg-config --cflags --libs gtk+-3.0) -rdynamic -lwiringPi 
 * 
 */


#include <stdio.h>
#include <wiringPi.h>
#include <mcp23017.h>
#include <gtk/gtk.h> 
#include "i2cController.h"





int main(int argc, char **argv)
{
	GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkEntry 		*TheBlinkDelayBox;
	GtkToggleButton *TheButton;
    
	gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "Blink_GUI.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);
 
	TheBlinkDelayBox = GTK_ENTRY(gtk_builder_get_object(builder, "BlinkDelay"));
	TheButton = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "Led_OnOffBtn"));
	
	i2c_init(TheBlinkDelayBox,TheButton);
	
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();  
    
    
    
    gtk_main_quit();
    
	return 0;
}

