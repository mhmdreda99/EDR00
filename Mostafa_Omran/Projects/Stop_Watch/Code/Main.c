/*
 * Main.c
 *
 *  Created on: Mar 8, 2022
 *      Author: Mostafa
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"
#include<util/delay.h>

#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "SSD_interface.h"

#define F_CPU 8000000UL


int main()
{
	/*Define new  7-Segment */
	SSD_t SSD1={Cathode,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PIN0};

	/*Define new  7-Segment */
	SSD_t SSD2={Cathode,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PIN1};

	/*Define new  7-Segment */
	SSD_t SSD3={Cathode,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PIN2};

	/*Define new  7-Segment */
	SSD_t SSD4={Cathode,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PIN3};

	/*Define pointer to the struct*/
	SSD_t*ptr1=&SSD1;

	/*Define pointer to the struct*/
	SSD_t*ptr2=&SSD2;

	/*Define pointer to the struct*/
	SSD_t*ptr3=&SSD3;

	/*Define pointer to the struct*/
	SSD_t*ptr4=&SSD4;

	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_INPUT);

	DIO_u8SetPortValue(DIO_u8PORTD,DIO_u8PORT_HIGH);
	u8 i,j,s,k,m,e;

	while(1)
	{
		if(GET_BIT(PIND,0)==0)
		{
			for(e=0;e<7;e++)
			{
				for(m=0;m<10;m++)
				{
					for(i=0;i<6;i++)
					{
						for(k=0;k<10;k++)
						{
							for(j=0;j<5;j++)
							{
								for(s=0;s<10;s++)
								{

									if(GET_BIT(PIND,1)==0)
									{
										i=0;j=0;s=0;k=0;m=0;e=0;
									}
									if(GET_BIT(PIND,2)==0)
									{
										do
										{
											SSD_Enable(ptr1);
											SSD_Set_Number(k, ptr1);
											softwareDelayMs(1);
											//_delay_ms(5);
											SSD_Disable(ptr1);

											SSD_Enable(ptr2);
											SSD_Set_Number(i, ptr2);
											softwareDelayMs(1);
											//_delay_ms(5);
											SSD_Disable(ptr2);

											SSD_Enable(ptr3);
											SSD_Set_Number(m, ptr3);
											softwareDelayMs(1);
											//_delay_ms(5);
											SSD_Disable(ptr3);

											SSD_Enable(ptr4);
											SSD_Set_Number(e, ptr4);
											softwareDelayMs(1);
											//_delay_ms(5);
											SSD_Disable(ptr4);

										}
										while(GET_BIT(PIND,2)==1);
									}
									SSD_Enable(ptr1);
									SSD_Set_Number(k, ptr1);
									softwareDelayMs(1);
									//_delay_ms(5);
									SSD_Disable(ptr1);

									SSD_Enable(ptr2);
									SSD_Set_Number(i, ptr2);
									softwareDelayMs(1);
									//_delay_ms(5);
									SSD_Disable(ptr2);

									SSD_Enable(ptr3);
									SSD_Set_Number(m, ptr3);
									softwareDelayMs(1);
									//_delay_ms(5);
									SSD_Disable(ptr3);

									SSD_Enable(ptr4);
									SSD_Set_Number(e, ptr4);
									softwareDelayMs(1);
									//_delay_ms(5);
									SSD_Disable(ptr4);



								}

							}
						}

					}

				}

			}

		}


	}
}

