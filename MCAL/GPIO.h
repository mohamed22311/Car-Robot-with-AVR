/*
 * GPIO.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_GPIO_H_
#define BASE_GPIO_H_

#include"macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           11
#define NUM_OF_PINS_PER_PORT   8

#define A               0
#define B               1
#define C               2
#define D               3
#define E               4
#define F               5
#define G               6
#define H               7
#define J               8
#define K               9
#define L               10

#define a               0
#define b               1
#define c               2
#define d               3
#define e               4
#define f               5
#define g               6
#define h               7
#define j               8
#define k               9
#define l               10


#define PIN0                0
#define PIN1                1
#define PIN2                2
#define PIN3                3
#define PIN4                4
#define PIN5                5
#define PIN6                6
#define PIN7                7


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	INPUT,OUTPUT
}PinDir;

typedef enum
{
	PINPUT,POUTPUT = 0xFF
}PortDir;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void pinMode(u8 port_num, u8 pin_num, PinDir dir);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void pinWrite(u8 port_num, u8 pin_num, u8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 pinRead(u8 port_num, u8 pin_num);

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void portMode(u8 port_num, u8 dir);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void portWrite(u8 port_num, u8 value);

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 portRead(u8 port_num);

#endif /* BASE_GPIO_H_ */
