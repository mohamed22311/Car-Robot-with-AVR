/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "uart.h"
#include "avr/io.h" /* To use the UART Registers */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
without interrupts
8bit mode
u2x double speed
asynchronous
 */
void UART_init(u32 baud_rate, u8 uart_no )
{
	u16 ubrr_value = 0;
	switch(uart_no){

	case uart0:
		UCSR0A = (1<<U2X0);
		UCSR0B = (1<<RXEN0) | (1<<TXEN0);
		UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);

		ubrr_value = (u16)(((F_CPU / (baud_rate * 8UL))) - 1);
		/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
		UBRR0H = ubrr_value>>8;
		UBRR0L = ubrr_value;
		break;
	case uart1:
		UCSR1A = (1<<U2X1);
		UCSR1B = (1<<RXEN1) | (1<<TXEN1);
		UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);

		ubrr_value = (u16)(((F_CPU / (baud_rate * 8UL))) - 1);
		/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
		UBRR1H = ubrr_value>>8;
		UBRR1L = ubrr_value;
		break;
	case uart2:
		UCSR2A = (1<<U2X2);
		UCSR2B = (1<<RXEN2) | (1<<TXEN2);
		UCSR2C = (1<<UCSZ21) | (1<<UCSZ20);

		ubrr_value = (u16)(((F_CPU / (baud_rate * 8UL))) - 1);
		/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
		UBRR2H = ubrr_value>>8;
		UBRR2L = ubrr_value;
		break;
	case uart3:
		UCSR3A = (1<<U2X3);
		UCSR3B = (1<<RXEN3) | (1<<TXEN3);
		UCSR3C = (1<<UCSZ31) | (1<<UCSZ30);

		ubrr_value = (u16)(((F_CPU / (baud_rate * 8UL))) - 1);
		/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
		UBRR3H = ubrr_value>>8;
		UBRR3L = ubrr_value;
		break;
	}
}



void UART_sendByte(const u8 data, u8 uart_no)
{
	switch(uart_no){
	case uart0:
		while(BIT_IS_CLR(UCSR0A,UDRE0)){} // waiting for Data Register Empty to be empty
		UDR0 = data;
		break;
	case uart1:
		while(BIT_IS_CLR(UCSR1A,UDRE1)){} // waiting for Data Register Empty to be empty
		UDR1 = data;
		break;
	case uart2:
		while(BIT_IS_CLR(UCSR2A,UDRE2)){} // waiting for Data Register Empty to be empty
		UDR2 = data;
		break;
	case uart3:
		while(BIT_IS_CLR(UCSR3A,UDRE3)){} // waiting for Data Register Empty to be empty
		UDR3 = data;
		break;
	}

}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
u8 UART_recieveByte(u8 uart_no)
{
	switch (uart_no){
	case uart0:
		while(BIT_IS_CLR(UCSR0A,RXC0)){}
		return UDR0;
		break;
	case uart1:
		while(BIT_IS_CLR(UCSR1A,RXC1)){}
		return UDR1;
		break;
	case uart2:
		while(BIT_IS_CLR(UCSR2A,RXC2)){}
		return UDR2;
		break;
	case uart3:
		while(BIT_IS_CLR(UCSR3A,RXC3)){}
		return UDR3;
		break;
	}
	return UDR0;
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const u8 *Str, u8 uart_no)
{
	u8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i],uart_no);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}		
	 *******************************************************************/
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(u8 *Str, u8 uart_no)
{
	u8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte(uart_no);

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte(uart_no);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
