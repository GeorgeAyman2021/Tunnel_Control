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


u8 Car_Counter=0;
u8 Temp_Read=0;
u8 FIRE_FLAG=0;
u8 SMOKE_FLAG=0;

//Read Temp Sensor &
void Timer0_ISR(void)
{
	static u8 Count=0;
	Count++;
	if(Count==count_check)
	{
		Temp_Read=Temp_U8Read();
		if(Temp_Read>0 && Temp_Read<=20)
			FAN_VidSetSpeed(FAN_Speed1);
		else if (Temp_Read>20 && Temp_Read<=25)
			FAN_VidSetSpeed(FAN_Speed2);
		else if (Temp_Read>25 && Temp_Read<=30)
			FAN_VidSetSpeed(FAN_Speed3);
		else if (Temp_Read>30 && Temp_Read<=40)
			FAN_VidSetSpeed(FAN_Speed4);
		else
			FAN_VidSetSpeed(FAN_Speed5);
	}
}

//IR Cars Count
void Exit0_ISR(void)
{
	Car_Counter++;
	while(DIO_U8GetPinValue(IR_PORT,IR_PIN)==1);
}
 

void Counter_Handler(void)
{
	if(Car_Counter == MAX_CAR_COUNTER)
	{
		DIO_VidSetPinValue(LED_PORT,Green_LED_PIN,DIO_LOW);
		DIO_VidSetPinValue(LED_PORT,Red_LED_PIN,DIO_HIGH);
	}
	else if (Car_Counter <= Allow_CAR_COUNTER)
	{
		DIO_VidSetPinValue(LED_PORT,Green_LED_PIN,DIO_HIGH);
		DIO_VidSetPinValue(LED_PORT,Red_LED_PIN,DIO_LOW);
	}
	else{}
}
void NORMAL(void)
{
	SERVO_VidSet(SERVO_CLOSE);
	Counter_Handler();
	DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_LOW);
	FAN_VidSetDirection(FAN_ClockWise);
}

void FIRE_Handler(void)
{
	SERVO_VidSet(SERVO_OPEN);
	DIO_VidSetPinValue(LED_PORT,Green_LED_PIN,DIO_LOW);
	DIO_VidSetPinValue(LED_PORT,Red_LED_PIN,DIO_HIGH);
	DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_HIGH);
	FAN_VidSetSpeed(FAN_Speed5);
	FAN_VidSetDirection(FAN_ClockOtherWise);
}
void SMOKE_Handler(void)
{
	DIO_VidSetPinValue(LED_PORT,Green_LED_PIN,DIO_LOW);
	DIO_VidSetPinValue(LED_PORT,Red_LED_PIN,DIO_HIGH);
	FAN_VidSetDirection(FAN_ClockOtherWise);
}
void LCD_PRINT(void)
{
	//LCD_VoidSendCmd(LCD_CLEAR);
	if(FIRE_FLAG==1)
	{
		LCD_VoidSendCmd(LCD_CLEAR);
		LCD_VoidGoToXY(0,0);
		LCD_VoidSendStr("Honak Fire");
	}
	else if(SMOKE_FLAG==1)
	{
		LCD_VoidSendCmd(LCD_CLEAR);
		LCD_VoidGoToXY(1,0);
		LCD_VoidSendStr("Honak Smoke");
	}
	else
	{
		LCD_VoidGoToXY(0,0);
		LCD_VoidSendStr("Counter = ");
		LCD_VoidSendNum(Car_Counter);
		LCD_VoidGoToXY(1,0);
		LCD_VoidSendStr("Temp = ");
		LCD_VoidSendNum(Temp_Read);
	}
}
//Enter Side
void main(void)
{
	//BLUETOOTH
	DIO_VidSetPinDirection(BLUETOOTH_PORT,BLUETOOTH_RX,DIO_INPUT);
	DIO_VidSetPinDirection(BLUETOOTH_PORT,BLUETOOTH_TX,DIO_OUTPUT);
	BLUETOOTH_VidInit();
	//SMOKE
	DIO_VidSetPinDirection(SMOKE_PORT,SMOKE_PIN,DIO_INPUT);
	//Temperature
	DIO_VidSetPinDirection(Temp_PORT,Temp_PIN,DIO_INPUT);
	Temp_VidInit();
	//FLAME
	DIO_VidSetPinDirection(FLAME_PORT,FLAME_PIN,DIO_INPUT);
	//IR
	DIO_VidSetPinDirection(IR_PORT,IR_PIN,DIO_INPUT);
	//FAN
	DIO_VidSetPinDirection(FAN_CONTROL_PORT,FAN_CONTROL_PIN1,DIO_OUTPUT);
	DIO_VidSetPinDirection(FAN_CONTROL_PORT,FAN_CONTROL_PIN2,DIO_OUTPUT);
	DIO_VidSetPinDirection(FAN_PWM_PORT,FAN_PWM_PIN,DIO_OUTPUT);
	FAN_VidInit();
	FAN_VidSetSpeed(FAN_Speed1);
	FAN_VidSetDirection(FAN_ClockWise);
	//SERVO
	DIO_VidSetPinDirection(SERVO_PORT,SERVO_PIN,DIO_OUTPUT);
	SERVO_VidInit();
	SERVO_VidSet(SERVO_CLOSE);
	//BUZZER
	DIO_VidSetPinDirection(BUZZER_PORT,BUZZER_PIN,DIO_OUTPUT);
	//LEDs
	DIO_VidSetPinDirection(LED_PORT,Green_LED_PIN,DIO_OUTPUT);
	DIO_VidSetPinDirection(LED_PORT,Red_LED_PIN,DIO_OUTPUT);
	//LCD
	LCD_VoidInit();
	//Timer0
	Timer0_voidInit();
	Timer0_Interrupt_Handle(Timer0_ISR);
	//Exit
	EXT0_init();
	EXT0_Interrupt_Handle(Exit0_ISR);
	//Global Interrupt Enable
	Enable_VidGlobal();
	NORMAL();


	while(1)
	{
		if(FIRE_FLAG==1)
		{
			FIRE_Handler();
		}
		else if(SMOKE_FLAG==1)
		{
			SMOKE_Handler();
		}
		else
		{
			NORMAL();
		}
		LCD_PRINT();
		if (DIO_U8GetPinValue(FLAME_PORT,FLAME_PIN))
			FIRE_FLAG=1;
		else
			FIRE_FLAG=0;
		if (DIO_U8GetPinValue(SMOKE_PORT,SMOKE_PIN))
			SMOKE_FLAG=1;
		else
			SMOKE_FLAG=0;

		if(BLUETOOTH_U8ReciveCarCount()!=0)
			Car_Counter--;

		/*if(DIO_U8GetPinValue(IR_PORT,IR_PIN)==1)
		{
			Car_Counter++;
			while(DIO_U8GetPinValue(IR_PORT,IR_PIN)==1);
			_delay_ms(5);
		}*/

	}
}
