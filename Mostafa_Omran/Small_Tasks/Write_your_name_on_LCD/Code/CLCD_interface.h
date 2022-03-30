/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : CLCD                 ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/*Function set command*/
#define CLCD_2Lines_5x8Fontsize         0b00111000
#define CLCD_2Lines_5x11Fontsize        0b00111100
#define CLCD_1Lines_5x8Fontsize         0b00110000
#define CLCD_1Lines_5x11Fontsize        0b00110100

/*Display on off control*/
#define CLCD_Curser_OFF                 0b00001100
#define CLCD_Curser_ON_NoBlinking       0b00001110
#define CLCD_Curser_ON_Blinking         0b00001111



void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(u8 Copy_u8Display,u8 Copy_u8Function);



#endif
