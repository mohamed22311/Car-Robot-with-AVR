/*
 * Ultrasonic_sensor _HC-SR04.c
 *
 *  Created on: Oct 18, 2022
 *      Author: abdoa
 */
#include "us_sensor.h"
#include <avr/io.h>
#include "../MCAL/macros.h"
#include "../MCAL/ICU.h"
#include "../MCAL/GPIO.h"
#include "util/delay.h"

/****************************************definitions*******************************/
static Icu_Config config={rising,F_8};                           /*to configure the icu module as you like!!*/
volatile static u16 timer_val =0;

/****************************************Prototypes*********************************/
void Ultrasonic_init(void)
{
	icu_init(&config);                                   /*initializing the icu dynamically by passing a structure to it*/
	icu_setCallBack(Ultrasonic_edgeProcessing);         /*when the isr is excuted it calls (Ultrasonic_edgeProcessing) function*/
	pinMode(Trigger_port_id,Trigger_pin_id,OUTPUT);
}

u16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	return (((timer_val*0.017)+1)/2)+1;    /*calculating the distance = speed of sound in cm x time in seconds=(34000*(timerval*10^-6))/2*/
}                                  /*i added the +1 to correct the value displayed on lcd as it displays the no to its nearest floor*/

void Ultrasonic_Trigger(void)                     /*function to send trigger pulse to ultrasonic*/
{
	pinWrite(Trigger_port_id,Trigger_pin_id,HIGH);
	_delay_us(200);                                      /*this number made the ultrasonic work correctly*/
	pinWrite(Trigger_port_id,Trigger_pin_id,LOW);
}
/*void Ultrasonic_edgeProcessing(){
	icu_counter++;
	if(icu_counter==1){
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(falling);
	}
	else if(icu_counter==2){
		icu_timer_value=ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(rising);

	}
}*/

void Ultrasonic_edgeProcessing(void)        /*function to save the high time of the pulse on the echo pin to be used in calculating the distance*/
{
	static u8 flag =0;	           /*local variable but keeps its value stored to indicate which edge is detected*/
	if(flag==0)                        /*rising edge is captured*/
	{
	    icu_clearTimer();
	    icu_edgeType(falling);
	    flag=1;
	}
	else if(flag == 1)                  /*falling edge is captured*/
	{
		timer_val = icu_get_Captured_value();             /*to store the high time elapsed between rising edge and falling edge */
		flag =0;
		icu_clearTimer();
	    icu_edgeType(rising);
	}

}

