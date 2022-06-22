/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : EXTI                 ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Sense controll options*/
#define EXTI_FALLING_EDGE		0
#define EXTI_RISING_EDGE		1

#define INT0					6
#define INT1					7
#define INT2					5

//initializaing the External Interrupt 0
extern u8 EXTI_u8Int0Init(u8 ExtInt_SenseControl);

//set user function to be executed on ISR
extern void INT0_voidCallBack(void(*func_Ptr)(void));

//
extern u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

//initializaing the External Interrupt 1
extern u8 EXTI_u8Int1Init(u8 ExtInt_SenseControl);

//set user function to be executed on ISR
extern void INT1_voidCallBack(void(*func_Ptr)(void));

//initializaing the External Interrupt 2
extern u8 EXTI_u8Int2Init(u8 ExtInt_SenseControl);

//set user function to be executed on ISR
extern void INT2_voidCallBack(void(*func_Ptr)(void));


u8 EXTI_u8DisableInterrupt(u8 Copy_IntNum);

u8 EXTI_u8EnableInterrupt(u8 Copy_IntNum);



#endif
