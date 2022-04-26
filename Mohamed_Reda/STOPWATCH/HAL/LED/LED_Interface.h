/*
 * File        : LED_Interface.h
 * Description : This interface file includes LED Driver prototypes and declarations for Atmega32
 * Author      : Mohamed reda 
 * Date        : 19/4/2022
 * Git account : https://github.com/mhmdreda99
 * mail        :  dev.mhmdreda99@gmail.com
 */

#ifndef __LED_Interface_h__ 
#define __LED_Interface_h__

#include "../../LIB/STD_TYPES.h"

#define LED_ON     DIO_ON
#define LED_OFF    DIO_OFF

/**
 * @brief 
 * Prototype   : u8 LED_u8InitOneLed(u8 u8Reg,u8 u8Bit);
 * Description : Initialize one LED on specific port and bit
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit  bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @return u8 	u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 LED_u8InitOneLed(u8 u8Reg,u8 u8Bit);

/**
 * @brief 
 * Prototype   : u8 LED_u8InitLedString(u8 u8Reg);
 * Description : Initialize string of 8 LEDs on specific port
 * @param u8Reg  Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @return u8  u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 LED_u8InitLedString(u8 u8Reg);

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
u8 LED_u8LedOnOff(u8 u8Reg,u8 u8Bit,u8 u8State);

/**
 * @brief 
 *  Prototype   : u8 LED_u8LedStringOnOff(u8 u8Reg,u8 u8Value);
 * Description : Turn string of 8 Leds on and off 
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Value Value   : takes only ON OFF or custom value
 * @return u8  number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 LED_u8LedStringOnOff(u8 u8Reg,u8 u8Value);

#endif
