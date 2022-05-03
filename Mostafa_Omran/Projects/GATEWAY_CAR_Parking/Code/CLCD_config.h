/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Author  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : CLCD                 ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_


#define CLCD_DATA_PORT		DIO_u8PORTA
#define CLCD_DATA_PIN7      DIO_u8PIN7
#define CLCD_DATA_PIN6      DIO_u8PIN6
#define CLCD_DATA_PIN5      DIO_u8PIN5
#define CLCD_DATA_PIN4      DIO_u8PIN4

#define CLCD_CTRL_PORT		DIO_u8PORTC
#define CLCD_RS_PIN			DIO_u8PIN0
#define CLCD_RW_PIN			DIO_u8PIN1
#define CLCD_E_PIN			DIO_u8PIN2

#define _FOUR_BIT
//#define _EIGHT_BIT


#endif
