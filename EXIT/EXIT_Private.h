/*
 * EXIT_Private.h
 *
 *  Created on: Dec 6, 2020
 *      Author: neutr
 */

#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_


#define SREG    *( (u8*) 0x5F)
#define I    	7

#define GICR    *( (u8*) 0x5B)
#define INT0	6
#define INT1	7
#define INT2	5

#define GIFR    *( (volatile u8*) 0x5A)
#define INTF0	6
#define INTF1	7
#define INTF2	5

#define MCUCR   *( (u8*) 0x55)
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

#define MCUCSR  *( (u8*) 0x54)
#define ISC2	6

#define NULL_PTR	0

void __vector_1(void) __attribute__((signal));

void __vector_2(void) __attribute__((signal));

void __vector_3(void) __attribute__((signal));


#endif /* EXIT_PRIVATE_H_ */
