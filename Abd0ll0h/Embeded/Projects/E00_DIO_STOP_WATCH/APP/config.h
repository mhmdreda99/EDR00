/*
 ============================================================================
 Name        : config.h
 Author      : user
 Layer		 : 
 Target		 : 
 Version     : 
 Date		 : Apr 30, 2022
 Copyright   :
 Description : 
 ============================================================================
 */
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

//Defining Digits while using BCD Decoder (4-bit)
#define Digit_0		0
#define Digit_1		1
#define Digit_2		2
#define Digit_3		3
#define Digit_4		4
#define Digit_5		5
#define Digit_6		6
#define Digit_7		7
#define Digit_8		8
#define Digit_9		9

//Defining Digits while not using BCD Decoder
/*
#define Digit_0             0b00111111
#define Digit_1             0b00000110
#define Digit_2             0b01011011
#define Digit_3             0b01001111
#define Digit_4             0b01100110
#define Digit_5             0b11101101
#define Digit_6             0b11111101
#define Digit_7             0b00000111
#define Digit_8             0b01111111
#define Digit_9             0b11101111
*/


//STD_return_t SSD_COUNT_FROM_TO(uint8 initial, uint8 end, uint8 PORT, uint8 delay);

#endif /* APP_CONFIG_H_ */
