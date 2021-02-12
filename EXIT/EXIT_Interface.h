/*
 * EXIT_Interface.h
 *
 *  Created on: Dec 6, 2020
 *      Author: neutr
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_



void EXT0_Interrupt_Handle(void(*a_ptr)(void));
void EXT1_Interrupt_Handle(void(*a_ptr)(void));
void EXT2_Interrupt_Handle(void(*a_ptr)(void));

void EXT0_init();

void EXT1_init();

void EXT2_init();

#endif /* EXIT_INTERFACE_H_ */
