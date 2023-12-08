/*
 * ir_sensor.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Mohamed
 */

#ifndef HAL_IR_SENSOR_H_
#define HAL_IR_SENSOR_H_

#define IR_sensors_port D
#define IR_right_pin 0
#define IR_left_pin 1

void IR_sensors_init();

u8 IR_right_read();
u8 IR_left_read();

#endif /* HAL_IR_SENSOR_H_ */
