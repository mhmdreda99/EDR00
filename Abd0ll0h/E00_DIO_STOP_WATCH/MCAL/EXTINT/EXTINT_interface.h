/*
 ============================================================================
 Name        : EXTI_interface.h
 Author      : Abdullah Ayman
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 21/04/2022
 Copyright   :
 Description : Header file for DIO Driver
 ============================================================================
 */

#ifndef EXTINT_INTERFACE_H_INCLUDED
#define EXTINT_INTERFACE_H_INCLUDED

/************************************************************/
/*******************	Include section    ******************/
/************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_MACROS.h"
#include "EXTINT_register.h"

/************************************************************/
/*******************	Data Type section   *****************/
/************************************************************/

//Data type for selecting the sense edge
typedef enum
{
	EXTINT_FALLING_EDGE,
	EXTINT_RISING_EDGE

}EXTINT_SENSE_CONTROL_t;

#define ENABLE_GLOBAL_INTERRUPT()	(SREG |= (1<<GIE))	//sei();
#define DISABLE_GLOBAL_INTERRUPT()	(SREG &= ~(1<<GIE))	//cli();

#define ENABLE_INT0()	(GICR |= (1<<INT0))
#define DISABLE_INT0()	(GICR &= ~(1<<INT0))

#define ENABLE_INT1()	(GICR |= (1<<INT1))
#define DISABLE_INT1()	(GICR &= ~(1<<INT1))

#define ENABLE_INT2()	(GICR |= (1<<INT1))
#define DISABLE_INT2()	(GICR &= ~(1<<INT1))




/************************************************************/
/*******************	Prototype section   *****************/
/************************************************************/

extern STD_return_t EXTINT_uint8ExternalInt0(EXTINT_SENSE_CONTROL_t);
extern void EXTINT_callbackInt0(void (*ptrfunc)());

extern STD_return_t EXTINT_uint8ExternalInt1(EXTINT_SENSE_CONTROL_t);
extern void EXTINT_callbackInt1(void (*ptrfunc)());

extern STD_return_t EXTINT_uint8ExternalInt2(EXTINT_SENSE_CONTROL_t);
extern void EXTINT_callbackInt2(void (*ptrfunc)());


#endif // EXTINT_INTERFACE_H_INCLUDED
