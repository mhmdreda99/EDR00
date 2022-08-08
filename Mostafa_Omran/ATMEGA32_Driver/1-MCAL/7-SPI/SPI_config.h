/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : SPI                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define SPI_TIMEOUT			5000000UL

/*SCK and the Oscillator Frequency */
//#define dividedBy_2
//#define dividedBy_4
//#define dividedBy_8
#define dividedBy_16
//#define dividedBy_32
//#define dividedBy_64
//#define dividedBy_128

/*Clock Polarity*/
#define LeadingEdge_Rising
//#define LeadingEdge_Falling

/*Clock Phase*/
#define LeadingEdge_Sample
//#define LeadingEdge_Setup

#endif
