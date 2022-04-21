/*
 ============================================================================
 Name        : DIO_interface.h
 Author      : Abdullah Ayman
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 20/04/2022
 Copyright   :
 Description : Header file for DIO Driver
 ============================================================================
 */

/************************************************************/
/*******************	Include section    ******************/
/************************************************************/
#ifndef DIO_INTERFACE_H_INCLUDED
#define DIO_INTERFACE_H_INCLUDED
#include "../4-LIB/STD_TYPES.h"
#include "../4-LIB/STD_MACROS.h"
#include "DIO_register.h"

/************************************************************/
/*******************	Data Type section   *****************/
/************************************************************/

/*----------------------------PIN---------------------------*/

typedef enum
{
	DIO_PIN_LOW,
	DIO_PIN_HIGH
}DIO_PIN_VALUE_t;

typedef enum
{
	DIO_PIN_IN,
	DIO_PIN_OUT
}DIO_PIN_DIRECTION_t;

typedef enum
{
	DIO_PIN_0,
	DIO_PIN_1,
	DIO_PIN_2,
	DIO_PIN_3,
	DIO_PIN_4,
	DIO_PIN_5,
	DIO_PIN_6,
	DIO_PIN_7
}DIO_PIN_NUMBER_t;

#define MAX_PIN_NUMBER	7
#define MIN_PIN_NUMBER	0

/*----------------------------PORT--------------------------*/

typedef enum
{
	DIO_PORT_LOW,
	DIO_PORT_HIGH
}DIO_PORT_VALUE_t;

typedef enum
{
	DIO_PORT_IN,
	DIO_PORT_OUT
}DIO_PORT_DIRECTION_t;

typedef enum
{
	DIO_PORT_A,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D,
}DIO_PORT_NUMBER_t;

/************************************************************/
/*******************	Prototype section   *****************/
/************************************************************/

void DIO_INIT(void);

uint8 DIO_SET_PIN_DIRECTION(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN, DIO_PIN_DIRECTION_t DIRECTION);
uint8 DIO_SET_PIN_VALUE(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN, DIO_PIN_VALUE_t VALUE);
//uint8 DIO_SET_PIN_PULLUPRESTANCE(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN, DIO_PIN_DIRECTION_t DIRECTION)

uint8 DIO_SET_PORT_DIRECTION(DIO_PORT_NUMBER_t PORT, DIO_PORT_DIRECTION_t DIRECTION);
uint8 DIO_SET_PORT_VALUE(DIO_PORT_NUMBER_t PORT, DIO_PORT_VALUE_t VALUE);

uint8 READ_PIN_VALUE(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN, uint8* VALUE);

#endif	//DIO_INTERFACE_H_INCLUDED
