/****************************************************************************
* Title                 :   BIT_CALC   
* Filename              :   BIT_CALC .h
* Author                :   Mohamed Reda
* Origin Date           :   07/05/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/

/*This is preprocessor (Header file) guard  */
#ifndef BIT_CALC_H_
#define BIT_CALC_H_

/******************************************************************/
/* This macro sets a certain bit in any Register                 
/* input : REG: reg name                      
/*         BIT_NUM: number of the bit to be set                 
/******************************************************************/
#define SET_BIT(REG,BIT_NUM) ((REG)|=(1<<(BIT_NUM)))                               


/**************************************************************/
/*This macro clears a certain bit in any Register            
/* input : REG:  reg name                   
/*         BIT_NUM: number of the bit to be cleared         
/*************************************************************/
#define CLEAR_BIT(REG,BIT_NUM) ((REG)&=(~(1<<(BIT_NUM))))                         

/************************************************************/
/*This macro toggles a certain bit in any Register        
/* input : REG: reg name                    
/*         BIT_NUM: number of the bit to be toggle        
/************************************************************/
#define TOGGLE_BIT(REG,BIT_NUM) ((REG)^=(1<<(BIT_NUM)))                          
 
/********************************************************/
/*This macro to get a certain bit in any Register     
/* input : REG: REG name                         
/*         BIT_NUM: number of the bit to get          
/****************************************************/

#define GET_BIT(REG,BIT_NUM) ((REG)>>(BIT_NUM))&(0X01)
/********************************************************/
/*This macro to check if  a certain bit is set to 1 in any Register     
/* input : REG: REG name                         
/*         BIT_NUM: number of the bit to get          
/****************************************************/
#define IS_BIT_SET(REG,BIT_NUM)      ((REG)   &  (1<< BIT_NUM))
/********************************************************/
/*This macro to check if  a certain bit is cleared  in any Register     
/* input : REG: REG name                         
/*         BIT_NUM: number of the bit to get          
/****************************************************/
#define IS_BIT_CLEAR(REG,BIT_NUM)    (!(IS_BIT_SET(REG,BIT_NUM)))

/*********************************************************/
/*This macro assign a certain bit in any Register    
/* input : REG: reg name               
/*         BIT_NUM: number of the bit to be assign     
/*        VAL: value of bit to assign the macro with 
/********************************************************/
/*if VAL == 1 assign the bit with 1 value otherwise assign it with 0 value */
#define VAL 1
#define BITCALC_ASSIGN_BIT(REG,BIT_NUM,VAL) REG=((REG)&(~(1<<(BIT_NUM))))|(VAL<<(BIT_NUM))
#endif 