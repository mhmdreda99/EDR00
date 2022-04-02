/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Author  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : CLCD                 ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

    /*Set RW pin to low for write*/
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

    /*Set command to data pins*/
    DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
    
    /*Send enable pulse*/
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to High for Data*/
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

    /*Set RW pin to low for write*/
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

    /*Set command to data pins*/
    DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

    /*Send enable pulse*/
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidInit(u8 Copy_u8Display,u8 Copy_u8Function)
{
	/*Initialize LCD pins direction*/
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);

	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: Choose lines, Choose Font size*/
	switch(Copy_u8Function)
    {
        case CLCD_Curser_OFF:
            CLCD_voidSendCommand(CLCD_Curser_OFF);
            break;
        case CLCD_Curser_ON_NoBlinking:
            CLCD_voidSendCommand(CLCD_Curser_ON_NoBlinking);
            break;
        case CLCD_Curser_ON_Blinking:
            CLCD_voidSendCommand(CLCD_Curser_ON_Blinking);
            break;
    }

	/*Display on off control: display enable, disable/enable cursor, no/ blink cursor*/
	switch(Copy_u8Display)
    {
        case CLCD_2Lines_5x8Fontsize:
            CLCD_voidSendCommand(CLCD_2Lines_5x8Fontsize);
            break;
        case CLCD_2Lines_5x11Fontsize:
            CLCD_voidSendCommand(CLCD_2Lines_5x11Fontsize);
            break;
        case CLCD_1Lines_5x8Fontsize:
            CLCD_voidSendCommand(CLCD_1Lines_5x11Fontsize);
            break;
        case CLCD_1Lines_5x11Fontsize:
            CLCD_voidSendCommand(CLCD_1Lines_5x11Fontsize);
            break;
    }

	/*Clear display*/
	CLCD_voidSendCommand(1);

}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*Calculating the Address of the DDRAM by the coordinates X and Y*/
	u8 Local_u8Address;
	if(Copy_u8XPos==0)
	{
		/*Location is at the first line*/
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		/*Location is at the second line*/
		Local_u8Address=Copy_u8YPos+0x40;
	}

	/*Send the DDRAM Address to point on the location on the screen you want to write on it with setting bit 7*/
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8arr,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Counter,Local_u8CGRAM_Address;

	/*Calculating the Address of the CGRAM whose block is 8 bytes*/
	Local_u8CGRAM_Address=Copy_u8PatternNumber*8;

	/*Send the CGRAM Address to point on the first location then the address counter will continue to increment
	 * 1 with setting bit 6 and clearing the bit 7*/
		CLCD_voidSendCommand(Local_u8CGRAM_Address+64);

	/*Loop to the start inserting the pattern into the CGRAM Byte by Byte*/
		for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
		{
			CLCD_voidSendData(Copy_pu8arr[Local_u8Counter]);
		}

	/*go back to the DDRAM to display the pattern in the selected position*/
		CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*The DDRAM accessing the CGRAM by block to Displaying the pattern*/
		CLCD_voidSendData(Copy_u8PatternNumber);
}
