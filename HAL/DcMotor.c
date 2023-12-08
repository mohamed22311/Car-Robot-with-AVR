/*
 * DcMotor.c
 *
 *  Created on: Oct 9, 2022
 *      Author: abdoa
 */

#include"../MCAL/macros.h"
#include "DcMotor.h"
#include "../MCAL/GPIO.h"
#include "../MCAL/timer.h"

void Motor_Init()
{
	pinMode(Motor1_PORT, Motor1_Pin1, OUTPUT);
	pinMode(Motor1_PORT, Motor1_Pin2, OUTPUT);
	pinMode(Motor2_PORT, Motor2_Pin1, OUTPUT);
	pinMode(Motor2_PORT, Motor2_Pin2, OUTPUT);

	pinWrite(Motor1_PORT, Motor1_Pin1, LOW);
	pinWrite(Motor1_PORT, Motor1_Pin2, LOW);
	pinWrite(Motor2_PORT, Motor2_Pin1, LOW);
	pinWrite(Motor2_PORT, Motor2_Pin2, LOW);

	T0_init();
	T0_PWM(255);
}

void Motor1_Rot(M_state st){

	switch(st)
	{
	case Clkw:
		pinWrite(Motor1_PORT, Motor1_Pin1, LOW);
		pinWrite(Motor1_PORT, Motor1_Pin2, HIGH);
		break;
	case A_Clkw:
		pinWrite(Motor1_PORT, Motor1_Pin1, HIGH);
		pinWrite(Motor1_PORT, Motor1_Pin2, LOW);
		break;
	case Stop:
		pinWrite(Motor1_PORT, Motor1_Pin1, LOW);
		pinWrite(Motor1_PORT, Motor1_Pin2, LOW);
		break;
	}
}

void Motor2_Rot(M_state st){

	switch(st)
	{
	case Clkw:
		pinWrite(Motor2_PORT, Motor2_Pin1, LOW);
		pinWrite(Motor2_PORT, Motor2_Pin2, HIGH);
		break;
	case A_Clkw:
		pinWrite(Motor2_PORT, Motor2_Pin1, HIGH);
		pinWrite(Motor2_PORT, Motor2_Pin2, LOW);
		break;
	case Stop:
		pinWrite(Motor2_PORT, Motor2_Pin1, LOW);
		pinWrite(Motor2_PORT, Motor2_Pin2, LOW);
		break;
	}
}



