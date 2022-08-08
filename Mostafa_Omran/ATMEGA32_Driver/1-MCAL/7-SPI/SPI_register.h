/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : SPI                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPDR			*((volatile u8*)0x2F)			/*SPI Data register*/


#define SPSR			*((volatile u8*)0x2E)			/*SPI status register*/
#define SPSR_SPIF		7								/*SPI Interrupt flag*/
#define SPSR_SPI2X		0								/*Prescaler bit 2*/


#define SPCR			*((volatile u8*)0x2D)			/*SPI Control register*/
#define SPCR_SPIE		7								/*SPI Interrupt Enable*/
#define SPCR_SPE		6								/*SPI Enable*/
#define SPCR_DORD		5								/*Data Order*/
#define SPCR_MSTR		4								/*Master bit*/
#define SPCR_CPOL		3								/*Clock Polarity*/
#define SPCR_CPHA		2								/*Clock Phase*/
#define SPCR_SPR1		1								/*Prescaler bit 1*/
#define SPCR_SPR0		0								/*Prescaler bit 0*/

#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal)) __VA_ARGS__;\
	void vector(void)


/*SPI VECTORS*/
#define SPI_Transfer_vect			__vector_12				/**/


#endif
