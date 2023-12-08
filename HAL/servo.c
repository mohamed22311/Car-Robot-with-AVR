/*
 * servo.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */
#include "servo.h"
#include "../MCAL/timer.h"
#include "../MCAL/macros.h"
#include "../MCAL/GPIO.h"
#include <util/delay.h>
#include <avr/io.h>
void Servo_Init(){
		T3_Init();
}
void Servo_SetAngle(u16 i){

	T3_duty(i); //
}
// 245 -90
// 500 90
// 0 375
