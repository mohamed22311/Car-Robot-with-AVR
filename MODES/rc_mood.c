/*
 * rc_mood.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mohamed
 */
#include "../MCAL/macros.h"
#include "../HAL/bluetooth.h"

void rc_car_mode(){
	u8 input;
	input=BT_RX();
	switch(input){
	case 'F':
		forward();
		break;
	case 'B':
		backward();
		break;
	case 'L':
		left();
		break;
	case 'R':
		right();
		break;
	case 'G':
		left();
		_delay_ms(50);
		forward();
		_delay_ms(50);
		break;
	case 'I':
		right();
		_delay_ms(50);
		forward();
		_delay_ms(50);
		break;
	case 'H':
		left();
		_delay_ms(50);
		backward();
		_delay_ms(50);
		break;
	case 'J':
		right();
		_delay_ms(50);
		backward();
		_delay_ms(50);
		break;
	case 'S':
		stop();
		break;
	default:
		stop();
		break;

	}
}



