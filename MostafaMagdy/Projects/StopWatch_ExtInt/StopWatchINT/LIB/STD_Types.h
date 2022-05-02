/*
 * @file 		  STD_Types.h
 * @author  	  MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version		  0.1
 * @date		  2022-04-26
 *
 * @copyright Copyright (c) 2022
 * 
 * Description : User defined data types
 */

/*This is preprocessor Header file guard  */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/******************************************************************************************************/
/* 	User Define DataTypes	*/

/* 	unsigned char 8 bits with larger +ve range 255		*/
typedef unsigned char u8;
/******************************************************************************************************/
/* 	signed char 8 bits with range 128 for + & -   		*/
typedef signed char s8;
/******************************************************************************************************/
/*	unsigned short int 16 bits with larger +ve range	*/
typedef unsigned short int u16;
/******************************************************************************************************/
/* 	signed short int 16 bits with range 128  for + &-	*/
typedef signed short int s16;
/******************************************************************************************************/
/* 	unsigned long int 32 bits with larger +ve range   	*/
typedef unsigned long int u32;
/******************************************************************************************************/
/*	signed long int 32 bits with range 128  for + & - 	*/
typedef signed long int s32;
/******************************************************************************************************/
/* 			float for real value 32 bits				*/
typedef float f32;
/******************************************************************************************************/
/* 			float for real value 64 bits				*/
typedef double f64;
/******************************************************************************************************/

/* enum for Error Return */
/* E_OK  : 	Error Return 
/* E_NOK :	No Error Returend
*/
typedef enum
	{
		E_OK, 
		E_NOK  
	}STD_Return;
/******************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif 
