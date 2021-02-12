/*
 * BLUETOOTH_Prog.c
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../UART/UART_INTERFACE.h"


void BLUETOOTH_VidInit(void)
{
	UART_VidInit();
}
void BLUETOOTH_VidSendCarCount(u8 Copy_U8Data)
{
	UART_VidTransmitChar(Copy_U8Data);
}
u8 BLUETOOTH_U8ReciveCarCount(void)
{
	return UART_U16ReciveChar();
}
