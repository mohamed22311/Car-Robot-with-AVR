/*
 * app.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mohamed
 */

#include "../MCAL/macros.h"
#include "../MODES/rc_mood.h"
#include "../MODES/ad_mood.h"
#include "../MODES/LF_mood.h"
#include "../HAL/bluetooth.h"
#include "../HAL/MotorDriver.h"
#include "../HAL/servo.h"
#include "../HAL/us_sensor.h"
#include "../HAL/leds.h"
#include "../HAL/ir_sensor.h"

void car_init(){
	BT_Init();
	Ultrasonic_init();
	Servo_Init();
	Driver();
	IR_sensors_init();
}

void mood_select(){
	u8 choice;
	choice = BT_RX();
	switch(choice){
		case '':
			while(BT_RX() != ''){
				rc_car_mode();
			}
			break;
		case '':
			while(BT_RX() != ''){
				ad_car_mode();
			}
			break;
		case '':
			while(BT_RX() != ''){

			}
			break;
		default:
			stop();
			break;
	}
}
