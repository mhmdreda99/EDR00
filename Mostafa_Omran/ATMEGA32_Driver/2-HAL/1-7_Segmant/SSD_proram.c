/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Author  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : SSD                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

void SSD_voidInit(SSD_t*SSD)
{
	DIO_u8SetPinDirection(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(SSD->PORT,DIO_u8PORT_OUTPUT);

}

u8 SSD_Set_Number(u8 Number, SSD_t*SSD)
{
	u8 sevenSeg[10]={Digit_0,Digit_1,Digit_2,Digit_3,Digit_4,Digit_5,Digit_6,Digit_7,Digit_8,Digit_9};
	u8 Local_u8ErrorState=0;
	if(SSD!=NULL)
	{
		if(Number<=9&&Number>=0)
		{
			if(SSD->COM_TYPE==Anode)
			{
				DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_HIGH);
				DIO_u8SetPortValue(SSD->PORT,~sevenSeg[Number]);
			}
			else if(SSD->COM_TYPE==Cathode)
			{
				DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_LOW);
				DIO_u8SetPortValue(SSD->PORT,sevenSeg[Number]);
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}
		
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 SSD_Enable(SSD_t*SSD)
{
	u8 Local_u8ErrorState=0;
	if(SSD->COM_TYPE==Anode)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_HIGH);
	}
	else if(SSD->COM_TYPE==Cathode)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 SSD_Disable(SSD_t*SSD)
{
	u8 Local_u8ErrorState=0;
	if(SSD->COM_TYPE==Anode)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_LOW);
	}
	else if(SSD->COM_TYPE==Cathode)
	{
		DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
