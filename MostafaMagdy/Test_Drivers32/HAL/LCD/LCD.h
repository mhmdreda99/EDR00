/*
 * LCD.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Seko
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../SERVICE/DIO_register.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

//bits for accessing CGRAM&DDRAM
#define	Set_Bit7	128
#define Set_Bit6	64

//Location in DDRAM of CLCD Controller
#define FirstLoc_SecondLine							0x40

//Commands
#define CLCD_CLEAR			0x01		//Clear the screen
#define LCD_GO_HOME		 	0x02		//Go to 0,0 line


/*Display on off control */
#define CLCD_CURSOR_OFF		0x0C		//Turn off cursor
#define CLCD_DISP_ON_CURSOR   						(0x0E)
#define CLCD_DISP_ON_CURSOR_BLINK   					(0x0F)

#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

void CLCD_init(void);
void CLCD_SendCommand(u8 command);
void CLCD_SendData(u8 Data);
void CLCD_SendWord(const u8 *Arr_PTR);
STD_Return CLCD_GoToXY(u8 X_Position,u8 Y_Position);
void CLCD_SendSpecialChar(u8 *Pattern,u8 BlockNumber,u8 X_Position,u8 Y_Position);
#endif /* HAL_LCD_LCD_H_ */
