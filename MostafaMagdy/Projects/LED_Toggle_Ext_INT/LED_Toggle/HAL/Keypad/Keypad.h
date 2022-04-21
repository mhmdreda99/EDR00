
/*
 * keypad.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Seko
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "Keypad_Config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/STD_Types.h"

#define Column_NO	4
#define Row_NO	4

u8 KeyPad_Pressed_Key(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
