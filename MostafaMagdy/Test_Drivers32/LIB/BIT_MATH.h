//file guard
#ifndef BIT_MATH_H_
#define BIT_MATH_H_
//X is the variable number
#define SET_BIT(X,BIT_NO)           (X|=(1<<BIT_NO))
#define CLEAR_BIT(X,BIT_NO)         (X&=(~(1<<BIT_NO)))
#define TOGGLE_BIT(X,BIT_NO)        (X^=(1<<BIT_NO))
#define GET_BIT(X,BIT_NO)           ((X>>BIT_NO)&1)
#endif //end of file guard
