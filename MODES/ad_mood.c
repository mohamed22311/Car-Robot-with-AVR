/*
 * ad_mood.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mohamed
 */

#include "../HAL/us_sensor.h"
#include "../HAL/MotorDriver.h"
#include "../HAL/servo.h"

u8 distance       = 100;
u8 distance_right = 0;
u8 distance_left  = 0;


void ad_car_mode(){
	distance_right = 0;
	distance_left  = 0;

	if(distance <= 45){
		stop();
		_delay_ms(300);
		backward();
		_delay_ms(400);
		stop();
		_delay_ms(300);
		distance_right = look_right();
		_delay_ms(300);
		distance_left = look_left();
		_delay_ms(300);

		if (distance >= distance_left){
			right();
			_delay_ms(250);
		    stop();
		}else{
		     left();
		    _delay_ms(250);
		    stop();
		}
	}else{
		forward();
	}

	distance = Ultrasonic_readDistance();

}




u8 look_right(){
	turn_RightSensorLED_on();
	_delay_ms(200);
	turn_RightSensorLED_off();

	Servo_turn_right()();
	_delay_ms(200);
	int distance = Ultrasonic_readDistance();
	_delay_ms(100);
	Servo_start_point();
	return distance;
}



u8 look_left(){

   turn_LeftSensorLED_on()//Robot Lk
   _delay_ms(200);
   turn_LeftSensorLED_off()//Robot Lk

  Servo_turn_left();
  _delay_ms(200);
  int distance = Ultrasonic_readDistance();
  _delay_ms(100);
  Servo_start_point();
  return distance;
}
