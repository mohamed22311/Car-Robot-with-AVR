 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "macros.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
#define uart0 0
#define uart1 1
#define uart2 2
#define uart3 3
/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(u32 baud_rate,u8 uart_no);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const u8 data, u8 uart_no);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
u8 UART_recieveByte(u8 uart_no);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const u8 *Str, u8 uart_no);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(u8 *Str, u8 uart_no); // Receive until #

#endif /* UART_H_ */
