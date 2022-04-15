/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"


void main(void)
{
	u8 Local_u8Key;
	PORT_voidInit();
	CLCD_voidInit(CLCD_2Lines_5x8Fontsize,CLCD_Curser_OFF);

	while(1)
	{
		do
		{
			Local_u8Key=KPD_u8GetPressedKey();
		}while(Local_u8Key==0xff);
		CLCD_voidWriteNumber(Local_u8Key);
	}

}
