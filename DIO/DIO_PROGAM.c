/*Auther	:Abanoub Raouf Kereakos
  Date  	:29/11/2020
  Vertion	:version 1
  Desc		:							*/
  
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"DIO_REGISTER.h"

void DIO_VidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Direcion)
{
		switch(Copy_U8Port)
		{
			case 0 :DDRA=Copy_U8Direcion;break;
			case 1 :DDRB=Copy_U8Direcion;break;
			case 2 :DDRC=Copy_U8Direcion;break;
			case 3 :DDRD=Copy_U8Direcion;break;
		}
}
void DIO_VidSetPortValue	(u8 Copy_U8Port,u8 Copy_U8Value)
{
		switch(Copy_U8Port)
		{
			case 0 :PORTA=Copy_U8Value;break;
			case 1 :PORTB=Copy_U8Value;break;
			case 2 :PORTC=Copy_U8Value;break;
			case 3 :PORTD=Copy_U8Value;break;
	}
}
u8 DIO_U8GetPortValue(u8 Copy_U8Port)
{
	u8 temp;
	switch (Copy_U8Port)
	{
		case 0:temp=PINA;break;
		case 1:temp=PINB;break;
		case 2:temp=PINC;break;
		case 3:temp=PIND;break;
	}

	return temp;
}
void DIO_VidSetPinDirection (u8 Copy_U8Port,u8 Copy_u8Pin ,u8 Copy_u8Direction)
{
	if (1 == Copy_u8Direction)
	{
		switch(Copy_U8Port)
		{
			case 0 :SET_BIT(DDRA,Copy_u8Pin);break;
			case 1 :SET_BIT(DDRB,Copy_u8Pin);break;
			case 2 :SET_BIT(DDRC,Copy_u8Pin);break;
			case 3 :SET_BIT(DDRD,Copy_u8Pin);break;
		}

	}
	else if (0 == Copy_u8Direction)
	{
		switch(Copy_U8Port)
		{
			case 0:CLR_BIT(DDRA,Copy_u8Pin);	break;
			case 1:CLR_BIT(DDRB,Copy_u8Pin);	break;
			case 2:CLR_BIT(DDRC,Copy_u8Pin);	break;
			case 3:CLR_BIT(DDRD,Copy_u8Pin);	break;
		}

	}
	else
	{
		
	}
}
void DIO_VidSetPinValue		(u8 Copy_U8Port,u8 Copy_u8Pin,u8 Copy_U8Value)
{
	if (1 == Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case 0:SET_BIT(PORTA,Copy_u8Pin);break;
			case 1:SET_BIT(PORTB,Copy_u8Pin);break;
			case 2:SET_BIT(PORTC,Copy_u8Pin);break;
			case 3:SET_BIT(PORTD,Copy_u8Pin);break;
		}

	}
	else if (0 == Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case 0:CLR_BIT(PORTA,Copy_u8Pin);	break;
			case 1:CLR_BIT(PORTB,Copy_u8Pin);	break;
			case 2:CLR_BIT(PORTC,Copy_u8Pin);	break;
			case 3:CLR_BIT(PORTD,Copy_u8Pin);	break;
		}

	}
	else
	{
		
	}
}
u8 DIO_U8GetPinValue		(u8 Copy_U8Port,u8 Copy_u8Pin)
{
	u8 value;
	switch(Copy_U8Port)
	{
		case 0:value=GET_BIT(PINA,Copy_u8Pin);break;
		case 1:value=GET_BIT(PINB,Copy_u8Pin);break;
		case 2:value=GET_BIT(PINC,Copy_u8Pin);break;
		case 3:value=GET_BIT(PIND,Copy_u8Pin);break;
	}
	return value;
}
void DIO_VidTogglePin		(u8 Copy_U8Port,u8 Copy_u8Pin )
{
	switch(Copy_U8Port)
	{
		case 0:TOG_BIT(PORTA,Copy_u8Pin);break;
		case 1:TOG_BIT(PORTB,Copy_u8Pin);break;
		case 2:TOG_BIT(PORTC,Copy_u8Pin);break;
		case 3:TOG_BIT(PORTD,Copy_u8Pin);break;
	}
}
void DIO_VoidSendMostNebble(u8 Copy_U8Port,u8 Copy_U8Status)
{
    Copy_U8Status&=0xF0;
    switch (Copy_U8Port)
        {
        case 0: PORTA&=0x0F;PORTA|=Copy_U8Status ;break;
        case 1: PORTB&=0x0F;PORTB|=Copy_U8Status ; ;break;
        case 2: PORTC&=0x0F;PORTC|=Copy_U8Status ; ;break;
        case 3: PORTD&=0x0F;PORTD|=Copy_U8Status ; ;break;
        }

}
void DIO_VoidSendLeastNebble(u8 Copy_U8Port,u8 Copy_U8Status)
{
    Copy_U8Status&=0x0F;
    switch (Copy_U8Port)
        {
        case 0: PORTA&=0xF0;PORTA|=Copy_U8Status ;break;
        case 1: PORTB&=0xF0;PORTB|=Copy_U8Status ; ;break;
        case 2: PORTC&=0xF0;PORTC|=Copy_U8Status ; ;break;
        case 3: PORTD&=0xF0;PORTD|=Copy_U8Status ; ;break;
        }

}
  
