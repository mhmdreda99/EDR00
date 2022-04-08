//file guard
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
 // STD_TYPES_H_
// char 8 bits with larger +ve range 255
typedef unsigned char u8;
// char 8 bits 128 for + & -
typedef signed char s8;
// int 16 bits with larger +ve range
typedef unsigned short int u16;
// int 16 bits with 128 for + & -
typedef signed short int s16;
// int 32 bits with larger +ve range
typedef unsigned long int u32;
// int 32 bits with 128 for + & -
typedef signed long int s32;
// float for real value 32 bits
typedef float f32;
// float for real with 64 bits
typedef double f64;

typedef enum
	{
		E_OK, //error found
		E_NOK  //error not found
	}STD_Return;

#endif //end of file guard
