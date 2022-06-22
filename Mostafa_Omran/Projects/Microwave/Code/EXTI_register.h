/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : EXTI                 ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


/********************************EXT INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal)) __VA_ARGS__;\
	void vector(void)

/*GICR Register*/
#define GICR 			*((volatile u8*)0x5b)
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

#define GIFR 			*((volatile u8*)0x5A)

#define MCUCR 			*((volatile u8*)0x55)
#define MCUCR_ISC11		3
#define MCUCR_ISC10		2
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0

#define MCUSCR 			*((volatile u8*)0x54)
#define MCUSCR_ISC2		6

//Interrupt Vectors of external interrupts
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3


#endif
