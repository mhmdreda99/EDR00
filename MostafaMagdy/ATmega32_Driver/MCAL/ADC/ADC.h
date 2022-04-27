/*
 * ADC.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Seko
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../SERVICE/DIO_register.h"
#include "../../SERVICE/Interrupt_Vector.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/External_Interrupt/External_Interrupt.h"
#include "ADC_Config.h"
typedef enum
{
	ADC_Interrupt_ENABLE,
	ADC_Interrupt_DISABLE
}ADC_Interrupt_State_t; //_t means that it is a datatype

#define Unselected_Channel_MASK	0xF8
#define Resolution_10Bit_MASK	0x3FF
#define MaxPinNum	7

//Function Prototypes
extern void ADC_Init(void);
extern STD_Return ADC_SetInterrupt_Enable(ADC_Interrupt_State_t State);
extern STD_Return ADC_Start_conversion(u8 channel);
extern STD_Return ADC_Get_Value(u32 *AdcResult);
extern STD_Return ADC_Read_Value(u8 channel,u32 *AdcValue);
extern STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt);
extern void ADC_CallBack(void (*func_ptr)(void));

#endif /* MCAL_ADC_ADC_H_ */
