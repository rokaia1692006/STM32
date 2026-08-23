#ifndef BIT_MATH_H
#define BIT_MATH_H 
#include <math.h>

#define SET_BIT(REG,BIT) (REG = REG|(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG &=(~(1<<BIT)))
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)
// xor value 
#define TOGGLE_BIT(REG,BIT) (REG ^=(1 << (BIT)))

#endif