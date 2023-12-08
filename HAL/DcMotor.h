/*
 * DcMotor.h
 *
 *  Created on: Oct 9, 2022
 *      Author: abdoa
 */

#ifndef GPIO_DCMOTOR_H_
#define GPIO_DCMOTOR_H_

#include"../MCAL/macros.h"


#define Motor1_PORT		H
#define Motor1_Pin1		PIN3
#define Motor1_Pin2		PIN4
#define Motor2_PORT		H
#define Motor2_Pin1		PIN5
#define Motor2_Pin2		PIN6


typedef enum {
	Clkw,A_Clkw,Stop
}M_state;



void Motor_Init();


void Motor1_Rot(M_state st);


void Motor2_Rot(M_state st);


#endif /* GPIO_DCMOTOR_H_ */
