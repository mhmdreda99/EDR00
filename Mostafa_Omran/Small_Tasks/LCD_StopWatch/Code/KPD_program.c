/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : KEYPAD               ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY,Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState;

	/*static to store the variable in .data initialized or .bss if not instead of the stack*/
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;
	static u8 Local_u8KPDCoulmnArr[COLUMN_NUM]={KPD_CLOUMN0_PIN,KPD_CLOUMN1_PIN,KPD_CLOUMN2_PIN,KPD_CLOUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};


	for(Local_u8ColumnIdx=0;Local_u8ColumnIdx<COLUMN_NUM;Local_u8ColumnIdx++)
	{
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDCoulmnArr[Local_u8ColumnIdx],DIO_u8PIN_LOW);

		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinState);

			/*Check if switch is pressed*/
			if(Local_u8PinState==DIO_u8PIN_LOW)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/*Polling (busy waiting) until the key is released*/
				while(Local_u8PinState==DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}

		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDCoulmnArr[Local_u8ColumnIdx],DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
