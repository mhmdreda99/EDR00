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
	CLCD_GoToXY(0,3);
	CLCD_SendData('R');
	CLCD_GoToXY(1,5);
		CLCD_SendData('M');
}
