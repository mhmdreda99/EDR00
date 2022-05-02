/*
 * main.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Seko
 */

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/External_Interrupt/External_Interrupt.h"
#include "../HAL/LCD/LCD.h"
#include "Config.h"
#include "util/delay.h"

f32 SensorVolt_Value;
u16 SensorADC_Value;
u8 CarsNumber=0;
u8 Flag=0;

void main(void)
{
	//initialization
	DIO_init();
	ADC_Init(ADC_ENABLE);
	CLCD_init();
	//Define SensorPin
	DIO_SetPinDirection(SensorOutput_Port,SensorOutput_PIN0,DIO_INPUT);
	DIO_EnablePullup(SensorOutput_Port,SensorOutput_PIN0,ENABLE_PullUp);
	//Define Buzzer Port direction
	DIO_SetPinDirection(BuzzerOutput_Port,BuzzerOutput_PIN4,DIO_OUTPUT);
	//Define Motor Port Direction
	DIO_SetPinDirection(MotorOutput_Port,MotorOutput_PIN5,DIO_OUTPUT);

	//Enable peripherals
	Enable_Global_Interrupt(Enable_Interrupt); //Enable GIE
	ADC_SetInterrupt_Enable(ADC_Interrupt_ENABLE); //Enable ADIE

	CLCD_Display_Decimal_Number( CarsNumber);
	CLCD_SendWord("  CarsEntered");

	while(1)
		{
		while(GET_BIT(ADCSRA,ADIF)==0)

		{
			while(GET_BIT(ADCSRA,ADIE)==1)
			{
				ADC_Start_conversion(SensorOutput_PIN0);
				ADC_Get_Value(&SensorADC_Value); //Get ADC_value store in variable SensorADC_value
				ADC_ReadVolt(SensorOutput_PIN0,&SensorVolt_Value);//Get voltValue store in variable SensorVolt_Value
				if((SensorVolt_Value!=0)&&(Flag==0))
				{
							CarsNumber=CarsNumber+1;
							CLCD_SendCommand(LCD_GO_HOME);
							CLCD_Display_Decimal_Number( CarsNumber);
							CLCD_SendWord("  CarsEntered");
							DIO_SetPinValue(BuzzerOutput_Port,BuzzerOutput_PIN4,DIO_HIGH);
							DIO_SetPinValue(MotorOutput_Port,MotorOutput_PIN5,DIO_HIGH);
							Flag=1;
				}
			else if ((SensorVolt_Value==0))
			{
				Flag=0;
				DIO_SetPinValue(BuzzerOutput_Port,BuzzerOutput_PIN4,DIO_LOW);
				DIO_SetPinValue(MotorOutput_Port,MotorOutput_PIN5,DIO_LOW);
			}
		}
		}

		/*while(SensorVolt_Value!=0)
					{
						for(u8 counter=1;counter!=0;counter++)
						{
							CarsNumber=CarsNumber+counter;
						}

					}
					*/
		}

}


