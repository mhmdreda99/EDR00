/*
 * @file          Keypad_Config.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 *  Description :  Configuration file for the Keypad
 */

/*This is preprocessor Header file guard  */
#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_
/******************************************Defintions**********************************************/
#define Key_Not_Pressed	0xff

#define Column_NO	4 
#define Row_NO		4
/**************************************KeyPad_Port_Selection***************************************/
//#define KeyPad_Port		DIO_PORTA
#define KeyPad_Port			DIO_PORTB
//#define KeyPad_Port		DIO_PORTC
//#define KeyPad_Port		DIO_PORTD
/****************************************KeyPad_Array_Value*****************************************/
#define KeyPad_Arr_Value	{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
/*************************************KeyPad_Pin_Row_Selection**************************************/
//#define ROW_PIN0	0
//#define ROW_PIN1	1
//#define ROW_PIN2	2
//#define ROW_PIN3	3
#define ROW_PIN0	4
#define ROW_PIN1	5
#define ROW_PIN2 	6
#define ROW_PIN3	7
/************************************KeyPad_Pin_Column_Selection*************************************/
#define Column_PIN0	0
#define Column_PIN1	1
#define Column_PIN2	2
#define Column_PIN3	3
//#define Column_PIN0	4
//#define Column_PIN1	5
//#define Column_PIN2	6
//#define Column_PIN3	7
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
