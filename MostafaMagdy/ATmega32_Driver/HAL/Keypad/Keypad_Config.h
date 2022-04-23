/*
 * Keypad_Config.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Seko
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


#define Key_Not_Pressed	0xff

#define Column_NO	4
#define Row_NO		4

//#define KeyPad_Port		DIO_PORTA
#define KeyPad_Port			DIO_PORTB
//#define KeyPad_Port		DIO_PORTC
//#define KeyPad_Port		DIO_PORTD

#define KeyPad_Arr_Value	{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

//Row Selection
//#define ROW_PIN0	0
//#define ROW_PIN1	1
//#define ROW_PIN2	2
//#define ROW_PIN3	3
#define ROW_PIN0	4
#define ROW_PIN1	5
#define ROW_PIN2 	6
#define ROW_PIN3	7

//Column Selection
#define Column_PIN0	0
#define Column_PIN1	1
#define Column_PIN2	2
#define Column_PIN3	3
//#define Column_PIN0	4
//#define Column_PIN1	5
//#define Column_PIN2	6
//#define Column_PIN3	7

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
