/*
 * SMOKE_Prog.c
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO/DIO_INTERFACE.h"

u8 SMOKE_U8Read(u8 Copy_U8PORT , u8 Copy_u8PIN )
{
	return DIO_U8GetPinValue(Copy_U8PORT,Copy_u8PIN);
}
