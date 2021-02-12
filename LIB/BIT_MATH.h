
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)
#define SET_REG(port,value)	(port)|= (value)
#define GET_REG(port) 		((port)) & 0x01)

#endif
