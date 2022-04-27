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

u16 App_u8ADCReading=0 ;
void ADCNotification(void);
void main (void)
{

	PORT_voidInit();

	CLCD_voidInit(CLCD_2Lines_5x11Fontsize,CLCD_Curser_OFF);

	GIE_voidEnable();

	ADC_voidInit();


	while(1)
	{
		//ADC_u8StartConversionAsynch(0,&App_u8ADCReading,&ADCNotification);
		ADC_u8StartConversionSynch(0,&App_u8ADCReading);
		CLCD_voidWriteNumber(App_u8ADCReading);
		_delay_ms(250);
		CLCD_voidSendCommand(CLCD_Clear_Display);
	}

}
void ADCNotification(void)
{
	CLCD_voidWriteNumber(App_u8ADCReading);
	_delay_ms(250);
	CLCD_voidSendCommand(CLCD_Clear_Display);
}
