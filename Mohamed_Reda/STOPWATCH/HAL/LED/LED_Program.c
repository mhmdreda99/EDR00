/*
 * File        : LED_Program.c
 * Description : This file includes LED Driver implementations for Atmega32
 * Author      : Mohamed reda 
 * Date        : 20/4/2022
 * Git account : https://github.com/mhmdreda99
 * mail        :  dev.mhmdreda99@gmail.com
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_MACROS.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED_Private.h"
#include "LED_Interface.h"


/**
 * @brief 
 * Prototype   : u8 LED_u8InitOneLed(u8 u8Reg,u8 u8Bit);
 * Description : Initialize one LED on specific port and bit
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit  bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @return u8 	u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 LED_u8InitOneLed(u8 u8Reg,u8 u8Bit)
{
	/*initialize desired bit as putput and return error value*/
	return DIO_u8SetDirectionBit(u8Reg,u8Bit,DIO_OUTPUT);

}/*end of LED_u8InitOneLed()*/


/**
 * @brief 
 * Prototype   : u8 LED_u8InitLedString(u8 u8Reg);
 * Description : Initialize string of 8 LEDs on specific port
 * @param u8Reg  Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @return u8  u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 LED_u8InitLedString(u8 u8Reg)
{
	/*initialize desired port  as output and return error value*/
	return DIO_u8SetDirectionReg(u8Reg,DIO_OUTPUT);

}/*end of LED_u8InitLedString*/


/**
 * @brief 
 * Prototype   : u8 LED_u8LedOnOff(u8 u8Reg,u8 u8Bit,u8 u8State);
 * Description : Turn one Led on and off 
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @param u8State  State   : takes only ON OFF
 * @return u8  u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 LED_u8LedOnOff(u8 u8Reg,u8 u8Bit,u8 u8State)
{
	/*write led value on desired bit and return error value*/
	return DIO_u8WriteBit(u8Reg,u8Bit,u8State);

}/*end of LED_u8LedOnOff*/


/**
 * @brief 
 *  Prototype   : u8 LED_u8LedStringOnOff(u8 u8Reg,u8 u8Value);
 * Description : Turn string of 8 Leds on and off 
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Value Value   : takes only ON OFF or custom value
 * @return u8  number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 LED_u8LedStringOnOff(u8 u8Reg,u8 u8Value)
{
	/*write led values on Register and return error value*/
	return DIO_u8WriteReg(u8Reg,u8Value);

}/*end of LED_u8LedStringOnOff()*/
