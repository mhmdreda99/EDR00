/*
 * Main.c
 *
 *  Created on: Mar 24, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "DIO_interface.h"

void main()
{
	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_INPUT);
	DIO_u8SetPortValue(DIO_u8PORTD,DIO_u8PORT_HIGH);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	EXTI_voidInt0Init();
	GIE_voidEnable();
	while(1)
	{

	}

}
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
}
