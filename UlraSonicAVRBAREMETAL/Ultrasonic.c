/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrhman.H ahmed
 */

#include"Ulrasonic.h"
#include"gpio.h"
#include<util/delay.h>
#include "std_types.h"
#include"icu.h"

static uint8 EdgeCounts =0;
static uint16 High_Time=0;


void Ultasonic_init(void){
	GPIO_setupPinDirection(TRIGGER_PORT,TRIGGER_PIN,PIN_OUTPUT);
	ICU_ConfigType config = {F_CPU_8,RAISING};
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	ICU_init(&config);

}
void Ultrasonic_Trigger(void) {
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void) {
	Ultrasonic_Trigger();
	while(1) {
		if(EdgeCounts == 2) {
			EdgeCounts =0;
			return (uint16)((float)High_Time*(0.017));
		}
	}

}

void Ultrasonic_edgeProcessing(void) {
	EdgeCounts++;
	if(EdgeCounts == 1) {
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}

	else if (EdgeCounts == 2 ) {
		High_Time = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
	}
}
