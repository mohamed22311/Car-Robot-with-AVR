/*
 * main.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mohamed
 */

#include "APP/app.h"
int main(){
	car_init();
	while(1)	mood_select();
	return 0;
}
