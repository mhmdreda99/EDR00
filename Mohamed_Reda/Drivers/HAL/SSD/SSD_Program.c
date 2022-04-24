/*
 * File        : SSD_Program.c
 * Description : This interface file includes 7SEG Driver implementations for Atmega32
 * Author      : Mohamed reda 
 * Date        : 18/4/2022
 * Git account : https://github.com/mhmdreda99
 * mail        : dev.mhmdreda99@gmail.com
 */


#include "LED_Interface.h"
#include "SSD_Private.h"
#include "SSD_Interface.h"


/**
 * @brief 
 * Prototype   : u8 SSD_u8Init(u8 u8Reg);
 * Description : Initialize one 7-Segment of 8 LEDs on specific port
 * @param u8Reg  Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * @return u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 SSD_u8Init(u8 u8Reg)
{
	/*initialize 7-segment led string at desired port and return error value*/
	return LED_u8InitLedString(u8Reg);

}/*end of SSD_u8Init()*/


/**
 * @brief 
 * Prototype   : u8 SSD_u8DisplayNumber(u8 u8Reg,u8 u8DisblayNumber);
 * Description : Display a number on a given 7-segment 
 * @param u8Reg Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * @param u8DisblayNumber Number  : takes only from 0 to 9 
 * @return u8 number for error handling 
 *               (0) means no error, (1) means Undefined PORT, (2) means Display Number out of range error 
 */
u8 SSD_u8DisplayNumber(u8 u8Reg,u8 u8DisblayNumber)
{
	/*Disblay Number check condition*/
	if ( (u8DisblayNumber >= 0) || (u8DisblayNumber<10) )
	{
		/*Disblay number from seven segment array and return error value*/
		return LED_u8LedStringOnOff(u8Reg,SSD_u8SevenSegArray[u8DisblayNumber]);
		
	} 
	else
	{
		/*Disblay Number out of range error*/
		return 2;  
		
	}/*End of Disblay Number check condition*/

}/*end of SSD_u8DisplayNumber()*/