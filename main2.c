/*
 * main.c
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_INTERFACE.h"
#include "LCD/LCD_Init.h"
#include "Timer0/Timer0_Init.h"
#include "Timer1/Timer1_Init.h"
#include "UART/UART_INTERFACE.h"
#include "GIN/GIN.INTERFACE.h"
#include "ADC/ADC_Interface.h"
#include "EXIT/EXIT_Interface.h"
#include "util/delay.h"
#include "TempSensor/Temp_Init.h"
#include "FAN/FAN_Init.h"
#include "FLAME/FLAME_Init.h"
#include "IR/IR_Init.h"
#include "SERVO/SERVO_Init.h"
#include "SMOKE/SMOKE_Init.h"
#include "BLUETOOTH/BLUETOOTH_Init.h"
#include "main_define.h"

u8 UART_FLAG=0;
//IR Cars Count
void Exit0_ISR(void)
{
	UART_FLAG=1;
}

void main(void)
{
	//BLUETOOTH
	DIO_VidSetPinDirection(BLUETOOTH_PORT,BLUETOOTH_RX,DIO_INPUT);
	DIO_VidSetPinDirection(BLUETOOTH_PORT,BLUETOOTH_TX,DIO_OUTPUT);
	BLUETOOTH_VidInit();
	//IR
	DIO_VidSetPinDirection(IR_PORT,IR_PIN,DIO_INPUT);
	//Exit
	EXT0_init();
	EXT0_Interrupt_Handle(Exit0_ISR);
	//Global Interrupt Enable
	Enable_VidGlobal();

	while(1)
	{
		if (UART_FLAG==1)
		{
			BLUETOOTH_VidSendCarCount(0x50);
			UART_FLAG=0;
		}
	}
}
