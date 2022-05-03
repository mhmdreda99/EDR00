/****************************************************/
/****************************************************/
/************  Author: Mahmoud Mohamed   ************/
/************  Layer: MCAL               ************/
/************  SWC: DIO                  ************/
/************  Version: 1.00             ************/
/****************************************************/
/****************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8PIN_OUTPUT          1
#define DIO_u8PIN_INPUT           0

#define DIO_u8PIN_HIGH            1
#define DIO_u8PIN_LOW             0

#define DIO_u8PORT_OUTPUT         0xff
#define DIO_u8PORT_INPUT          0

#define DIO_u8PORT_HIGH           0xff
#define DIO_u8PORT_LOW            0

#define DIO_u8PORTA               0
#define DIO_u8PORTB               1
#define DIO_u8PORTC               2
#define DIO_u8PORTD               3

#define DIO_u8PIN0                0
#define DIO_u8PIN1                1
#define DIO_u8PIN2                2
#define DIO_u8PIN3                3
#define DIO_u8PIN4                4
#define DIO_u8PIN5                5
#define DIO_u8PIN6                6
#define DIO_u8PIN7                7

/*rage3 el pull up w e3mlo # */
#define DIO_Pull_Up_Enable        1
#define DIO_Pull_Up_Disable       0


typedef enum
{
	DIO_PUD_DISABLE, // set bit
	DIO_PUD_ENABLE // clear bit
}DIO_PUD_ENABLE_t;

typedef enum
{
	DIO_PORT_A,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D



}DIO_PORT_t;


u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

u8 DIO_u8SetPortDirection(u8 Copy_u8Port,  u8 Copy_u8Direction);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port,  u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8*Copy_pu8Value);





//u8 DIO_u8PullUpEnable(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_pu8Value)


#endif // DIO_INTERFACE_H_
