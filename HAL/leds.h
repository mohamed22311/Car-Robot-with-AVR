/*
 * leds.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Mohamed
 */

#ifndef HAL_LEDS_H_
#define HAL_LEDS_H_

#include "../MCAL/macros.h"
#include "../MCAL/GPIO.h"


#define Led_port H
#define ForwardLEDS_pin 0
#define BackwardLEDS_pin 1
#define LeftLED_pin 2
#define RightLED_pin 3
#define LeftSensorLED_pin 4
#define RightSensorLED_pin 5

void led_system_init();
void turn_ForwardLEDS_on();
void turn_ForwardLEDS_off();
void turn_BackwardLEDS_on();
void turn_BackwardLEDS_off();
void turn_LeftLED_on();
void turn_LeftLED_off();
void turn_RightLED_on();
void turn_RightLED_off();
void turn_LeftSensorLED_on();
void turn_LeftSensorLED_off();
void turn_RightSensorLED_on();
void turn_RightSensorLED_off();
#endif /* HAL_LEDS_H_ */
