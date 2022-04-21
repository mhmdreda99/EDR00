/*
 * STD_MACROS.h
 *
 *  Created on: Apr 19, 2022
 *      Author: user
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_


int GET_BIT(int number,int bit)
{
	return (number & (1<<bit));
}
int SET_BIT(int number,int bit)
{
	return (number|(1<<bit));
}
int CLEAR_BIT(int number,int bit)
{
	return (number&(~(1<<bit)));
}


#endif /* STD_MACROS_H_ */
