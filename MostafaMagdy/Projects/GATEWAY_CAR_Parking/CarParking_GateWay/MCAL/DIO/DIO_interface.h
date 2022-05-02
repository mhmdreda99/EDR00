/*
 * @file 		  DIO_interface.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Header file for the DIO driver
 */

/*This is preprocessor Header file guard  */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/******************************************Includes**************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../SERVICE/DIO_register.h"
/*******************************************Defintions***********************************************/
#define MAX_PinNum 	7
#define PORT_HIGH	0xff
#define PORT_LOW	0
#define PORT_OUTPUT	0xff
#define PORT_INPUT	0
#define NULL 0
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * 
 * _t means that it is a datatype
**/
typedef enum
	{
		DIO_PORTA,
		DIO_PORTB,
		DIO_PORTC,
		DIO_PORTD
	} DIO_Ports_t;
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State Direction DIO_Input/DIO_Output
 * 
 * _t means that it is a datatype
**/
typedef enum
	{
		DIO_INPUT,
		DIO_OUTPUT
	} DIO_Direction_t;
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State PinValue DIO_LOW/DIO_HIGH
 * 
 * _t means that it is a datatype
**/
typedef enum
	{
		DIO_LOW,
		DIO_HIGH
	} DIO_State_t;
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State state of pull up resistor  Enable/Disable
 * 
 * _t means that it is a datatype
**/
typedef enum
	{
		ENABLE_PullUp,
		DISABLE_PullUp
	}DIO_PullUpState_t;
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		void DIO_init(void);
 * Description  	 	:		Initialize DIO Periphiral 
 * 
 * @param   	void 	:  		has no input paramater
 * @return  	void 	:		Return nothing
 **/
void DIO_init(void);
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPinDirection(DIO_Ports_t PORT, u8 PIN, DIO_Direction_t Direction);
 * Description  	 	: function for Set pin direction Input or Output
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param PIN 			: takes the number of pin in the PORT
 * @param Direction 	: takes the directon of the single PIN is DIO_INPUT or DIO_OUTPUT
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPinDirection(DIO_Ports_t PORT, u8 PIN, DIO_Direction_t Direction); //DDR for single pin
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPortDirection(DIO_Ports_t PORT,DIO_Direction_t Direction);
 * Description  	 	: function for Set PORT direction Input or Output
 * 
 * @param PORT 		    : takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD		
 * @param Direction     : takes the direction of all pins in the port PORT_INPUT/PORT_OUTPUT
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPortDirection(DIO_Ports_t PORT,DIO_Direction_t Direction);
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t State);		  
 * Description  	 	: function for Set specific Pin in a port value High or Low
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param PIN 			: takes the number of pin in the PORT
 * @param State 		: takes the Value of the single PIN is DIO_HIGH or DIO_LOW
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 							return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t State);		 
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPortValue(DIO_Ports_t PORT,u8 value);
 * Description  	 	: function for Set PORT Value High or Low
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param value  		: takes the value  of all pins in the port PORT_HIGH/PORT_LOW
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPortValue(DIO_Ports_t PORT,u8 value);	 
/*******************************************************************************************************/       
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_GetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t* State);  
 * Description  	 	: function for storing the value of pin 
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param PIN 		    : takes the number of pin in the PORT
 * @param State 		: pointer of the state that takes the Value of the single PIN is DIO_HIGH or DIO_LOW
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_GetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t* State);        
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_togglePin(DIO_Ports_t port,u8 pin); 
 * Description  	 	: function for toggle the current value of pin 
 *  
 * @param port 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param pin 			: takes the number of pin in the PORT
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_togglePin(DIO_Ports_t port,u8 pin);
/*******************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_EnablePullup(DIO_Ports_t port, u8 pin, DIO_PullUpState_t Pullstate); 
 * Description  	 	: function for activting the pull up resistor 
 * 
 * @param port 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param pin 			: takes the number of pin in the PORT
 * @param Pullstate     : take the pull up state ENABLE_PullUp/DISABLE_PullUp
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_EnablePullup(DIO_Ports_t port, u8 pin, DIO_PullUpState_t Pullstate); 
/*******************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* DIO_INTERFACE_H_ */
