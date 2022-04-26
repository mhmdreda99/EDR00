/****************************************************************************
* Title                 :   STD_TYPES   
* Filename              :   STD_TYPES.h
* Author                :   Mohamed Reda 
* Origin Date           :   07/5/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: ATmega32
* Notes                 :   None
*
*****************************************************************************/
/* Preprocessor Guard        */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#define HIGH        (1u)
#define LOW         (0u)

/* define the pointer to NULL */
#define NULL ((void *)0)

/* User defined different Data Types                 */
/* Unsigned 8 bit type       */
typedef unsigned char        u8  ;
/* Unsigned 16 bit type      */
typedef unsigned short int   u16 ;
/* Unsigned 32 bit type      */
typedef unsigned long int    u32 ;
/* Unsigned 64 bit type      */
typedef unsigned long long   u64; 
/* Signed 8 bit type         */
typedef signed char          s8  ;
/* Signed 16 bit type        */
typedef signed short int     s16 ;
/* Signed 32 bit type        */
typedef signed long int      s32 ;
/* Signed 64 bit type        */
typedef signed long long     s64;
/* Floating type 32 bit      */
typedef float                f32 ;
/* Floating type 64 bit      */
typedef double               f64 ;


/* User defined union Data Type to access bits and bytes */
typedef union{
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
		u8 Bit8 : 1;
		u8 Bit9 : 1;
		u8 Bit10 :1;
		u8 Bit11 :1;
		u8 Bit12 :1;
		u8 Bit13 :1;
		u8 Bit14 :1;
		u8 Bit15 :1;
		u8 Bit16 :1;
		u8 Bit17 :1;
		u8 Bit18 :1;
		u8 Bit19 :1;
		u8 Bit20 :1;
		u8 Bit21 :1;
		u8 Bit22 :1;
		u8 Bit23 :1;
		u8 Bit24 :1;
		u8 Bit25 :1;
		u8 Bit26 :1;
		u8 Bit27 :1;
		u8 Bit28 :1;
		u8 Bit29 :1;
		u8 Bit30 :1;
		u8 Bit31 :1;
	}BitAccess;
	u32 FourByteAccess;
}Register_32Bit;

/* Any component will return error so we define the error here as it is common across all the modules*/
#define ERROR_NOK             (u8)0
#define ERROR_OK              (u8)1



#endif /* STD_TYPES_H_ */