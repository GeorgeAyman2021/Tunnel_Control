/*
 * Timer0_Prog.c
 *
 *  Created on: Dec 15, 2020
 *      Author: 20122
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO/DIO_INTERFACE.h"
#include "Timer0_config.h"
#include "Timer0_Private.h"


static volatile void (*callBackPtr)(void) = NULL_PTR;  /*initiat function to point to null*/


void Timer0_Interrupt_Handle(void(*a_ptr)(void))
{
	callBackPtr = a_ptr; /*give address function processing to the pointer pointer*/
}

void __vector_11()
{
	if(callBackPtr != NULL_PTR)
			{

			/* Call the Call Back function in the application after the edge is detected */
				(*callBackPtr)();
			}
}


u16 count=0;
/*
void __vector_11() //Normal Mode Interrupt
{
	count++;
	if(count==count_check)
	{
		TCNT0=PRELOAD;
		count=0;
		DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
	}
}*/
void __vector_10()// CTC Mode Interrupt
{
	count++;
	if(count==count_check)
	{
		DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
		count=0;
	}
}

void Timer0_voidSetDuty(f32 Copy_F32Duty)
{
	u8 Duty=(u8)((Copy_F32Duty/100)*256);
#if  PWM_Mode==PWM_NonInvert
	OCR0=Duty;
#elif PWM_Mode==PWM_Invert
	OCR0=256-Duty;
#endif
}
void Timer0_voidInit()
{

#if Timer_Mode == NORMAL
	TCNT0=PRELOAD;
	SET_BIT(TIMSK,TOIE0); //Timer/Counter0 Overflow Interrupt Enable
	CLR_BIT(TIMSK,OCIE0);

#elif Timer_Mode == CTC
	OCR0=OCR0Data;
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TIMSK,OCIE0); //Timer/Counter0 Output Compare Match Interrupt Enable
	CLR_BIT(TIMSK,TOIE0);
#elif Timer_Mode == PWM_PHC

	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	Timer0_voidSetDuty(PWM_Init_Duty);
#if PWM_Mode==PWM_NORMAL
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif PWM_Mode==PWM_Reserved
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif PWM_Mode==PWM_NonInvert
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif PWM_Mode==PWM_Invert
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
#elif Timer_Mode == Fast_PWM
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	Timer0_voidSetDuty(PWM_Init_Duty);
#if PWM_Mode==PWM_NORMALPORT
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif PWM_Mode==PWM_Reserved
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif PWM_Mode==PWM_NonInvert
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif PWM_Mode==PWM_Invert
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif

#endif

#if PRESCALLER == SCALE_1
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
#elif PRESCALLER ==SCALE_8
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
#elif PRESCALLER ==SCALE_64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
#elif PRESCALLER ==SCALE_256
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
#elif PRESCALLER ==SCALE_1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
#elif PRESCALLER ==EXT_CLK_FALLING
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
#elif PRESCALLER ==EXT_CLK_RISING
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
#endif

}
