/*
 * UART_INTERFACE.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Abanoub Raouf
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Interrupt_Handle(void(*a_ptr)(void));
void UART_VidInit(void);
void UART_VidTransmitChar(u8 value);
u8 UART_U16ReciveChar(void);
void UART_VidTransmit_string(const u8 *string);



#endif /* UART_INTERFACE_H_ */
