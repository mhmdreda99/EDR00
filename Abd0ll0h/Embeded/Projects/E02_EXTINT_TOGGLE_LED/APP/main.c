/*
 ============================================================================
 Name        : main.c
 Author      : Abd0ll0h Ayman
 Layer		 : APP
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 28/4/2022
 Copyright   :
 Description : Source code of Application
 ============================================================================
 */

/************************************************************/
/*******************	Include section    ******************/
/************************************************************/
#include <util/delay.h>
#include "../LIB/STD_MACROS.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTINT/EXTINT_interface.h"

/************************************************************/
/*****************	Main Function section    ****************/
/************************************************************/
void ToggleLed()
{
	TOGGLE_BIT(PORTA, 7);

}

void main()
{
	DIO_init();
	DIO_uint8SetPortDirection(DIO_PORT_A, DIO_PORT_OUT);
	DIO_uint8SetPortDirection(DIO_PORT_D, DIO_PORT_IN);
	DIO_uint8SetPortValue(DIO_PORT_D, 0xff); //enable pull up resistance

	ENABLE_GLOBAL_INTERRUPT();
	EXTINT_uint8ExternalInt0(EXTINT_RISING_EDGE);
	EXTINT_callbackInt0(ToggleLed);

	while (1);
}





