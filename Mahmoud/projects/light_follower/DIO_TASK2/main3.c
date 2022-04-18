#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_Math.h"







void main (void)
{
	DDRA=0xff;
	DDRD=0b00000000;
	DDRB=0xff;
	PORTD=0xff;


	int ledArr[8]=
	{
			0b00000001,
			0b00000010,
			0b00000100,
			0b00001000,
			0b00010000,
			0b00100000,
			0b01000000,
			0b10000000,

	};
	int x,i,s=0  ;

	while(1)
	{
		x= GET_BIT(PIND,0);
		s= GET_BIT(PIND,1);

		if (x==0)

		{
			if(s==1)
			{


				if(i>=8)
				{
					i=0;
				}
				PORTA=ledArr[i];
				i++;
				_delay_ms(1000);
				PORTB=~0b00000110;
			}
			else if (s==0)
			{
			PORTA=ledArr[i];
			}

		}
		else
		{
			PORTA=0;
			i=0;
		}

	}

}










