/*
 * Timer0.h
 *
 *  Created on: Dec 15, 2020
 *      Author: 20122
 */

#ifndef TIMER0_INIT_H_
#define TIMER0_INIT_H_


void Timer0_Interrupt_Handle(void(*a_ptr)(void));
void Timer0_voidInit(void);
void Timer0_voidSetDuty(f32 Copy_F32Duty);
#endif /* TIMER0_INIT_H_ */
