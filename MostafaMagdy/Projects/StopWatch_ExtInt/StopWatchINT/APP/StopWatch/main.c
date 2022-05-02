/*
 * test.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Seko
 */
#include "../../HAL/StopWatch/StopWatch.h"
#include "../../MCAL/External_Interrupt/External_Interrupt.h"
#include"../../LIB/BIT_MATH.h"
#include <util/delay.h>

//defining GlobalVariables
u8 counter_Sec10,counter_Sec01,counter_Min01,counter_Min10,StopSwitch,z;
u8 arr[]=
		{
				Zero,
				One,
				Two,
				Three,
				Four,
				Five,
				Six,
				Seven,
				Eight,
				Nine,
		};

void StopFunc(void)
{
	while(1)
	{
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Sec01);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Sec01]);
			_delay_ms(40);
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Sec10);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Sec10]);
			_delay_ms(40);
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Min01);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Min01]);
			_delay_ms(40);
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Min10);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Min10]);
			_delay_ms(40);
			if(GET_BIT(PIND,0)==0)
				break;
			else if (GET_BIT(PIND,1)==0)
				counter_Sec10=0,counter_Sec01=0,counter_Min01=0,counter_Min10=0;

	}
}
/*
void ResetFunc(void)
{
	counter_Sec10=0,counter_Sec01=0,counter_Min01=0,counter_Min10=0;
	while(1)
		{
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Sec01);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Sec01]);
			_delay_ms(40);
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Sec10);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Sec10]);
			_delay_ms(40);
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Min01);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Min01]);
			_delay_ms(40);
			TimingSelection(StopWatch_ControlPort_A,CommonCathod,Min10);
			SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Min10]);
			_delay_ms(40);
			/*if(GET_BIT(PIND,0)==0)
			break;
			}
}
			*/
void main(void)
{
	Enable_Global_Interrupt(Enable_Interrupt);
	//define Stop switch
	DIO_SetPinDirection(StopWatch_ControlSwitch_Port,StopWatch_StopSwitch_Pin,DIO_INPUT);
	DIO_EnablePullup(StopWatch_ControlSwitch_Port,StopWatch_StopSwitch_Pin,ENABLE_PullUp);
	//define Start switch
	DIO_SetPinDirection(StopWatch_ControlSwitch_Port,StopWatch_StartSwitch_Pin,DIO_INPUT);
	DIO_EnablePullup(StopWatch_ControlSwitch_Port,StopWatch_StartSwitch_Pin,ENABLE_PullUp);
	//define Reset Switch
	DIO_SetPinDirection(StopWatch_ControlSwitch_Port,StopWatch_ResetSwitch_Pin,DIO_INPUT);
	DIO_EnablePullup(StopWatch_ControlSwitch_Port,StopWatch_ResetSwitch_Pin,ENABLE_PullUp);
	External_Int0(Falling_Edge_Sense);
	CallBack_Int0(StopFunc);

while(1)
{
	if((GET_BIT(PIND,0))==0)
	{
		for(counter_Min10=0;counter_Min10<6;counter_Min10++)
					for(counter_Min01=0;counter_Min01<10;counter_Min01++)
						for(counter_Sec10=0;counter_Sec10<6;counter_Sec10++)
							for(counter_Sec01=0;counter_Sec01<10;counter_Sec01++)
							{
								{
									{
										{
											TimingSelection(StopWatch_ControlPort_A,CommonCathod,Sec01);
											SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Sec01]);
											_delay_ms(40);
											TimingSelection(StopWatch_ControlPort_A,CommonCathod,Sec10);
											SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Sec10]);
											_delay_ms(40);
											TimingSelection(StopWatch_ControlPort_A,CommonCathod,Min01);
											SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Min01]);
											_delay_ms(40);
											TimingSelection(StopWatch_ControlPort_A,CommonCathod,Min10);
											SevenSegment_Display(DIO_PORTB,CommonCathod,arr[counter_Min10]);
											_delay_ms(40);
											if (GET_BIT(PIND,1)==0)
											{
												counter_Sec10=0,counter_Sec01=0,counter_Min01=0,counter_Min10=0;
												StopFunc();
											}
										}
									}
								}
							}
		}
	}
}

