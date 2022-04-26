/*
 * File        : main.c
 * Description : This file include main code for stopwatch application using four 7-segment and push button Drivers
 *               start/pause  : when pressed count stop until it's pressed again
 *               reset button : when pressed reset count to zero and stop count until start/stop button is pressed
 * Author      : Mohamed reda 
 * Date        : 18/4/2022
 * Git account : https://github.com/mhmdreda99
 * mail        : dev.mhmdreda99@gmail.com
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>


#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/SSD/SSD_Interface.h"

/*Macros*/
/*SEVEN_SEG_DELAY is used to set all 7-segments change rate */
#define SEVEN_SEG_DELAY   2
/*DELAY is used to set duration time for each time display */   
#define DELAY  ( (u8)( 1000 / (SEVEN_SEG_DELAY*4) ) )

#define PRESSED   0
#define START     1
#define STOP      0

/*==========================================
 * Global variables
 *==========================================*/

u8 APP_u8StopStartButtonState = STOP;
/**
 * @brief 
 * main code for stopwatch application using four 7-segment and push button Drivers
 *               start/pause  : when pressed count stop until it's pressed again
 *               reset button : when pressed reset count to zero and stop count until start/stop button is pressed
 * @return int 
 */
int main(void)
{
	
	/*==========================================
	 * Initialization
	 *==========================================*/
	
	/*Initialize  7-Segment value at PORTB*/
	SSD_u8Init(DIO_PORTC);
	
	/*Initialize Buttons*/
	/*=============================================================================*/
	/*Start button*/
	DIO_u8SetDirectionBit(DIO_PORTD,DIO_PD0,DIO_INPUT);
	/*enable pull up resistor*/
	DIO_u8ConfigPullupBit(DIO_PORTD,DIO_PD0,DIO_EN_PULL_UP_RES);
	
	/*Reset button*/
	DIO_u8SetDirectionBit(DIO_PORTD,DIO_PD1,DIO_INPUT);
	/*enable pull up resistor*/
	DIO_u8ConfigPullupBit(DIO_PORTD,DIO_PD1,DIO_EN_PULL_UP_RES);
	/*Stop button*/
	
	DIO_u8SetDirectionBit(DIO_PORTD,DIO_PD2,DIO_INPUT);
	/*enable pull up resistor*/
	DIO_u8ConfigPullupBit(DIO_PORTD,DIO_PD2,DIO_EN_PULL_UP_RES);
	
	/*initialize enable pins these pins will be used to choose between 7-segments*/
	/*=============================================================================*/
	/*set Seconds-Units 7-segment's enable at PB7 and set it as Output*/
	DIO_u8SetDirectionBit(DIO_PORTC,DIO_PC0,DIO_OUTPUT);
	/*set Seconds-Tens 7-segment's enable at PB6 and set it as Output*/
	DIO_u8SetDirectionBit(DIO_PORTC,DIO_PC1,DIO_OUTPUT);
	/*set Minutes-Units 7-segment's enable at PB5 and set it as Output*/
	DIO_u8SetDirectionBit(DIO_PORTC,DIO_PC2,DIO_OUTPUT);
	/*set Minutes-Tens 7-segment's enable at PB4 and set it as Output*/
	DIO_u8SetDirectionBit(DIO_PORTC,DIO_PC3,DIO_OUTPUT);
	
	/*initialize all 4 7-segments off*/
	/*=============================================================================*/
	/*disable Seconds' Units 7-segment*/
	DIO_u8WriteBit(DIO_PORTC,DIO_PC0,DIO_LOW);
	/*disable Seconds' Tens 7-segment*/
	DIO_u8WriteBit(DIO_PORTC,DIO_PC1,DIO_LOW);
	/*disable Minutes' Units 7-segment*/
	DIO_u8WriteBit(DIO_PORTC,DIO_PC2,DIO_LOW);
	/*disable Minutes' Tens 7-segment*/
	DIO_u8WriteBit(DIO_PORTC,DIO_PC3,DIO_LOW);
	
	/*==========================================
	 * Variables
	 *==========================================*/
	/*Seconds units value*/
	u8 Local_u8SecondsUnitsCount = 0;
	/*Seconds tens value*/
	u8 Local_u8SecondsTensCount  = 0;
	/*Minutes units value*/
	u8 Local_u8MinutesUnitsCount = 0;
	/*Minutes tens value*/
	u8 Local_u8MinutesTensCount  = 0;
	
	
	/*infinite loop*/
	while (1) 
    {
		
		
		/*loop to display all 7 segments with a delay Dependant on number of iteration*/
		for (u8 i = 0 ; i < DELAY ; i++)
		{
			
			if ( PRESSED == DIO_u8ReadBit(DIO_PORTD,DIO_PD0) )
			{
				/* Start Button has been pressed
				 * Update button status to start*/
				APP_u8StopStartButtonState = START;
	
			}
			else if ( PRESSED == DIO_u8ReadBit(DIO_PORTD,DIO_PD2) )
			{
				/* Stop Button has been pressed
				 * toggle button status*/
				APP_u8StopStartButtonState = STOP;
				//break;
			}
			else if ( PRESSED == DIO_u8ReadBit(DIO_PORTD,DIO_PD1) )
			{
				/*Reset Button has been pressed*/
				/*Stop count*/
				APP_u8StopStartButtonState   = STOP;
				/* Rest counter Digits
				 * Seconds units value*/
				Local_u8SecondsUnitsCount = 0;
				/*Seconds tens value*/
				Local_u8SecondsTensCount  = 0;
				/*Minutes units value*/
				Local_u8MinutesUnitsCount = 0;
				/*Minutes tens value*/
				Local_u8MinutesTensCount  = 0;
				
			}/*end of if statement */
			
			/*================================================================
			 *Display Seconds-Units 7-segment
			 *================================================================*/
			/*enable Seconds-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC0,DIO_HIGH);
			/*disable Seconds-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC1,DIO_LOW);
			/*disable Minutes-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC2,DIO_LOW);
			/*disable Minutes-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC3,DIO_LOW);
			/*set Seconds-Units 7-segment value*/
			SSD_u8DisplayNumber(DIO_PORTB,Local_u8SecondsUnitsCount);
			/*wait*/
			_delay_ms(SEVEN_SEG_DELAY);
			
			/*================================================================
			 *Display Seconds-Tens 7-segment
			 *================================================================*/
			/*disable Seconds-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC0,DIO_LOW);
			/*enable Seconds' Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC1,DIO_HIGH);
			/*disable Minutes-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC2,DIO_LOW);
			/*disable Minutes-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC3,DIO_LOW);
			/*set Seconds-Tens 7-segment value*/
			SSD_u8DisplayNumber(DIO_PORTB,Local_u8SecondsTensCount);
			/*wait*/
			_delay_ms(SEVEN_SEG_DELAY);
			
			/*================================================================
			 *Display Minutes-Units 7-segment
			 *================================================================*/
			/*disable Seconds-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC0,DIO_LOW);
			/*disable Seconds-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC1,DIO_LOW);
			/*enable Minutes-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC2,DIO_HIGH);
			/*disable Minutes-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC3,DIO_LOW);
			/*set Minutes-Units 7-segment value*/
			SSD_u8DisplayNumber(DIO_PORTB,Local_u8MinutesUnitsCount);
			/*wait*/
			_delay_ms(SEVEN_SEG_DELAY);
			
			/*================================================================
			 *Display Minutes-Tens 7-segment
			 *================================================================*/
			/*disable Seconds-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC0,DIO_LOW);
			/*disable Seconds-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC1,DIO_LOW);
			/*disable Minutes-Units 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC2,DIO_LOW);
			/*enable Minutes-Tens 7-segment*/
			DIO_u8WriteBit(DIO_PORTC,DIO_PC3,DIO_HIGH);
			/*set Minutes-Tens 7-segment value*/
			SSD_u8DisplayNumber(DIO_PORTB,Local_u8MinutesTensCount);
			/*wait*/
			_delay_ms(SEVEN_SEG_DELAY);
			
		}/*end of for*/
		
		
		/*if current state is start*/
		if ( START == APP_u8StopStartButtonState )
		{
			/*================================================================
			* Update stopwatch digits values 
			*================================================================*/
		
			/*increment Seconds' Units value*/
			Local_u8SecondsUnitsCount++;
		
			/*when Seconds' Units value reaches 10*/
			if (10 == Local_u8SecondsUnitsCount)
			{
				/*make Seconds' Units value equal 0*/
				Local_u8SecondsUnitsCount = 0;
				/*increment Seconds' Tens value*/
				Local_u8SecondsTensCount++;
			
			}/*end of if*/
			
			/*when Seconds' Tens value reaches 6*/
			if ( 6 == Local_u8SecondsTensCount)
			{
				/*make Seconds' Units  value equal 0*/
				Local_u8SecondsUnitsCount = 0;
				/*make Seconds' Tens  value equal 0*/
				Local_u8SecondsTensCount = 0;
				/*Increment Minutes' Units value*/
				/*increment Seconds' Units value*/
				Local_u8MinutesUnitsCount++;
			}/*end of if*/
		
			/*when Minutes' Units value reaches 10*/
			if (10 == Local_u8MinutesUnitsCount)
			{
				/*make Minutes' Units value equal 0*/
				Local_u8MinutesUnitsCount = 0;
				/*increment Minutes' Tens value*/
				Local_u8MinutesTensCount++;
			
			}/*end of if*/
			
			/*when Minutes' Tens value reaches 6*/
			if ( 6 == Local_u8MinutesTensCount)
			{
				/*make Minutes' Units  value equal 0*/
				Local_u8MinutesUnitsCount = 0;
				/*make Minutes' Tens  value equal 0*/
				Local_u8MinutesTensCount = 0;
			}/*end of if*/
			
		}/*end of status update*/
		
		
	}/*end of infinite loop*/
	
}/*end of main()*/

