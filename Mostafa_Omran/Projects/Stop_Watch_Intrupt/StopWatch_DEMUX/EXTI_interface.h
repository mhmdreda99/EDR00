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
#define EXTI_FALLING_EDGE        0
#define EXTI_RISING_EDGE         1

//initializaing the External Interrupt 0
u8 EXTI_u8Int0Init(u8 ExtInt_SenseControl);

//set user function to be executed on ISR
void INT0_voidCallBack(void*(func_Ptr)(void));

//initializaing the External Interrupt 1
u8 EXTI_u8Int1Init(u8 ExtInt_SenseControl);

//set user function to be executed on ISR
void INT1_voidCallBack(void*(func_Ptr)(void));

//initializaing the External Interrupt 2
u8 EXTI_u8Int2Init(u8 ExtInt_SenseControl);

//set user function to be executed on ISR
void INT2_voidCallBack(void*(func_Ptr)(void));



#endif
