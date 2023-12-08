/*
 * timer.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */


#include <avr/io.h>
#include "macros.h"
#include "GPIO.h"
#include "timer.h"


void T0_init(){
	OCR0A  = 0;
	DDRB   = DDRB | (1<<PB7);
	TCCR0A = (1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
	TCCR0B = (1<<CS01) | (1<<WGM02);
}

void T0_PWM(u8 duty_cycle){
	OCR0A = (u8)(((u32)(duty_cycle*255))/100);
}


void T3_Init(){
	pinMode(B,0,OUTPUT);
	TCCR3A =  (1<<COM3A1);
	TCCR3B = (1<<WGM32) | (1<<CS30) | (1<<CS31);
	OCR3A = 11;
	TCNT3 = 0;
}

// 1 tick = 0.5 us
// 1 ms --> -90        1600
// 1.5ms --> 0         3000
// 2ms --> 90          5250

// range between 1900 to 5250
void angle(void){
	TCNT3=0;
	while(!( TIFR3 & (1<<OCF3A)));
	TIFR3 |= (1<<OCF3A);
	TOGGLE_BIT(PORTB,0);
}
void T3_duty(u16 x){
	OCR3A = x;
	angle();
	angle();
}


