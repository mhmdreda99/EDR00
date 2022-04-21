/*
 ============================================================================
 Name        : DIO_program.c
 Author      : Abdullah Ayman
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 20/04/2022
 Copyright   :
 Description : Header file for DIO Driver
 ============================================================================
 */

#include "DIO_interface.h"


void DIO_INIT(void) {
	PINA = 0;
	PINB = 0;
	PINC = 0;
	PIND = 0;

	DDRA = 0;
	DDRB = 0;
	DDRC = 0;
	DDRD = 0;

	PORTA = 0;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
}

uint8 DIO_SET_PIN_DIRECTION(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		DIO_PIN_DIRECTION_t DIRECTION) {

	if ((PIN <= MAX_PIN_NUMBER) && (PIN > MIN_PIN_NUMBER)) {
		switch (PORT) {
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
			return 1;
		}
	} else
		return 1;
	return 0;
}
uint8 DIO_SET_PIN_VALUE(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN,
		DIO_PIN_VALUE_t VALUE) {

	if ((PIN <= MAX_PIN_NUMBER) && (PIN > MIN_PIN_NUMBER)) {

		switch (VALUE) {
		case (DIO_PIN_LOW):
			switch (PORT) {
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
				return 1;
			}
			break;
		case (DIO_PIN_HIGH):
			switch (PORT) {
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
				return 1;
			}
			break;
		default:
			return 1;
		}
	} else
		return 1;
	return 0;
}

uint8 DIO_SET_PORT_DIRECTION(DIO_PORT_NUMBER_t PORT,
		DIO_PORT_DIRECTION_t DIRECTION) {

	switch (PORT) {
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
		return 1;
	}
	return 0;
}
uint8 DIO_SET_PORT_VALUE(DIO_PORT_NUMBER_t PORT, DIO_PORT_VALUE_t VALUE) {
	switch (VALUE) {

	case (DIO_PORT_LOW):
		switch (PORT) {
		case (DIO_PORT_A):
			PORTA = 0;
			break;
		case (DIO_PORT_B):
			PORTB = 0;
			break;
		case (DIO_PORT_C):
			PORTC = 0;
			break;
		case (DIO_PORT_D):
			PORTD = 0;
			break;
		default:
			return 1;
		}
	case (DIO_PORT_HIGH):
		switch (PORT) {
		case (DIO_PORT_A):
			PORTA = 0XFF;
			break;
		case (DIO_PORT_B):
			PORTB = 0XFF;
			break;
		case (DIO_PORT_C):
			PORTC = 0XFF;
			break;
		case (DIO_PORT_D):
			PORTD = 0XFF;
			break;
		default:
			return 1;
		}
	default:
		return 1;
	}
}

uint8 READ_PIN_VALUE(DIO_PORT_NUMBER_t PORT, DIO_PIN_NUMBER_t PIN, uint8 *VALUE)
{

}
