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
