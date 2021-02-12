/*
 * FAN_Prog.c
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */



#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../Timer1/Timer1_Init.h"
#include "../DIO/DIO_INTERFACE.h"
void FAN_VidInit(void)
{
	Timer1_voidInit();
}
void FAN_VidSetSpeed(u8 Copy_U8Speed)
{
	if (Copy_U8Speed == 0)
	{
		Timer1_voidSetDutyCHB(0);
	}
	else if (Copy_U8Speed == 1)
	{
		Timer1_voidSetDutyCHB(20);
	}
	else if (Copy_U8Speed == 2)
	{
		Timer1_voidSetDutyCHB(40);
	}
	else if (Copy_U8Speed == 3)
	{
		Timer1_voidSetDutyCHB(60);
	}
	else if (Copy_U8Speed == 4)
	{
		Timer1_voidSetDutyCHB(80);
	}
	else if (Copy_U8Speed == 5)
	{
		Timer1_voidSetDutyCHB(100);
	}
}
void FAN_VidSetDirection(u8 Copy_U8Dir)
{
	if (Copy_U8Dir== 0)
	{
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
	}
	else if (Copy_U8Dir== 1)
	{
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
	}

}

