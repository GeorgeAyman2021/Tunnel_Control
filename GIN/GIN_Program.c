/*
 * GIN_Program.c
 *
 *  Created on: Jan 1, 2021
 *      Author: Abanoub Raouf
 */
#include"../LIB/BIT_MATH.h"
#include"../LIB/STD_TYPES.h"
#include"GIN.PRIVATE.h"

void Enable_VidGlobal(void)
{
	//	global Interrupt enable
	SET_BIT(SREG,7);
}
void Disable_VidGlobal(void)
{
	//	global Interrupt disable
	CLR_BIT(SREG,7);
}
