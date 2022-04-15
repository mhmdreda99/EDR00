/*
 ============================================================================
 Name        : DIO_register.h
 Author      : Mostafa Magdy
 Layer		 : MCAL
 Target		 : ATMEGA 32
 Version     : 1.0
 Date		 : 4/3/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for the DIO driver
 ============================================================================
 */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

//
#define PORTA		*((volatile u8*)0x3B)
#define DDRA		*((volatile u8*)0x3A)
#define PINA		*((volatile u8*)0x39)

#define PORTB		*((volatile u8*)0x38)
#define DDRB		*((volatile u8*)0x37)
#define PINB		*((volatile u8*)0x36)

#define PORTC		*((volatile u8*)0x35)
#define DDRC		*((volatile u8*)0x34)
#define PINC		*((volatile u8*)0x33)

#define PORTD		*((volatile u8*)0x32)
#define DDRD		*((volatile u8*)0x31)
#define PIND		*((volatile u8*)0x30)

#define SREG		*((volatile u8*)0x5F)
#define GIE			7

#define GICR		*((volatile u8*)0x5B)
#define INT0			6
#define INT1			7
#define INT2			5

#define GIFR		*((volatile u8*)0x5A)
#define INTF0			6
#define INTF1			7
#define INTF2			5

#define MCUCR		*((volatile u8*)0x55)
#define ISC00			0
#define ISC01			1
#define ISC10			2
#define ISC11			3

#define MCUCSR		*((volatile u8*)0x54)
#define ISC2			6

#endif /* DIO_REGISTER_H_ */
