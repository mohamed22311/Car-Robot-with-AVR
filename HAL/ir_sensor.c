/*
 * ir_sensor.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Mohamed
 */

#include "../MCAL/macros.h"
#include "../MCAL/GPIO.h"
#include "ir_sensor.h"

void IR_sensors_init(){
	pinMode(IR_sensors_port,IR_right_pin,INPUT);
	pinMode(IR_sensors_port,IR_left_pin,INPUT);
}

u8 IR_right_read(){
	return pinRead(IR_sensors_port,IR_right_pin);
}
u8 IR_left_read(){
	return pinRead(IR_sensors_port,IR_left_pin);
}
