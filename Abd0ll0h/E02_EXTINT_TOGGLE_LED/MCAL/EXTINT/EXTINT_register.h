/*
 ============================================================================
 Name        : EXTI_register.h
 Author      : Abdullah Ayman
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 21/04/2022
 Copyright   :
 Description : Header file for DIO Driver
 ============================================================================
 */

#ifndef EXTINT_REGISTER_H_INCLUDED
#define EXTINT_REGISTER_H_INCLUDED

/**
 * Status REGister							(SREG)
 * contains control bit for enabling External Interrupt
 */
#define SREG	*((volatile unsigned char*)0x5f)
#define GIE		7

/**
 * General Interrupt Control Register		(GICR)
 * contains control bits for enabling the three External Interrupts Pins
 */
#define GICR	*((volatile unsigned char*)0x5b)
#define INT2	5
#define INT0	6
#define INT1	7

/**
 * Microcontroller  Control status Register	(MCUCSR)
 * Microcontroller  Control Register		(MCUCR)
 * contains control bits for interrupt sense control and general MCU functions.
 */
#define MCUCSR	*((volatile unsigned char*)0x54)
#define ISC2	6

#define MCUCR	*((volatile unsigned char*)0x55)
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/**
 *
 */
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal)) __VA_ARGS__;\
	void vector(void)


#define	INT0_vect		__vector_1
#define	INT1_vect		__vector_2
#define	INT2_vect		__vector_3

#endif //EXTINT_REGISTER_H_INCLUDED
