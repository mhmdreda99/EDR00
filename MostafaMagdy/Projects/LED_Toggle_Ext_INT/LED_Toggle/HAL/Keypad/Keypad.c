/*
 * keypad.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Seko
 */
#include "Keypad.h"

u8 KeyPad_Pressed_Key(void)
{
	u8 ColumnIndex,RowIndex,PinState,PressedKey;
	static u8 KeyPad_Arr[Row_NO][Column_NO]= KeyPad_Arr_Value;
	static u8 KeyPad_Column_Arr [Column_NO]={Column_PIN4,Column_PIN5,Column_PIN6,Column_PIN7};
	static u8 KeyPad_Row_Arr [Column_NO]={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};

	PressedKey=Key_Not_Pressed;

	for(ColumnIndex=0;ColumnIndex<Column_NO;ColumnIndex++)
		{
			//activate current column
			DIO_SetPinValue(KeyPad_Port,KeyPad_Column_Arr[ColumnIndex],DIO_LOW);
			for(RowIndex=0;RowIndex<Row_NO;RowIndex++)
				{
				 //read current row
					DIO_GetPinValue(KeyPad_Port,KeyPad_Row_Arr[RowIndex],&PinState);

				//check if switch is pressed
					if(PinState==DIO_LOW)
						{
							PressedKey=KeyPad_Arr[RowIndex][ColumnIndex];
							while(PinState==DIO_LOW)
								{
									//polling check until key is released
									DIO_GetPinValue(KeyPad_Port,KeyPad_Row_Arr[RowIndex],&PinState);
								}
							return PressedKey;
						}
						DIO_SetPinValue(KeyPad_Port,KeyPad_Column_Arr[ColumnIndex],DIO_LOW);
				}
		}
	// changeable value by user
	return PressedKey;
}

