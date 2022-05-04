/*
 ============================================================================
 Name        : DIO_program.c
 Author      : Abd0ll0h Ayman
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

#include "DIO_interface.h"

/************************************************************/
/************	Function Implementation section	*************/
/************************************************************/

void DIO_init(void)
{
	PINA = 0;
	PINB = 0;
	PINC = 0;
	PIND = 0;

	DDRA = 0;
	DDRB = 0;
	DDRC = 0;
	DDRD = 0;
}

STD_return_t DIO_uint8SetPinDirection(DIO_PORT_NUMBER_t PORT,
		DIO_PIN_NUMBER_t PIN, DIO_PIN_DIRECTION_t DIRECTION)
{

	if ((PIN <= MAX_PIN_NUMBER) && (PIN >= MIN_PIN_NUMBER))
	{
		switch (DIRECTION)
		{
		case DIO_PIN_IN:
			switch (PORT)
			{
			case (DIO_PORT_A):
				CLEAR_BIT(DDRA, PIN);
				break;
			case (DIO_PORT_B):
				CLEAR_BIT(DDRB, PIN);
				break;
			case (DIO_PORT_C):
				CLEAR_BIT(DDRC, PIN);
				break;
			case (DIO_PORT_D):
				CLEAR_BIT(DDRD, PIN);
				break;
			default:
				return P_NOK;
			}
			break;

		case DIO_PIN_OUT:
			switch (PORT)
			{
			case (DIO_PORT_A):
				SET_BIT(DDRA, PIN);
				break;
			case (DIO_PORT_B):
				SET_BIT(DDRB, PIN);
				break;
			case (DIO_PORT_C):
				SET_BIT(DDRC, PIN);
				break;
			case (DIO_PORT_D):
				SET_BIT(DDRD, PIN);
				break;
			default:
				return P_NOK;
			}
			break;

		default:
			return P_NOK;
		}
	}
	else
		return P_NOK;
	return P_OK;
}
STD_return_t DIO_uint8SetPinValue(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		DIO_PIN_VALUE_t VALUE)
{

	if ((PIN <= MAX_PIN_NUMBER) && (PIN >= MIN_PIN_NUMBER))
	{

		switch (VALUE)
		{
		case (DIO_PIN_LOW):
			switch (PORT)
			{
			case (DIO_PORT_A):
				CLEAR_BIT(PORTA, PIN);
				break;
			case (DIO_PORT_B):
				CLEAR_BIT(PORTB, PIN);
				break;
			case (DIO_PORT_C):
				CLEAR_BIT(PORTC, PIN);
				break;
			case (DIO_PORT_D):
				CLEAR_BIT(PORTD, PIN);
				break;
			default:
				return P_NOK;
			}
			break;
		case (DIO_PIN_HIGH):
			switch (PORT)
			{
			case (DIO_PORT_A):
				SET_BIT(PORTA, PIN);
				break;
			case (DIO_PORT_B):
				SET_BIT(PORTB, PIN);
				break;
			case (DIO_PORT_C):
				SET_BIT(PORTC, PIN);
				break;
			case (DIO_PORT_D):
				SET_BIT(PORTD, PIN);
				break;
			default:
				return P_NOK;
			}
			break;
		default:
			return P_NOK;
		}
	}
	else
		return P_NOK;
	return P_OK;
}

STD_return_t DIO_uint8SetPortDirection(DIO_PORT_NUMBER_t PORT,
		DIO_PORT_DIRECTION_t DIRECTION)
{

	switch (DIRECTION)
	{

	case DIO_PORT_LOW:
		switch (PORT)
		{
		case (DIO_PORT_A):
			DDRA = 0;
			break;
		case (DIO_PORT_B):
			DDRB = 0;
			break;
		case (DIO_PORT_C):
			DDRC = 0;
			break;
		case (DIO_PORT_D):
			DDRD = 0;
			break;
		default:
			return P_NOK;
		}
		break;

	case DIO_PORT_HIGH:
		switch (PORT)
		{
		case (DIO_PORT_A):
			DDRA = 0XFF;
			break;
		case (DIO_PORT_B):
			DDRB = 0XFF;
			break;
		case (DIO_PORT_C):
			DDRC = 0XFF;
			break;
		case (DIO_PORT_D):
			DDRD = 0XFF;
			break;
		default:
			return P_NOK;
			break;
		}
		break;

	default:
		return P_NOK;
	}
	return P_OK;
}
STD_return_t DIO_uint8SetPortValue(DIO_PORT_NUMBER_t PORT, uint8 VALUE)
{

	switch (PORT)
	{
	case (DIO_PORT_A):
		PORTA = VALUE;
		break;
	case (DIO_PORT_B):
		PORTB = VALUE;
		break;
	case (DIO_PORT_C):
		PORTC = VALUE;
		break;
	case (DIO_PORT_D):
		PORTD = VALUE;
		break;
	default:
		return P_NOK;
	}
	return P_OK;
}

STD_return_t DIO_uint8ReadPinValue(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		uint8 *VALUE)
{
	if ((PIN <= MAX_PIN_NUMBER) && (PIN >= MIN_PIN_NUMBER))
	{
		switch (PORT)
		{
		case DIO_PORT_A:
			*VALUE = READ_BIT(PINA, PIN);
			break;
		case DIO_PORT_B:
			*VALUE = READ_BIT(PINB, PIN);
			break;
		case DIO_PORT_C:
			*VALUE = READ_BIT(PINC, PIN);
			break;
		case DIO_PORT_D:
			*VALUE = READ_BIT(PIND, PIN);
			break;
		default:
			return P_NOK;
		}
	}
	else
		return P_NOK;
	return P_OK;
}
