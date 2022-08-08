/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : TWI                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWCR				*((volatile u8*)0x56)	/*TWI Control Register*/
#define TWCR_TWINT			7						/*Interrupt Flag (the only flag can't clear by interrupt)*/
#define TWCR_TWEA			6						/*Enable Acknowledge*/
#define TWCR_TWSTA			5						/*Start Condition*/
#define TWCR_TWSTO			4						/*Stop Condition*/
#define TWCR_TWWC			3						/*Write Collision*/
#define TWCR_TWEN			2						/*Enable*/
#define TWCR_TWIE			0						/*Interrupt Enable*/


#define TWBR				*((volatile u8*)0x20)	/*TWI Bit Rate Register*/

#define TWSR				*((volatile u8*)0x21)	/*TWI Status Register*/
#define TWSR_TWPS1			1						/*Prescaler Bit 1*/
#define TWSR_TWPS0			0						/*Prescaler Bit 0*/

#define TWDR				*((volatile u8*)0x23)	/*TWI Data Register*/


#define TWAR				*((volatile u8*)0x22)	/*TWI Address Register*/
#define TWAR_TWGCE			0						/*General Call Recognition Enable*/


#endif
