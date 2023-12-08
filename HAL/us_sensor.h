/*
 * Ultrasonic_sensor _HC-SR04.h
 *
 *  Created on: Oct 18, 2022
 *      Author: abdoa
 */

#ifndef ULTRASONIC_SENSOR__HC_SR04_H_
#define ULTRASONIC_SENSOR__HC_SR04_H_
#include "../MCAL/macros.h"

#define Trigger_port_id D
#define Trigger_pin_id PIN5



void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
u16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_SENSOR__HC_SR04_H_ */
