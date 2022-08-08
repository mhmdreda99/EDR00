/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : TIMER0               ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


/*Timer0 Mode Selection*/
#define NormalMode								0			/**/
#define PhaseCorrect_PWM_NonInverted			1			/**/
#define PhaseCorrect_PWM_Inverted				2			/**/
#define	CTC_TogglePin							3			/*The Event on pin OC0*/
#define	CTC_ClearPin							4			/*The Event on pin OC0*/
#define	CTC_SetPin								5			/*The Event on pin OC0*/
#define CTC_DisconnectedPin						6			/*No Event on pin OC0*/
#define Fast_PWM_NonInverted					7			/**/
#define Fast_PWM_Inverted						8			/**/

/*Prescale options*/
#define NoDivsion				0
#define DivsionBy8				1
#define DivsionBy64				2
#define DivsionBy256			3
#define DivsionBy1024			4

/*Interrupt Mode*/
#define CTCInterrupt			0
#define OVFInterrupt			1

void TIMER0_voidInit(u8 Copy_u8Mode,u8 Copy_u8Prescale);

void TIMER0_voidInterruptEnable(u8 Copy_u8InterruptType);

void TIMER0_voidSetComareMatchValue(u8 Copy_u8Value);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),u8 Copy_u8InterruptType);

#endif
