/*
 
 ============================================================================
 Name        : UART.h
 Author      : Muhamed Reda
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 9/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description :  code of SPI driver
 ============================================================================
*/
#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA16/Registers.h"



extern void UART_init(void);
extern StdReturn UART_transmitChar(uint8 data);
extern StdReturn UART_receiveChar(uint8 *data);

#endif /* MCAL_UART_UART_H_ */
