/*
 * bluetooth.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */


#include "../MCAL/macros.h"
#include "bluetooth.h"
#include "../MCAL/uart.h"


void BT_Init(){
	UART_init(9600,uart0);
}
u8  BT_RX(){
	return UART_recieveByte(uart0);
}
void BT_TX(u8 data){
	UART_sendByte(data,uart0);
}
void BT_TX_string (u8 data[]){
	UART_sendString(data,uart0);
}
