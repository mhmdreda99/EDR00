/*
 ============================================================================
 Name        : main.c
 Author      : Abd0ll0h
 Layer		 : 
 Target		 : 
 Version     : 
 Date		 : May 5, 2022
 Copyright   :
 Description : 
 ============================================================================
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/STD_MACROS.h"
#include "../LIB/STD_TYPES.h"

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
