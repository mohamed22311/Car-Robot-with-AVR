/*
 * GPIO.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#include "GPIO.h"
#include <avr/io.h>

/*
 * Description :
 * Setup the dir of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void pinMode(u8 port_num, u8 pin_num, PinDir dir){
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	*/
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)){}
	else{
		/* Setup the pin dir as required */
		switch(port_num){
			case (A | a):
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRA,pin_num);
				}
				else
				{
					CLR_BIT(DDRA,pin_num);
				}
				break;
			case (B | b) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRB,pin_num);
				}
				else
				{
					CLR_BIT(DDRB,pin_num);
				}
				break;
			case (C | c) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRC,pin_num);
				}
				else
				{
					CLR_BIT(DDRC,pin_num);
				}
				break;
			case (D | d) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRD,pin_num);
				}
				else
				{
					CLR_BIT(DDRD,pin_num);
				}
				break;
			case (E | e) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRE,pin_num);
				}
				else
				{
					CLR_BIT(DDRE,pin_num);
				}
				break;

			case (F | f):
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRF,pin_num);
				}
				else
				{
					CLR_BIT(DDRF,pin_num);
				}
				break;
			case (G | g) :
				if(pin_num>5){
					break;
				}
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRG,pin_num);
				}
				else
				{
					CLR_BIT(DDRG,pin_num);
				}
				break;
			case (H | h) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRH,pin_num);
				}
				else
				{
					CLR_BIT(DDRH,pin_num);
				}
				break;
			case (J | j) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRJ,pin_num);
				}
				else
				{
					CLR_BIT(DDRJ,pin_num);
				}
				break;
			case (K | k) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRK,pin_num);
				}
				else
				{
					CLR_BIT(DDRK,pin_num);
				}
				break;
			case (L | l) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRL,pin_num);
				}
				else
				{
					CLR_BIT(DDRL,pin_num);
				}
							break;
			}
		}

}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void pinWrite(u8 port_num, u8 pin_num, u8 value){
	/*
		 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
		 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
		 * In this case the input is not valid port/pin number
		 */
		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)){}
		else
		{
			/* Write the pin value as required */
			switch(port_num)
			{
			case (A | a):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTA,pin_num);
				}
				else
				{
					CLR_BIT(PORTA,pin_num);
				}
				break;
			case (B | b):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTB,pin_num);
				}
				else
				{
					CLR_BIT(PORTB,pin_num);
				}
				break;
			case (C | c):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTC,pin_num);
				}
				else
				{
					CLR_BIT(PORTC,pin_num);
				}
				break;
			case (D | d):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTD,pin_num);
				}
				else
				{
					CLR_BIT(PORTD,pin_num);
				}
				break;
			case (E | e):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTE,pin_num);
				}
				else
				{
					CLR_BIT(PORTE,pin_num);
				}
				break;
			case (F | f):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTF,pin_num);
				}
				else
				{
					CLR_BIT(PORTF,pin_num);
				}
				break;
			case (G | g):
				if(pin_num>5){break;}
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTG,pin_num);
				}
				else
				{
					CLR_BIT(PORTG,pin_num);
				}
				break;
			case (H | h):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTH,pin_num);
				}
				else
				{
					CLR_BIT(PORTH,pin_num);
				}
				break;
			case (J | j):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTJ,pin_num);
				}
				else
				{
					CLR_BIT(PORTJ,pin_num);
				}
				break;
			case (K | k):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTK,pin_num);
				}
				else
				{
					CLR_BIT(PORTK,pin_num);
				}
				break;
			case (L | l):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTL,pin_num);
				}
				else
				{
					CLR_BIT(PORTL,pin_num);
				}
				break;
			}
		}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 pinRead(u8 port_num, u8 pin_num){
		u8 pin_value = LOW;
		/*
		 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
		 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
		 * In this case the input is not valid port/pin number
		 */
		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)){}
		else
		{
			/* Read the pin value as required */
			switch(port_num)
			{
			case (A | a):
				if(BIT_IS_SET(PINA,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (B | b):
				if(BIT_IS_SET(PINB,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (C | c):
				if(BIT_IS_SET(PINC,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (D | d):
				if(BIT_IS_SET(PIND,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (E | e):
				if(BIT_IS_SET(PINE,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (F | f):
				if(BIT_IS_SET(PINF,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (G | g):
				if(BIT_IS_SET(PING,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (H | h):
				if(BIT_IS_SET(PINH,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (J | j):
				if(BIT_IS_SET(PINJ,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (K | k):
				if(BIT_IS_SET(PINK,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (L | l ):
				if(BIT_IS_SET(PINL,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			}
		}

		return pin_value;

}

/*
 * Description :
 * Setup the dir of the required port all pins input/output.
 * If the dir value is PORT_INPUT all pins in this port should be input pins.
 * If the dir value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void portMode(u8 port_num, u8 dir){
	/*
		 * Check if the input number is greater than NUM_OF_PORTS value.
		 * In this case the input is not valid port number
		 */
		if(port_num >= NUM_OF_PORTS){}
		else
		{
			/* Setup the port dir as required */
			switch(port_num)
			{
			case (A | a):
				DDRA = dir;
				break;
			case (B | b):
				DDRB = dir;
				break;
			case (C | c):
				DDRC = dir;
				break;
			case (D | d):
				DDRD = dir;
				break;
			case (E | e):
				DDRE = dir;
				break;
			case (F | f):
				DDRF = dir;
				break;
			case (G | g):
				DDRG = dir;
				break;
			case (H | h):
				DDRH = dir;
				break;
			case (J | j):
				DDRJ = dir;
				break;
			case (K | k):
				DDRK = dir;
				break;
			case (L | l):
				DDRL = dir;
				break;
			}
		}

}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void portWrite(u8 port_num, u8 value){
	/*
		 * Check if the input number is greater than NUM_OF_PORTS value.
		 * In this case the input is not valid port number
		 */
		if(port_num >= NUM_OF_PORTS){}
		else
		{
			/* Write the port value as required */
			switch(port_num)
			{
			case (A | a):
				PORTA = value;
				break;
			case (B | b):
				PORTB = value;
				break;
			case (C | c):
				PORTC = value;
				break;
			case (D | d):
				PORTD = value;
				break;
			case (E | e):
				PORTE = value;
				break;
			case (F | f):
				PORTF = value;
				break;
			case (G | g):
				PORTG = value;
				break;
			case (H | h):
				PORTH = value;
				break;
			case (J | j):
				PORTJ = value;
				break;
			case (K | k):
				PORTK = value;
				break;
			case (L | l):
				PORTL = value;
				break;

			}
		}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 portRead(u8 port_num){
	u8 value = LOW;
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS){}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case (A | a):
			value = PINA;
			break;
		case (B | b):
			value = PINB;
			break;
		case (C | c):
			value = PINC;
			break;
		case (D | d):
			value = PIND;
			break;
		case (E | e):
			value = PINE;
			break;
		case (F | f):
			value = PINF;
			break;
		case (G | g):
			value = PING;
			break;
		case (H | h):
			value = PINH;
			break;
		case (J | j):
			value = PINJ;
			break;
		case (K | k):
			value = PINK;
			break;
		case (L | l):
			value = PINL;
			break;
		}
	}

	return value;
}

