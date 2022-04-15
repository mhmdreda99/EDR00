/*
 ============================================================================
 Name        : DIO_interface.h
 Author      : Mostafa Magdy
 Layer		 : MCAL
 Target		 : ATMEGA 32
 Version     : 1.0
 Date		 : 4/3/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for the DIO driver
 ============================================================================
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../SERVICE/DIO_register.h"

#define MAX_PinNum 	7
#define PORT_HIGH	0xff
#define PORT_LOW	0
#define PORT_OUTPUT	0xff
#define PORT_INPUT	0

#define NULL 0
typedef enum
	{
		DIO_PORTA,
		DIO_PORTB,
		DIO_PORTC,
		DIO_PORTD
	} DIO_Ports;
//Direction
typedef enum
	{
		DIO_INPUT,
		DIO_OUTPUT
	} DIO_Direction;

//Value
typedef enum
	{
		DIO_LOW,
		DIO_HIGH
	} DIO_State;
typedef enum
	{
		ENABLE_PullUp,
		DISABLE_PullUp
	}DIO_PullUpState;
//return_type


void DIO_init(void);

STD_Return DIO_SetPinDirection(DIO_Ports PORT, u8 PIN, DIO_Direction Direction); //DDR for single pin

STD_Return DIO_SetPortDirection(DIO_Ports PORT,DIO_Direction Direction);	   //DDR for All port

STD_Return DIO_SetPinValue(DIO_Ports PORT,u8 PIN,DIO_State State);		   // for pin value

STD_Return DIO_SetPortValue(DIO_Ports PORT,DIO_State State);	           //for port value

STD_Return DIO_GetPinValue(DIO_Ports PORT,u8 PIN,DIO_State* State);        //for store pin value using pointer

STD_Return DIO_EnablePullup(DIO_Ports port, u8 pin, DIO_PullUpState Pullstate); //to activate PullUp resistor

#endif /* DIO_INTERFACE_H_ */
