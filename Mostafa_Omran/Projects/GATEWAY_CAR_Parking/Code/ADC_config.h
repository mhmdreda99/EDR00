/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : ADC                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_u32TIMEOUT			50000
#define MUXMask					0b11100000
#define PrescalerMask			0b11111000
//Mask to only read 10 bits from uint16 value
#define _10_BIT_MASK	0x3FF

/*Voltage Reference Selections for ADC*/
#define VREF			1
/*
 * options 0- AREF, Internal Vref turned off
 * 		   1- AVCC with external capacitor at AREF pin
 * 		   2- Internal 2.56V Voltage Reference with external capacitor at AREF pin
 */

/*ADC Prescaler Selection*/
#define PS				4
/*
 * options 0- Prescaler 2
 * 		   1- Prescaler 4
 * 		   2- Prescaler 8
 * 		   3- Prescaler 16
 * 		   4- Prescaler 32
 * 		   5- Prescaler 64
 * 		   6- Prescaler 128
 */
/*Resolution Selection*/
#define Resolution		0
/*
 * options 0- 8-bit Resolution
 * 		   1- 10-bit Resolution
 */

#endif
