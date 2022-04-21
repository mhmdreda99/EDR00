/*
 * main.c
 *
 *  Created on: Apr 20, 2022
 *      Author: user
 */

#include <avr/io.h>
#include <util/delay.h>
#include "STD_MACROS.h"
#include "STD_TYPES.h"

void main(void) {
	uint8 line_array[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	DDRA = 0xff;
	while (1) {
		for (uint8 i = 0; i < 8; i++) {
			PORTA = line_array[i];
			_delay_ms(500);
		}
	}
}
