/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Abd0ll0h
 */

#include <avr/io.h>
#include <util/delay.h>
#include "any.h"
#include "STD_TYPES.h"
void SSD_COUNT_FROM_TO(uint8 initial, uint8 end, uint8* PORT, uint8 delay);

void main(void) {

	uint8 sevenSeg[10] = { Digit_0, Digit_1, Digit_2, Digit_3, Digit_4, Digit_5,
	Digit_6, Digit_7, Digit_8, Digit_9 };

	DDRA = 0xff;
	DDRC = 0xff;
	DDRB = 0;


	while (1) {
		//for (uint16 hour_tens = 0; hour_tens < 2; hour_tens++) {
		//for (uint16 hour_ones = 0; hour_ones < 11; hour_ones++) {
		for (uint16 min_tens = 0; min_tens < 6; min_tens++) {
			for (uint8 min_ones = 0; min_ones < 10; min_ones++) {
				for (uint16 sec_tens = 0; sec_tens < 6; sec_tens++) {
					for (uint8 sec_ones = 0; sec_ones < 10; sec_ones++) {
						for (uint8 delay = 0; delay < 50; delay++) {
							//if ()
							PORTA = 0;          //Enable sec_ones
							PORTC = sevenSeg[sec_ones];
							_delay_ms(37.5);
							PORTA = 0b00000001; //Enable sec_tens
							PORTC = sevenSeg[sec_tens];
							_delay_ms(37.5);
							PORTA = 0b00000010; //Enable min_ones
							PORTC = sevenSeg[min_ones];
							_delay_ms(37.5);
							PORTA = 0b00000011; //Enable min_tens
							PORTC = sevenSeg[min_tens];
							_delay_ms(37.5);
							/*PORTA = 0b00000100; //Enable hour_ones
							 PORTC = sevenSeg[hour_ones];
							 _delay_ms(350);
							 PORTA = 0b00000101; //Enable hour_tens
							 PORTC = sevenSeg[hour_tens];
							 _delay_ms(350);*/
						}
					}
				}
			}
		}
		//}
		//}
	}
}

//for(uint8 SSD=0; SSD<=9; SSD++){PORTC=sevenSeg[SSD];_delay_ms(20);}

void SSD_COUNT_FROM_TO(uint8 initial, uint8 end, uint8 PORT, uint8 delay)
{
	uint8 sevenSeg[10] = { Digit_0, Digit_1, Digit_2, Digit_3, Digit_4, Digit_5,
			Digit_6, Digit_7, Digit_8, Digit_9 };
	switch(PORT)
	{
	case (PORTA):
		for(uint8 i=initial; i<=end; i++){*PORT=sevenSeg[i];_delay_ms(delay);}
		break;
	case (PORTB):
		for(uint8 i=initial; i<=end; i++){PORTB=sevenSeg[i];_delay_ms(delay);}
		break;
	case (PORTC):
		for(uint8 i=initial; i<=end; i++){PORTC=sevenSeg[i];_delay_ms(delay);}
		break;
	case (PORTD):
		for(uint8 i=initial; i<=end; i++){PORTD=sevenSeg[i];_delay_ms(delay);}
		break;

	}

}
