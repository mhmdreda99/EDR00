/*
 * Main.c
 *
 *  Created on: Apr 24, 2022
 *      Author: Mostafa
 */


#include "STD_TYPES.h"
#include <util/delay.h>


#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"



void main (void)
{
	u16 App_u8ADCReading=0 ;
	u8 Local_counter=0;
	u8 flag=0;

	/*Initializing the Port*/
	PORT_voidInit();

	/*Initializing the LCD 2 lines no curser*/
	CLCD_voidInit(CLCD_2Lines_5x11Fontsize,CLCD_Curser_OFF);

	/*Initializing the ADC*/
	ADC_voidInit();

	/*Write on the LCD*/
	CLCD_voidSendString("Total Car no =0");

	while(1)
	{
		/*Polling the ADC conversion*/
		ADC_u8StartConversionSynch(0,&App_u8ADCReading);

		/*Checking if high and the flag is low to take only one read*/
		if((App_u8ADCReading==255) && (flag==0))
		{
			/*increment the counter which indicate the cars number*/
			Local_counter++;

			/*go to position x "Total car no =x" and over write it*/
			CLCD_voidGoToXY(0,14);
			CLCD_voidWriteNumber(Local_counter);

			/*Enable the motor and the buzzer*/
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);

			/*raising the flag to take only one reading*/
			flag=1;
		}
		else
		{
			/*disabling the the motor and the buzzer*/
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_LOW);

			/*clearing the flag*/
			flag=0;
		}

	}

}
