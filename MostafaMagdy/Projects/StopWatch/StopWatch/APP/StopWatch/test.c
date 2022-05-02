/*
 * test.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Seko
 */
#include "../../HAL/StopWatch/StopWatch.h"
#include <util/delay.h>
void main(void)
{
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
while(1)
	{
		u8 counter_Sec10,counter_Sec01,counter_Min01,counter_Min10;
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
								}
							}
						}
					}
	}
}

