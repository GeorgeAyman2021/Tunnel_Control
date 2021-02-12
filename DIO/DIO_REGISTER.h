/*Auther	:Abanoub Raouf Kereakos
  Date  	:29/11/2020
  Vertion	:version 1
  Desc		:							*/
#ifndef _DIO_REGISTER_H
#define _DIO_REGISTER_H

#define DDRA *((u8*)0x3A)
#define DDRB *((u8*)0x37)
#define DDRC *((u8*)0x34)
#define DDRD *((u8*)0x31)

#define PORTA *((u8*)0x3B)
#define PORTB *((u8*)0x38)
#define PORTC *((u8*)0x35)
#define PORTD *((u8*)0x32)

#define PINA *((volatile u8*)0x39)
#define PINB *((volatile u8*)0x36)
#define PINC *((volatile u8*)0x33)
#define PIND *((volatile u8*)0x30)



#endif
