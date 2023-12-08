/*
 * ICU.c
 *
 *  Created on: Oct 18, 2022
 *      Author: abdoa
 */
#include <avr/interrupt.h>
#include "macros.h"
#include "ICU.h"
#include "avr/io.h"
#include "GPIO.h"

static volatile void(*ptr)(void) = NULL_PTR;

void icu_init(const Icu_Config*config_ptr)
{

	pinMode(D, PIN4, INPUT);//icu pin

	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1C = 0;

	SET_BIT(TCCR1C,FOC1A);
	SET_BIT(TCCR1C,FOC1B);
	SET_BIT(TCCR1C,FOC1C);

	switch(config_ptr->edge)        /*configure the edge to be detected as in the input structure */
	{
		case falling:                 //already cleared/
			CLR_BIT(TCCR1B,ICES1);
			break;
		case rising:                  //setting the bit/
			SET_BIT(TCCR1B,ICES1);
			break;
	}
	switch(config_ptr->clock_presc)      /*configure the clock and prescaler as in the input structure*/
	{
	    case NO_Clock:
	    	CLR_BIT(TCCR1B,CS10);
	    	CLR_BIT(TCCR1B,CS11);
	    	CLR_BIT(TCCR1B,CS12);
			break;
		case F_1:
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
			break;
		case F_8:
			CLR_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
			break;
		case F_64:
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
			break;
		case F_256:
			CLR_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);
			break;
		case F_1024:
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);
			break;
	}
	                      /*set initial value for timer and ICR1 regs.*/
  TCNT1 = 0;
  ICR1 = 0;
  TIMSK1=0;
  SET_BIT(TIMSK1,ICIE1);      /*module int enabled*/

}
/*void ICU_init(ICU_config *config){
	//TCCR1A=(1<<FOC1A)|(1<<FOC1B);
	//TCCR1C=(1<<FOC1A)|(1<<FOC1B)|(1<<FOC1C);
	SREG &= ~(1<<SREG_I);
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1C = 0;
	TCCR1B = (TCCR1B & 0xF8) | (config->clock_select);
	TCCR1B = (TCCR1B & 0xBF) | ((config->input_edge)<<6);
	pinMode(D, PIN4, INPUT);//icu pin
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK1 |= (1<<ICIE1) | (1<<TOIE1);
	SREG |= (1<<SREG_I);
}*/

void icu_edgeType(const Edge_Type edge)
{
   TCCR1B = (TCCR1B & 0xBF) | (edge<<6);   /*first section for masking the reg with 1 except the bit 6 with zero*/
}


void icu_setCallBack(void(*ptr_func)(void))   /*we save the address of the call back function which is passed to this func*/
{
    ptr = ptr_func;
}


u16 icu_get_Captured_value(void)
{
	return ICR1;              /*return the value stored in timer reg when edge is captured*/
}

void icu_clearTimer(void)
{
	TCNT1 = 0;
}

void icu_DEinit(void)          /*to disable the icu driver*/
{
	TCCR1A =0;
	TCCR1B =0;
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK1 &= ~(1<<ICIE1);
}


ISR (TIMER1_CAPT_vect)
{
	if(ptr != NULL_PTR)  /*if the pointer points to a function enter the cond*/
	{
		ptr();        /*we call the call back function we point at using the pointer*/
	}
}
