#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include"STD_TYPES.h"
#include"BIT_Math.h"

#define Anode      1
#define Cathode    0

#define NUM_0                    0b00111111
#define NUM_1                    0b00000110
#define NUM_2                    0b01011011
#define NUM_3                    0b01001111
#define NUM_4                    0b01100110
#define NUM_5                    0b01101101
#define NUM_6                    0b01111101
#define NUM_7                    0b00000111
#define NUM_8                    0b01111111
#define NUM_9                    0b01101111

/*#define RED_LIGHT                0b10001001
#define YELLOW_LIGHT             0b01010010
#define GREEN_LIGHT              0b00100100
#define OFF                      0b00000000*/


typedef struct 
{
    u8 COM_TYPE;
    u8 PORT;
    u8 EnablePort;
    u8 EnablePin;
}SSD_STRUCT;

u8 SSD_Set_Number(u8 Number, SSD_STRUCT*SSD);
u8 SSD_Enable(SSD_STRUCT*SSD);
u8 SSD_Disable(SSD_STRUCT*SSD);

#endif
