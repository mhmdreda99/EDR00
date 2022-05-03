/****************************************************/
/****************************************************/
/************  Author: Mahmoud Mohamed   ************/
/************  Layer: MCAL               ************/
/************  SWC: EXTI                 ************/
/************  Version: 1.00             ************/
/************  Date:29-4-2022            ************/
/****************************************************/
/****************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Sense control options*/
#define EXTI_FALLING_EDGE        0
#define EXTI_RISING_EDGE         1

/*INT0 initialize */
u8 EXTI_u8Int0Init(u8 ExtInt_SenseControl);

/*INT0 initialize */
u8 EXTI_u8INT1Init(u8 ExtInt_SenseControl);

/*INT0 initialize */
u8 EXTI_u8INT2Init(u8 ExtInt_SenseControl);


#endif
