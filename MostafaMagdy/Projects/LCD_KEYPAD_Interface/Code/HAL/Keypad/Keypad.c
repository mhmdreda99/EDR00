/*
 * keypad.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Seko
 */
#include "Keypad.h"

/************* KeyPad Key Index ***************/
/*         Col_0   Col_1   Col_2   Col_3     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/

u8 KeyPad_Pressed_Key(void)
{
	u8 ColumnIndex,RowIndex,PinState,PressedKey;

	PressedKey=Key_Not_Pressed;

	static u8 KeyPad_Arr[Row_NO][Column_NO]= KeyPad_Arr_Value;
	static u8 KeyPad_Row_Arr[Row_NO]={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};
	static u8 KeyPad_Column_Arr[Column_NO]={Column_PIN0,Column_PIN1,Column_PIN2,Column_PIN3};

	for(ColumnIndex=0;ColumnIndex<Column_NO;ColumnIndex++)
	{
		//Set column of Keypad Output
		DIO_SetPortDirection(KeyPad_Port,PORT_OUTPUT);
		//Activate current column
		DIO_SetPinValue(KeyPad_Port,KeyPad_Column_Arr[ColumnIndex],DIO_LOW);


		for(RowIndex=0;RowIndex<Row_NO;RowIndex++)
		{
			//Set Row input and activate pull-up
			DIO_SetPinDirection(KeyPad_Port,KeyPad_Row_Arr[RowIndex],DIO_INPUT);
			DIO_EnablePullup(KeyPad_Port,KeyPad_Row_Arr[RowIndex],ENABLE_PullUp);

			//Read the current row
			DIO_GetPinValue(KeyPad_Port,KeyPad_Row_Arr[RowIndex],&PinState);

			//Check if switch is pressed
			if(PinState==DIO_LOW)
			{
				PressedKey=KeyPad_Arr[RowIndex][ColumnIndex];

				//Polling (busy waiting) until the key is released
				while(PinState==DIO_LOW)
				{
					DIO_GetPinValue(KeyPad_Port,KeyPad_Row_Arr[RowIndex],&PinState);
				}
				return PressedKey;
			}
		}
		//Deactivate the current column
		DIO_SetPinValue(KeyPad_Port,KeyPad_Column_Arr[ColumnIndex],DIO_HIGH);
	}
	return PressedKey;
}

