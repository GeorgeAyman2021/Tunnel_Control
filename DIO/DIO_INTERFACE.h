/*Auther	:Abanoub Raouf Kereakos
  Date  	:29/11/2020
  Vertion	:version 1
  Desc		:							*/


#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


#define DIO_HIGH 1
#define DIO_LOW  0

#define DIO_INPUT  0
#define DIO_OUTPUT 1



void DIO_VidSetPortDirection(u8 Copu_U8Port,u8 Copy_U8Direcion);
void DIO_VidSetPinDirection (u8 Copy_U8Port,u8 Copy_u8Pin ,u8 Copy_u8Direction);
u8 DIO_U8GetPortValue		(u8 Copy_U8Port);
void DIO_VidSetPortValue	(u8 Copy_U8Port,u8 Copy_U8Value);
void DIO_VidSetPinValue		(u8 Copy_U8Port,u8 Copy_u8Pin,u8 Copy_U8Value);
void DIO_VidTogglePin		(u8 Copy_U8Port,u8 Copy_u8Pin );
u8 DIO_U8GetPinValue		(u8 Copy_U8Port,u8 Copy_u8Pin);
void DIO_VoidSendMostNebble(u8 Copy_U8Port,u8 Copy_U8Status);
void DIO_VoidSendLeastNebble(u8 Copy_U8Port,u8 Copy_U8Status);



#endif
