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
#ifndef DIO_INTERFACE_H_INCLUDED
#define DIO_INTERFACE_H_INCLUDED

/************************************************************/
/*******************	Include section    ******************/
/************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_MACROS.h"
#include "DIO_register.h"

/************************************************************/
/*******************	Data Type section   *****************/
/************************************************************/

/*----------------------------PIN---------------------------*/

//Data Type for selection PIN output Value
typedef enum {
	DIO_PIN_LOW,
	DIO_PIN_HIGH
} DIO_PIN_VALUE_t;

//Data Type for selection PIN Direction
typedef enum {
	DIO_PIN_IN,
	DIO_PIN_OUT
} DIO_PIN_DIRECTION_t;

//Data Type for selection PIN Number
typedef enum {
	DIO_PIN_0,
	DIO_PIN_1,
	DIO_PIN_2,
	DIO_PIN_3,
	DIO_PIN_4,
	DIO_PIN_5,
	DIO_PIN_6,
	DIO_PIN_7
} DIO_PIN_NUMBER_t;

#define MAX_PIN_NUMBER	7
#define MIN_PIN_NUMBER	0

/*----------------------------PORT--------------------------*/

//Data Type for selection PORT output Value
typedef enum {
	DIO_PORT_LOW,
	DIO_PORT_HIGH
} DIO_PORT_VALUE_t;

//Data Type for selection PORT Direction
typedef enum {
	DIO_PORT_IN,
	DIO_PORT_OUT
} DIO_PORT_DIRECTION_t;

//Data Type for selection PORT Number
typedef enum {
	DIO_PORT_A,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D,
} DIO_PORT_NUMBER_t;

/************************************************************/
/*******************	Prototype section   *****************/
/************************************************************/

void DIO_init(void);

STD_return_t DIO_uint8SetPinDirection(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		DIO_PIN_DIRECTION_t DIRECTION);
STD_return_t DIO_uint8SetPinValue(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		DIO_PIN_VALUE_t VALUE);
//STD_return_t DIO_SET_PIN_PULLUPRESTANCE(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN, DIO_PIN_DIRECTION_t DIRECTION)

STD_return_t DIO_uint8SetPortDirection(DIO_PORT_NUMBER_t PORT,
		DIO_PORT_DIRECTION_t DIRECTION);
STD_return_t DIO_uint8SetPortValue(DIO_PORT_NUMBER_t PORT, uint8 VALUE);

STD_return_t DIO_uint8ReadPinValue(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		uint8 *VALUE);

#endif	//DIO_INTERFACE_H_INCLUDED
