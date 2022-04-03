/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : SSD                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define Anode       		1
#define Cathode 			0

#define Digit_0             0b00111111
#define Digit_1             0b00000110
#define Digit_2             0b01011011
#define Digit_3             0b01001111
#define Digit_4             0b01100110
#define Digit_5             0b11101101
#define Digit_6             0b11111101
#define Digit_7             0b00000111
#define Digit_8             0b11111111
#define Digit_9             0b11101111

#define SSD1					0
#define SSD2					1
#define SSD3					2
#define SSD4					3

typedef struct
{
    u8 COM_TYPE;
    u8 PORT;
    u8 EnablePort;
    u8 EnablePin;
}SSD_t;


u8 SSD_Set_Number(u8 Number, SSD_t*SSD);
u8 SSD_Enable(SSD_t*SSD); 
u8 SSD_Disable(SSD_t*SSD);
void SSD_voidInit(SSD_t*SSD);
void SSD_Enable_BY_DEMUX(u8 SSD_Number);

#endif
