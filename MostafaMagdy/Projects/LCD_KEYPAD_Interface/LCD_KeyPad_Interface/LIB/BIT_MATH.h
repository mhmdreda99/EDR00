/*
 * file           BIT_MATH.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*This is preprocessor Header file guard  */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*********************************************************/
/* Macro for set a certian bit in a register
 *  Input: Reg:     Register name that contain the bit
 *         BIT_NO:  bit number that to be Set
 *
 */
/*********************************************************/  

#define SET_BIT(Reg,BIT_NO)           (Reg|=(1<<BIT_NO))

/*********************************************************/
/* Macro for Clear a certian bit in a register
 *  Input: Reg:     Register name that contain the bit
 *         BIT_NO:  bit number that to be Clear
 *
 */
/*********************************************************/ 

#define CLEAR_BIT(Reg,BIT_NO)         (Reg&=(~(1<<BIT_NO)))

/*********************************************************/
/* Macro for Toggle a certian bit in a register
 *  Input: Reg:     Register name that contain the bit
 *         BIT_NO:  bit number that to be Toggle
 *
 */
/*********************************************************/ 

#define TOGGLE_BIT(Reg,BIT_NO)        (Reg^=(1<<BIT_NO))

/*********************************************************/
/* Macro for Get Value a certian bit in a register
 *  Input: Reg:     Register name that contain the bit
 *         BIT_NO:  bit number that to be Read/Value get
 *
 */
/*********************************************************/ 

#define GET_BIT(Reg,BIT_NO)			((Reg & (1<<BIT_NO))?1:0)

/*This is preprocessor Header file guard End  */
#endif 
