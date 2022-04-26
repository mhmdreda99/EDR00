/*
 * File        : SSD_Inerface.h
 * Description : This interface file includes 7SEG Driver Prototypes and declarations for Atmega32
 * Author      : Mohamed reda 
 * Date        : 18/4/2022
 * Git account : https://github.com/mhmdreda99
 * mail        : dev.mhmdreda99@gmail.com
 */

#ifndef __SSD_Interface_h__ 
#define __SSD_Interface_h__

#include "../../LIB/STD_TYPES.h"

/**
 * @brief 
 * Prototype   : u8 SSD_u8Init(u8 u8Reg);
 * Description : Initialize one 7-Segment of 8 LEDs on specific port
 * @param u8Reg  Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * @return u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 SSD_u8Init(u8 u8Reg); 


/**
 * @brief 
 * Prototype   : u8 SSD_u8DisplayNumber(u8 u8Reg,u8 u8DisblayNumber);
 * Description : Display a number on a given 7-segment 
 * @param u8Reg Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * @param u8DisblayNumber Number  : takes only from 0 to 9 
 * @return u8 number for error handling 
 *               (0) means no error, (1) means Undefined PORT, (2) means Display Number out of range error 
 */
u8 SSD_u8DisplayNumber(u8 u8Reg,u8 u8DisblayNumber); 

#endif
