/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrhman.H ahmed
 */



#ifndef LCD_H_
#define LCD_H_


#include"std_types.h"
#include"gpio.h"

#define TRIGGER_PORT PORTB_ID
#define TRIGGER_PIN PIN5_ID

#define ECHO_PORT PORTD_ID
#define ECHO_PIN PIN6_ID

void Ultasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);


#endif
