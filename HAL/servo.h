/*
 * servo.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_SERVO_H_
#define BASE_SERVO_H_
#include "../MCAL/macros.h"
#define Startup 19999
#define FAST_PWM_ICR1 14
#define FAST_PWM_OCR1A 15
#define Normal 0
#define Toggle 1
#define CLEAR 2
#define SET 3

void Servo_Init();
void Servo_SetAngle(u16 i);

void Servo_turn_right();
void Servo_start_point();
void Servo_turn_left();

#endif /* BASE_SERVO_H_ */
