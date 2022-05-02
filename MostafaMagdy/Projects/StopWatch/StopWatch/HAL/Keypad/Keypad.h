/*
 * @file          Keypad.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 *  Description :  Header file for the Keypad
 */

/*This is preprocessor Header file guard  */
#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
/******************************************Includes**************************************************/
#include "Keypad_Config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/STD_Types.h"
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: u8 KeyPad_Pressed_Key(void);
 * Description          : function to define which switch is pressed in the keypad
 * 
 * @return u8           : return the value of the pressed switch 
 */
u8 KeyPad_Pressed_Key(void);
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* HAL_KEYPAD_KEYPAD_H_ */
