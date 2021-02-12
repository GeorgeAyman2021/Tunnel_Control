#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "EXIT_Private.h"
#include "../DIO/DIO_REGISTER.h"
#include "../DIO/DIO_INTERFACE.h"
#include "EXIT_Config.h"


static volatile void (*callBackPtr0)(void) = NULL_PTR;  /*initiat function to point to null*/
static volatile void (*callBackPtr1)(void) = NULL_PTR;  /*initiat function to point to null*/
static volatile void (*callBackPtr2)(void) = NULL_PTR;  /*initiat function to point to null*/
void EXT0_Interrupt_Handle(void(*a_ptr)(void))
{
	callBackPtr0 = a_ptr; /*give address function processing to the pointer pointer*/
}

void EXT1_Interrupt_Handle(void(*a_ptr)(void))
{
	callBackPtr1 = a_ptr; /*give address function processing to the pointer pointer*/
}

void EXT2_Interrupt_Handle(void(*a_ptr)(void))
{
	callBackPtr2 = a_ptr; /*give address function processing to the pointer pointer*/
}

void __vector_1()
{
	if(callBackPtr0 != NULL_PTR)
			{

			/* Call the Call Back function in the application after the edge is detected */
				(*callBackPtr0)();
			}
}

void __vector_2()
{
	if(callBackPtr1 != NULL_PTR)
			{

			/* Call the Call Back function in the application after the edge is detected */
				(*callBackPtr1)();
			}
}

void __vector_3()
{
	if(callBackPtr2 != NULL_PTR)
			{

			/* Call the Call Back function in the application after the edge is detected */
				(*callBackPtr2)();
			}
}

void EXT0_init()
{
//	set pin direction for interrupt source to pin D4
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
#if I0_CS == FALLING
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
//	configure interrupt source to falling edge
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);

#elif I0_CS == RISING
	//	configure interrupt source to falling edge
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif I0_CS == OCH
	//	configure interrupt source to falling edge
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif I0_CS == LOW
	//	configure interrupt source to falling edge
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#endif
//	enable interrupt 0
	SET_BIT(GICR,INT0);

}
// initiate
void EXT1_init()
{
//	set pin direction for interrupt source to pin D3
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
#if I1_CS == FALLING
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
//	configure interrupt source to falling edge
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);

#elif I1_CS == RISING
	//	configure interrupt source to falling edge
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif I1_CS == OCH
	//	configure interrupt source to falling edge
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif I1_CS == LOW
	//	configure interrupt source to falling edge
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#endif
//	enable interrupt 0
	SET_BIT(GICR,INT0);

}

void EXT2_init()
{
//	set pin direction for interrupt source to pin B2
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);
#if I2_CS == FALLING
	DIO_VidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
//	configure interrupt source to falling edge
	SET_BIT(MCUCSR,ISC2);

#elif I2_CS == RISING
	//	configure interrupt source to falling edge
	SET_BIT(MCUCSR,ISC2);

#endif
//	enable interrupt 0
	SET_BIT(GICR,INT0);

}
/*
void __vector_1(void)
{

TOG_BIT(PORTC,0);

}

void __vector_2(void)
{

}

void __vector_3(void)
{

}*/
