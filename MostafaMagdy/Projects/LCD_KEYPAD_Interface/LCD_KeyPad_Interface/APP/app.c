/*
 * app.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Seko
 */

#include "../LIB/STD_Types.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../MCAL/DIO/DIO_interface.h"

void main()
{
	DIO_init();
	u8 Key_Value;
	CLCD_init();

while(1)
{
	do
		{
			Key_Value=KeyPad_Pressed_Key();
		}
	while((Key_Value) == (Key_Not_Pressed));
	CLCD_Display_Decimal_Number(Key_Value);

}

}
