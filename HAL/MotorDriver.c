/*
 * MotorDriver.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Mohamed
 */


#include "DcMotor.h"
#include "../MCAL/timer.h"
#include "../HAL/leds.h"
#include "../MCAL/macros.h"

bool goesForward = FALSE;

void Driver(){
	Motor_Init();
	led_system_init();
}

void forward(){
	if(!goesForward){
		goesForward = TRUE;
		turn_ForwardLEDS_on();
		Motor1_Rot(Clkw);
		Motor2_Rot(Clkw);
	}

}

void backward(){
	goesForward = FALSE;
	Motor1_Rot(A_Clkw);
	Motor2_Rot(A_Clkw);
	turn_BackwardLEDS_on();
}

void left(){
	turn_LeftLED_on();
	Motor1_Rot(Clkw);
	Motor2_Rot(A_Clkw);
}

void right(){
	turn_RightLED_on();
	Motor1_Rot(A_Clkw);
	Motor2_Rot(Clkw);
}

void stop(){
	Motor1_Rot(Stop);
	Motor2_Rot(Stop);
	turn_BackwardLEDS_off();
	turn_ForwardLEDS_off();
	turn_LeftLED_off();
	turn_RightLED_off();
	turn_LeftSensorLED_off();
	turn_RightSensorLED_off();
}


void speed(u8 spd){
	T0_PWM(spd);
}
