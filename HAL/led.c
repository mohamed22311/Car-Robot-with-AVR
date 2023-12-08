/*
 * led.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Mohamed
 */
#include "../MCAL/macros.h"
#include "leds.h"
#include <avr/io.h>

void led_system_init(){
	pinMode(Led_port,ForwardLEDS_pin,OUTPUT);
	pinMode(Led_port,BackwardLEDS_pin,OUTPUT);
	pinMode(Led_port,LeftLED_pin,OUTPUT);
	pinMode(Led_port,RightLED_pin,OUTPUT);
	pinMode(Led_port,LeftSensorLED_pin,OUTPUT);
	pinMode(Led_port,RightSensorLED_pin,OUTPUT);
}

void turn_ForwardLEDS_on(){
	pinWrite(Led_port,ForwardLEDS_pin,HIGH);
}
void turn_ForwardLEDS_off(){
	pinWrite(Led_port,ForwardLEDS_pin,LOW);
}
void turn_BackwardLEDS_on(){
	pinWrite(Led_port,BackwardLEDS_pin,HIGH);
}
void turn_BackwardLEDS_off(){
	pinWrite(Led_port,BackwardLEDS_pin,LOW);
}
void turn_LeftLED_on(){
	pinWrite(Led_port,LeftLED_pin,HIGH);
}
void turn_LeftLED_off(){
	pinWrite(Led_port,LeftLED_pin,LOW);
}
void turn_RightLED_on(){
	pinWrite(Led_port,RightLED_pin,HIGH);
}
void turn_RightLED_off(){
	pinWrite(Led_port,RightLED_pin,LOW);
}
void turn_LeftSensorLED_on(){
	pinWrite(Led_port,LeftSensorLED_pin,HIGH);
}
void turn_LeftSensorLED_off(){
	pinWrite(Led_port,LeftSensorLED_pin,LOW);
}
void turn_RightSensorLED_on(){
	pinWrite(Led_port,RightSensorLED_pin,HIGH);
}
void turn_RightSensorLED_off(){
	pinWrite(Led_port,RightSensorLED_pin,LOW);
}
