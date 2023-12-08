/*
 * timer.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_TIMER_H_
#define BASE_TIMER_H_

#include "macros.h"


void T0_init();
void T0_PWM(u8 duty_cycle);

void T3_Init();
void T3_duty(u16 x);
#endif /* BASE_TIMER_H_ */
