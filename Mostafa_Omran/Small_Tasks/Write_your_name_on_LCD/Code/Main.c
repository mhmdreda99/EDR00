/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"

#include "CLCD_interface.h"
#include "DIO_interface.h"

#include "STD_TYPES.h"

#include "CLCD_interface.h"
#include "DIO_interface.h"

void main(void)
{
	/*Initialize LCD pins direction*/
	CLCD_voidInit(CLCD_2Lines_5x11Fontsize,CLCD_Curser_ON_NoBlinking);

	CLCD_voidSendData('M');
	CLCD_voidSendData('O');
	CLCD_voidSendData('S');
	CLCD_voidSendData('T');
	CLCD_voidSendData('A');
	CLCD_voidSendData('F');
	CLCD_voidSendData('A');


	while(1)
	{

	}
}
