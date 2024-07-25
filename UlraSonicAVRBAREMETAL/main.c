/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrhman.H ahmed
 */
#include "lcd.h"
#include"Ulrasonic.h"
#include"std_types.h"
#include <avr/io.h>

int main() {
		uint16 Distance ;
		SREG |= (1<<7);  //Enable global INT
		LCD_init();
		Ultasonic_init();
		LCD_displayString("Distance=    cm");
		while(1) {
			Distance = Ultrasonic_readDistance();

					/* Display the distance value every time at same position */
					LCD_moveCursor(0,10);
					if(Distance >= 100)
					{
						LCD_intgerToString(Distance);
					}
					else
					{
						LCD_intgerToString(Distance);
						/* In case the digital value is two or one digits print space in the next digit place */
						LCD_displayCharacter(' ');
					}

		}
		return 0 ;
}
