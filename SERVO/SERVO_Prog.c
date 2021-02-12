/*
 * SERVO_Prog.c
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../Timer1/Timer1_Init.h"

void SERVO_VidInit(void)
{
	Timer1_voidInit();
}
void SERVO_VidSet(u8 Copy_U8Set)
{
	if (Copy_U8Set == 1) //OPEN DOOR
	{
		Timer1_voidSetDutyCHA(1); 	//Test And Change This Number
	}
	else if (Copy_U8Set == 0) //CLOSE DOOR
	{
		Timer1_voidSetDutyCHA(6);	//Test And Change This Number
	}
}
