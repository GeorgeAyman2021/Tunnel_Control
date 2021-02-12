/*
 * Timer0_Private.h
 *
 *  Created on: Dec 15, 2020
 *      Author: 20122
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0	*((volatile u8*)0x53)
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

#define TIMSK	*((volatile u8*)0x59)
#define TOIE0	0
#define OCIE0	1

#define TCNT0 	*((volatile u8*)0x52)

#define SREG   *((volatile u8*)0x5F)

#define OCR0   *((volatile u8*)0x5C)


#define NULL_PTR	0
void __vector_11() __attribute__((signal));
void __vector_10() __attribute__((signal));


#endif /* TIMER0_PRIVATE_H_ */
