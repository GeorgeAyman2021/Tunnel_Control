/*
 * UART_CONFG.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Abanoub Raouf
 */

#ifndef UART_CONFG_H_
#define UART_CONFG_H_

//***********************************************************************************************************
#define	Normal	0
#define	Double	1
#define	Transmission_Speed 	Normal
//***********************************************************************************************************
#define	Normal_P		0
#define	multi_P			1
#define	processor_Communication_Mode	Normal_P
//***********************************************************************************************************
#define	Enable_RX_Interrupt		1
#define Disable_RX_Interrupt	0
#define RX_Complete_Interrupt	Disable_RX_Interrupt
//***********************************************************************************************************
#define Enable_TX_Interrupt		1
#define Disable_TX_Interrupt	0
#define TX_Complete_Interrupt 	Disable_TX_Interrupt
//***********************************************************************************************************
#define	Enable		1
#define	Disable		0
#define USART_Data_Register_Empty Disable
//***********************************************************************************************************
#define	Enable_RX		1
#define	Disable_RX		0
#define	 Receiver		Enable_RX
//***********************************************************************************************************
#define	Enable_TX		1
#define	Disable_TX		0
#define	Transmitter	Enable_TX
//***********************************************************************************************************
#define Asynchronous	0
#define	Synchronous		1
#define USART_Mode_Select	Asynchronous
//***********************************************************************************************************
#define	Disabled_Parity			0
#define	Enabled_Even_Parity		2
#define	Enabled_Odd_Parity		3
#define Parity_Mode		Disabled_Parity
//***********************************************************************************************************
#define	_1_bit		0
#define	_2_bit		1
#define	Stop_Bit	_1_bit
//***********************************************************************************************************
#define	_5_bit		0
#define	_6_bit		1
#define	_7_bit		2
#define	_8_bit		3
#define	_9_bit		7
#define Character_Size	_8_bit
//***********************************************************************************************************
//This bit is used for Synchronous mode only. Write this bit to zero when Asynchronous mode is used
#define Transmitted_Data_Changed_Rising_Edge_and_Received_Data_Sampled_Falling_Edge		0
#define Transmitted_Data_Changed_Falling_Edge_and_Received_Data_Sampled_Rising_Edge		1
#define	Clock_Polarity			 Transmitted_Data_Changed_Rising_Edge_and_Received_Data_Sampled_Falling_Edge
//***********************************************************************************************************
//#define	_2400_		0
#define	_4800_		1
#define _9600_		2
#define	_14400_		3
#define	_19200_		4
#define	_28800_		5
#define	_38400_		6
#define	_57600_		7
#define	_76800_		8
#define	_115200_	9
#define	_230400_	10
#define	_250000_	11
#define	Baud_Rate	_9600_
//***********************************************************************************************************




#endif /* UART_CONFG_H_ */
