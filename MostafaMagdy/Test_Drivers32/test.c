/*
 * test.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Seko
 */
#include "HAL/LCD/LCD.h"
#include <util/delay.h>
void main(void)
{

	CLCD_init();
	CLCD_SendData('S');
	CLCD_SendData('E');
	CLCD_SendData('K');
	CLCD_SendData('O');

	while(1)
	{
	}
}
