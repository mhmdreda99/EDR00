/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : TIMER0               ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define TCCR0 			    *((volatile u8*)0x53)       /*Timer0 Control register*/
#define TCCR0_WGM00		    6                           /*Waveform Generation Mode bit 0 */
#define TCCR0_WGM01		    3                           /*Waveform Generation Mode bit 1 */
#define TCCR0_COM01         5                           /*Compare Match Output Mode bit 1*/
#define TCCR0_COM00         4                           /*Compare Match Output Mode bit 0*/
#define TCCR0_CS02		    2                           /*Prescaler bit2*/
#define TCCR0_CS01		    1                           /*Prescaler bit1*/
#define TCCR0_CS00		    0                           /*Prescaler bit0*/

#define TCNT0               *((volatile u8*)0x52)       /*Timer0 counter Register*/

#define OCR0 			    *((volatile u8*)0x5C)       /*Output compare register 0*/

#define TIMSK 			    *((volatile u8*)0x59)       /*Timer mask*/
#define TIMSK_OCIE0		    1                           /*Output compare 0 interrupt enable */
#define TIMSK_TOIE0         0                           /*Overflow 0 Interrupt Enable*/


#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal)) __VA_ARGS__;\
	void vector(void)


/* Timer/Counter0 VECTORS*/
#define TIMER0_CTC				__vector_10				/*Timer/Counter0 Compare Match*/

#define TIMER0_OVF				__vector_11				/*Timer/Counter0 Overflow*/

#endif
