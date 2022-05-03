/****************************************************/
/****************************************************/
/************  Author: Mahmoud Mohamed   ************/
/************  Layer: MCAL               ************/
/************  SWC: EXTI                 ************/
/************  Version: 1.00             ************/
/************  Date:29-4-2022            ************/
/****************************************************/
/****************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define GICR   *((volatile u8*)0x5B) //INT ENABLE 
#define GICR_INT1  7
#define GICR_INT0  6 
#define GICR_INT2  5

#define GIFR   *((volatile u8*)0x5A) //FLAG REGISTER

#define MCUCR   *((volatile u8*)0x55)  //CONTROL & SENSE REGISTER FOR INT0 INT1

#define MCUCR_ISC11  3   
#define MCUCR_ISC10  2  
#define MCUCR_ISC01  1  
#define MCUCR_ISC00  0


#define MCUSCR *((volatile u8*)0x54) //CONTROL & SENSE REGISTER FOR INT2

#define MCUSCR_ISC2   6

#endif
