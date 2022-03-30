/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

void main(void)
{
	/*Define new  7-Segment */
	SSD_t SSD1={Cathode,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PIN3};

	/*Define pointer to the struct*/
	SSD_t*ptr1=&SSD1;
	/*Initialize LCD pins direction*/
	SSD_voidInit(ptr1);
	while(1)
	{
		SSD_Set_Number(8,ptr1);
	}
}
