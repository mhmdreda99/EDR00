/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Seko
 */

#include "../MCAL/DIO/DIO_interface.h"
#include  "../MCAL/External_interrupt/External_interrupt.h"
#include "../LIB/BIT_MATH.h"
#include "Config_file.h"
#include <util/delay.h>

void SwitchFunc(void)
{
	 DIO_togglePin(LEDS_PORT ,LED_Pin0);
}

void main(void)
{
	DIO_init();
	Enable_Global_Interrupt(Enable_Interrupt);

	DIO_SetPortDirection(LEDS_PORT,PORT_OUTPUT);
	DIO_SetPortDirection(Switch_PORT,PORT_INPUT);
	while (1)
	{
		DIO_SetPinValue(LEDS_PORT,LED_Pin0,DIO_HIGH);
		External_Int0(Rising_Edge_Sense);
		CallBack_Int0(&SwitchFunc);
	}

}



