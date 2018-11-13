/*
 * prosjektopg3.cpp
 *
 * Created: 15.10.2018 09.01.02
 * Author : toreg
 */ 

#include <avr/io.h>


int main(void)
{
	//Setter hele B registeret som output
	DDRB = 0xFF;
	//Setter hele B registeret til lav
	PORTD = 0x00;
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

