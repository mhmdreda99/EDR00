/*
 * @file		  ADC.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Header file for the ADC driver
 */

/*This is preprocessor Header file guard  */
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
/******************************************Includes**************************************************/
#include "../../SERVICE/DIO_register.h"
#include "../../SERVICE/Interrupt_Vector.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/External_Interrupt/External_Interrupt.h"
#include "ADC_Config.h"
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State Enable / Disable ADC interrupt 
 * 
 * _t means that it is a datatype
**/
typedef enum
{
	ADC_Interrupt_ENABLE,
	ADC_Interrupt_DISABLE
}ADC_Interrupt_State_t; 
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State Enable / Disable ADC Peripheral 
 * 
 * _t means that it is a datatype
**/
typedef enum
{
	ADC_ENABLE,
	ADC_DISABLE
}ADC__State_t; 
/******************************************Defintions**********************************************/
#define Unselected_Channel_MASK	0xF8
#define Resolution_10Bit_MASK	0x3FF
#define MaxPinNum	7
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		extern void ADC_Init(void);
 * Description  	 	:		Initialize ADC Periphiral 
 * 
 * @param   	void 	:  		has no input paramater
 * @return  	void 	:		Return nothing
 **/
extern STD_Return ADC_Init(ADC__State_t State);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :	 	extern STD_Return ADC_SetInterrupt_Enable(ADC_Interrupt_State_t State);	
 * Description		 	 :		function to enable the ADC periphiral
 * 
 * @param State  	 	 :		State takes only ADC_Interrupt_Enable,ADC_Interrupt_DISABLE
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
extern STD_Return ADC_SetInterrupt_Enable(ADC_Interrupt_State_t State);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype 			 :		extern STD_Return ADC_Start_conversion(u8 channel); 
 * Description			 : 		function to start the Analog to Digital conversion
 * 
 * @param channel  	 	 :		Takes the number of pin/ channel which is used in the conversion
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
extern STD_Return ADC_Start_conversion(u8 channel);
/*****************************************************************************************************/
/**
 * @brief
 * Prototype			 :		extern STD_Return ADC_Get_Value(u32 *AdcResult);		
 * Description 			 :		function to get the value 
 * 
 * @param AdcResult 	 :		take the result of the Analog to digital conversion
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
extern STD_Return ADC_Get_Value(u16 *AdcResult);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :		extern STD_Return ADC_Read_Value(u8 channel,u32 *AdcValue);		
 * Description 			 :		function Combine between the Conversion and GetValue Function in one function
 * 
 * @param channel 		 :		takes the number of pin/ channel which is used in the conversion
 * @param AdcValue 		 :		take the result of the Analog to digital conversion ADC value
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
extern STD_Return ADC_Read_Value(u8 channel,u16 *AdcValue);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :		extern STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt);	
 * Description 			 :		function calculate the voltage value of the ADC value
 * 
 * @param channel 		 :		takes the number of pin/ channel which is used in the conversion
 * @param AdcVolt        : 		the value of the ADC conversion
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
extern STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :		extern STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt);	
 * Description 			 :		function calculate the voltage value of the ADC value
 * 
 * @param func_ptr 		 :		pointer to function that points to the user/ External function
 * @return void			 : 		return nothing
 **/
extern void ADC_CallBack(void (*func_ptr)(void));
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* MCAL_ADC_ADC_H_ */
