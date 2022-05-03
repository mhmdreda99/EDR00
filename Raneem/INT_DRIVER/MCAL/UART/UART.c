/*
 ============================================================================
 Name        : UART.c
 Author      : Muhamed Reda
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 9/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of UART driver
 ============================================================================
*/
#include "UART.h"


void UART_init(void){
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);

	SET_BIT(UCSRC, URSEL);
	SET_BIT(UCSRC, UPM1);

	UBRRL = 51;

	SET_BIT(UCSRB, RXCIE);
}

StdReturn UART_transmitChar(uint8 data){

	while(!READ_BIT(UCSRA, UDRE));
	UDR = data;

	return E_OK;
}

StdReturn UART_receiveChar(uint8 *data){
	while(!READ_BIT(UCSRA, RXC));
	*data = UDR;

	return E_OK;
}
