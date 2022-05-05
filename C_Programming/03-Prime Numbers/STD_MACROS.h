/*/
 * STD_MACROS.h
 *
 *  Created on: Apr 19, 2022
 *      Author: user
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_

////This macro used to read a specific bit in a register
#define READ_BIT(reg,bit)	((reg & (1<<bit))?1:0)

//This macro is used to set a specific bit in a register
#define SET_BIT(reg,bit)	(reg |= (1<<bit))

//This macro is used to clear a specific bit in a register
#define CLEAR_BIT(reg,bit)	(reg &= ~(1<<bit))

//This macro is used to toggle a specific bit in a register
#define TOGGLE_BIT(reg,bit)	(reg ^= (1<<bit))


#endif /* STD_MACROS_H_ */
