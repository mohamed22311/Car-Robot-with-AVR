/*
 * LF_mood.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mohamed
 */

#include "../MCAL/GPIO.h"
#include "../MCAL/macros.h"
#include "../HAL/MotorDriver.h"
#include "../HAL/ir_sensor.h"

u8 IR_right_val = 0;
u8 IR_left_val  = 0;

lf_car_mood(){
	IR_right_val = IR_right_read();
	IR_left_val = IR_left_read();

	//If none of the sensors detects black line, then go straight
	  if (IR_right_val == LOW && IR_left_val == LOW)
	  {
	    forward();
	  }
	  //If right sensor detects black line, then turn right
	  else if (IR_right_val == HIGH && IR_left_val == LOW )
	  {
	      right();
	  }
	  //If left sensor detects black line, then turn left
	  else if (IR_right_val == LOW && IR_left_val == HIGH )
	  {
	      left();
	  }
	  //If both the sensors detect black line, then stop
	  else
	  {
	    stop();
	  }
}
