/*
 * File        : DIO_Interface.h
 * Description : This interface file includes DIO Driver prototypes and difinitions for Atmega32
 * Author      : Mohamed reda 
 * Date        : 18/4/2022
 * Git account : https://github.com/mhmdreda99
 * mail        : dev.mhmdreda99@gmail.com
 */


#ifndef __DIO_Interface_H__
#define __DIO_Interface_H__
#include "../LIB/STD_TYPES.h"
#include "../LIB/STD_MACROS.h"

/*==============================================================================================================================================
 * macros used with I/O
 *==============================================================================================================================================*/

#define DIO_EN_PULL_UP_RES     1
#define DIO_DIS_PULL_UP_RES    0

#define DIO_OUTPUT  1
#define DIO_INPUT   0
#define DIO_HIGH    1
#define DIO_LOW     0
#define DIO_ON      1
#define DIO_OFF     0


/*define ports*/
#define DIO_PORTA   1
#define DIO_PORTB   2
#define DIO_PORTC   3
#define DIO_PORTD   4

/*PORTA PINS*/
#define DIO_PA0     0
#define DIO_PA1     1
#define DIO_PA2     2
#define DIO_PA3     3
#define DIO_PA4     4
#define DIO_PA5     5
#define DIO_PA6     6
#define DIO_PA7     7

/*PORTB PINS*/
#define DIO_PB0     0
#define DIO_PB1     1
#define DIO_PB2     2
#define DIO_PB3     3
#define DIO_PB4     4
#define DIO_PB5     5
#define DIO_PB6     6
#define DIO_PB7     7

/*PORTC PINS*/
#define DIO_PC0     0
#define DIO_PC1     1
#define DIO_PC2     2
#define DIO_PC3     3
#define DIO_PC4     4
#define DIO_PC5     5
#define DIO_PC6     6
#define DIO_PC7     7

/*PORTD PINS*/
#define DIO_PD0     0
#define DIO_PD1     1
#define DIO_PD2     2
#define DIO_PD3     3
#define DIO_PD4     4
#define DIO_PD5     5
#define DIO_PD6     6
#define DIO_PD7     7

/*==============================================================================================================================================
 * Direction modules
 *==============================================================================================================================================*/
 
/**
 * @brief 
 * Prototype   : u8 DIO_u8SetDirectionReg(u8 u8Reg,u8 u8Status);
 * Description : Set direction of the whole register
 * 
 * @param u8Reg : Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD 
 * @param u8Status Status  : takes INPUT sets whole reg i/p,OUTPUT sets whole reg o/p, or Custom -(0-255)values- DDRx values
 * @return u8 : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument 
 */

u8 DIO_u8SetDirectionReg(u8 u8Reg,u8 u8Status);


/**
 * @brief 
 *  Prototype   : u8 DIO_u8SetDirectionBit(u8 u8Reg,u8 u8Bit,u8 u8Status);
 * Description : Set direction of one bit of the register
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @param u8Status Status  : takes only INPUT,OUTPUT 
 * @return u8 u8 number used for error handling
 *			 (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means status value out of range
 */
u8 DIO_u8SetDirectionBit(u8 u8Reg,u8 u8Bit,u8 u8Status);

/*==============================================================================================================================================
 * Write modules
 *==============================================================================================================================================*/


/**
 * @brief 
 * Prototype   : u8 DIO_u8WriteReg(u8 u8Reg,u8 u8Value);
 * Description : write o/p to  the whole register
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD 
 * @param u8Value Value  : takes HIGH sets whole reg high,LOW sets whole reg low, or Custom -(0-255)values- PORTx values
 * @return u8  : number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8WriteReg(u8 u8Reg,u8 u8Value);


/**
 * @brief 
 *  Prototype   : u8 DIO_u8WriteBit(u8 u8Reg,u8 u8Bit,u8 u8Value);
 * Description : Write value of one bit of the register
 * 
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit  bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @param u8Value Value  : takes only HIGH,LOW 
 * @return u8       u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 DIO_u8WriteBit(u8 u8Reg,u8 u8Bit,u8 u8Value);

/**
 * @brief 
 *  Prototype   : u8 DIO_u8ToggleReg(u8 u8Reg);
 * Description : Toggles pin values of the whole register
 * 
 * @param u8Reg  Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD 
 * @return u8 u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */

u8 DIO_u8ToggleReg(u8 u8Reg);

/**
 * @brief 
 * Prototype   : u8 DIO_u8ToggleBit(u8 u8Reg,u8 u8Bit);
 * Description : Toggle pin value of one bit of the register
 * @param u8Reg  Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit Bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @return u8  u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */

u8 DIO_u8ToggleBit(u8 u8Reg,u8 u8Bit);


/*==============================================================================================================================================
 * Read modules
 *==============================================================================================================================================
 */


/**
 * @brief 
 * Prototype   : u8 DIO_u8ReadReg(u8 u8Reg);
 * Description : Read i/p of the whole register
 * 
 * @param u8Reg Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD 
 * @return u8   Register reading of type u8, it will always return 240(0xAA)(0b10101010) in case of Undefined Port error
 *              whatever the actual reading is 
 */         
u8 DIO_u8ReadReg(u8 u8Reg);


/**
 * @brief 
 * Prototype   : u8 DIO_u8ReadBit(u8 u8Reg,u8 u8Bit);
 * Description : Read pin value of one bit of the register
 * @param u8Reg  Register: takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8Bit Bit     : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PB6,DIO_PD2....
 * @return u8    u8 actual reading (0 or 1) or number used for error handling
 *			     (2) means Undefined PORT Argument, (3) means Bit number out of range
 */
u8 DIO_u8ReadBit(u8 u8Reg,u8 u8Bit);

 
/*==============================================================================================================================================
 * enable pullup res modules
 *==============================================================================================================================================*/


/**
 * @brief 
 * Prototype   : u8 DIO_u8ConfigPullupReg(u8 u8Reg,u8 u8PullUpResStatus);
 * Description : Configure pullup Res status for the whole register
 * 
 * @param u8Reg  Register    : takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param u8PullUpResStatus pull up res : takes only DIO_EN_PULL_UP_RES (will enable it for the whole reg) or 
 *                             DIO_DIS_PULL_UP_RES (will disable it for the whole reg) or a custom value
 * @return u8  u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8ConfigPullupReg(u8 u8Reg,u8 u8PullUpResStatus);


/**
 * @brief 
 * Prototype   : u8 DIO_u8ConfigPullupBit(u8 u8Reg,u8 u8Bit,u8 u8PullUpResStatus);
 * Description : Configure pullup Res status for on a given bit and port 
 * 
 * @param u8Reg Register    : takes only DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD 
 * @param u8Bit Bit         : takes only DIO_Px0,DIO_Px1,DIO_Px2,DIO_Px3,DIO_Px4,DIO_Px5,DIO_Px6,DIO_Px7 ex: DIO_PA0,DIO_PD2....
 * @param u8PullUpResStatus pull up res : takes only DIO_EN_PULL_UP_RES or DIO_DIS_PULL_UP_RES
 * @return u8   number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means pull up 
 *               resistor status value out of range
 */

u8 DIO_u8ConfigPullupBit(u8 u8Reg,u8 u8Bit,u8 u8PullUpResStatus);

#endif /* END OF DIO_PRIVATE_H_FILE */
