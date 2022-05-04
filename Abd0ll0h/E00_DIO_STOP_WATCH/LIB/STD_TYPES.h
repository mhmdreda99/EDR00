/***********************************************************/
/***********************************************************/
/*******************	Author:Abd0ll0h	********************/
/*******************	Layer:LIB		********************/
/*******************	Version:1.0		********************/
/***********************************************************/
/***********************************************************/

#ifndef STD_TYPES_H_INCLUDED
#define STD_TYPES_H_INCLUDED

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;


typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;


typedef float f32;
typedef double f64;

//Data type used as indication	if process completed successfully (P_OK) return 0
//								if process completed unsuccessfully (P_NOK) return 1
typedef enum
{
	P_OK,
	P_NOK
}STD_return_t;
#endif // STD_TYPES_H_INCLUDED
