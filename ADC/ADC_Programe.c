/*
 * ADC_Programe.c
 *
 *  Created on: Dec 7, 2020
 *      Author: neutr
 */
#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "ADC_Interface.h"
#include  "ADC_Private.h"
#include "ADC_Config.h"


void ADC_init()
{

	// AREFF is set to AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	// Right Adjust Result
	CLR_BIT(ADMUX,ADLAR);
	// run in single conversion mode
	CLR_BIT(ADCSRA,ADATE);
	// Select prescaller
#if PRESCALLER == PSC_2

	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

#elif PRESCALLER == PSC_4

	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

#elif PRESCALLER == PSC_8

	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

#elif PRESCALLER == PSC_16

	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

#elif PRESCALLER == PSC_32

	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

#elif PRESCALLER == PSC_64

	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

#elif PRESCALLER == PSC_128

	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#endif
// enable ADC
ADC_EN(ON);

}

void ADC_EN(u8 ON_OFF)
{
	if ( ON == ON_OFF)
	{
		SET_BIT(ADCSRA,ADEN);
	}
	else if (OFF == ON_OFF)
	{
		CLR_BIT(ADCSRA,ADEN);
	}
}

u16 ADC_Read_Channle(u8 Channle)
{
	u16 channel_value = 0;

	// select channel to read from
	SET_REG(ADMUX,Channle);

	// start conversion
	SET_BIT(ADCSRA,ADSC);

	// wait till conversion is completed
	while ( 1 == GET_BIT(ADCSRA,ADIF));
	channel_value = ADC_DATA;

	//Clear interrupt flag
	SET_BIT(ADCSRA,ADIF);

	return channel_value;
}
