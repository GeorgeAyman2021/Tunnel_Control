/*
 * UART_PROGRAM.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Abanoub Raouf
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"UART_CONFG.h"
#include"UART_PRIVETE.h"

static volatile void (*callBackPtr)(void) = NULL_PTR;  /*initiat function to point to null*/


void UART_Interrupt_Handle(void(*a_ptr)(void))
{
	callBackPtr = a_ptr; /*give address function processing to the pointer pointer*/
}

void __vector_13()
{
	if(callBackPtr != NULL_PTR)
			{

			/* Call the Call Back function in the application after the edge is detected */
				(*callBackPtr)();
			}
}


void UART_VidInit(void)
{

	//UBRRL=(fOSC/(16*BAUDRATE))-1;
		u8 UCSRC_HELP;
		SET_BIT(UCSRC_HELP,URSEL);
		//Select normal mode speed
		CLR_BIT(UCSRA,MPCM);
		CLR_BIT(UCSRA,U2X);

		//Interrupt Enable
		//SET_BIT(UCSRB,RXCIE); //RX Complete Interrupt Enable
		//SET_BIT(UCSRB,TXCIE);	//TX Complete Interrupt Enable

		//Character Size 8-bit
		CLR_BIT(UCSRB,UCSZ2);
		SET_BIT(UCSRC_HELP,UCSZ0);
		SET_BIT(UCSRC_HELP,UCSZ1);

		//Enable Transimte & Recive
		SET_BIT(UCSRB,TXEN);
		SET_BIT(UCSRB,RXEN);

		//Select Asyncronas Mode
		CLR_BIT(UCSRC_HELP,UMSEL);

		//Parity Mode Disable
		CLR_BIT(UCSRC_HELP,UPM0);
		CLR_BIT(UCSRC_HELP,UPM1);

		//select 1 stop bit
		CLR_BIT(UCSRC_HELP,USBS);

		UCSRC=UCSRC_HELP;
		//Buad Rate 9600 on freq 8000000
		UBRRL=51;
		UBRRH=0;

}

/*
void UART_VidInit(void)
{
	u8 UCSRC_help=0;
//**********************************************************************************************************
	#if processor_Communication_Mode==0
		CLR_BIT(UCSRA,0);//disable Multi-processor Communication Mode
	#elif processor_Communication_Mode==1
		SET_BIT(UCSRA,0);
	#endif
//**********************************************************************************************************
	#if Transmission_Speed==0
		CLR_BIT(UCSRA,1);//disable Double of USART Transmission Speed
	#elif Transmission_Speed==0
		SET_BIT(UCSRA,1);
	#endif
//**********************************************************************************************************
#if	RX_Complete_Interrupt==0
		CLR_BIT(UCSRB,7);
#elif RX_Complete_Interrupt==1
		SET_BIT(UCSRB,7);
#endif
//**********************************************************************************************************
#if TX_Complete_Interrupt==0
		CLR_BIT(UCSRB,6);
#elif TX_Complete_Interrupt==1
		SET_BIT(UCSRB,6);
#endif
//**********************************************************************************************************
#if USART_Data_Register_Empty==0
		CLR_BIT(UCSRB,5);
#elif	USART_Data_Register_Empty==1
		SET_BIT(UCSRB,5);
#endif
//**********************************************************************************************************
#if Receiver==0
		CLR_BIT(UCSRB,4);
#elif	Receiver==1
		SET_BIT(UCSRB,4);//Receiver Enable
#endif
//**********************************************************************************************************
#if	Transmitter==0
		CLR_BIT(UCSRB,3);
#elif Transmitter==1
		SET_BIT(UCSRB,3);//Transmitter Enable
#endif
//**********************************************************************************************************
#if	USART_Mode_Select==0
		CLR_BIT(UCSRC_help,6);//select Asynchronous Operation
		CLR_BIT(UCSRC_help,0);//Clock Polarity
#elif	USART_Mode_Select==1
		SET_BIT(UCSRC_help,6);
		#if Clock_Polarity==0
			CLR_BIT(UCSRC_help,0);
		#elif Clock_Polarity==1
			SET_BIT(UCSRC_help,0);
		#endif
#endif
//**********************************************************************************************************
#if	Parity_Mode==0
		//bit 4,5 to disable Parity Mode
		CLR_BIT(UCSRC_help,5);
		CLR_BIT(UCSRC_help,4);
#elif	Parity_Mode==2
		SET_BIT(UCSRC_help,5);
		CLR_BIT(UCSRC_help,4);
#elif	Parity_Mode==3
		SET_BIT(UCSRC_help,5);
		SET_BIT(UCSRC_help,4);
#endif
//**********************************************************************************************************
#if	Stop_Bit==0
		CLR_BIT(UCSRC_help,3);//select 1 bit for stop bits
#elif	Stop_Bit==1
		SET_BIT(UCSRC_help,3);
#endif
//**********************************************************************************************************
#if	Character_Size==0
		CLR_BIT(UCSRB,2);
		CLR_BIT(UCSRC_help,2);
		CLR_BIT(UCSRC_help,1);
#elif	Character_Size==1
		CLR_BIT(UCSRB,2);
		CLR_BIT(UCSRC_help,2);
		SET_BIT(UCSRC_help,1);
#elif	Character_Size==2
		CLR_BIT(UCSRB,2);
		SET_BIT(UCSRC_help,2);
		CLR_BIT(UCSRC_help,1);
#elif	Character_Size==3
		//select 8 bit character size
		CLR_BIT(UCSRB,2);
		SET_BIT(UCSRC_help,2);
		SET_BIT(UCSRC_help,1);

#elif	Character_Size==7
		SET_BIT(UCSRB,2);
		SET_BIT(UCSRC_help,2);
		SET_BIT(UCSRC_help,1);
#endif
//**********************************************************************************************************
		SET_BIT(UCSRC_help,7);
		//using UCSRC_help because The URSEL must be one when writing the UCSRC (bit 7 must set 1 with all register at same time of set or clr other bits)
		UCSRC=UCSRC_help;
//**********************************************************************************************************
#if Baud_Rate==1
		UBRRL=207;
#elif Baud_Rate==2
		//UBRRL=0b01100111;//write 103 to select 9600 baudrate at 16MHz frequency
		UBRRL=103;
#elif Baud_Rate==3
		UBRRL=68;
#elif Baud_Rate==4
		UBRRL=51;
#elif Baud_Rate==5
		UBRRL=34;
#elif Baud_Rate==6
		UBRRL=25;
#elif Baud_Rate==7
		UBRRL=16;
#elif Baud_Rate==8
		UBRRL=12;
#elif Baud_Rate==9
		UBRRL=8;
#elif Baud_Rate==10
		UBRRL=3;
#elif Baud_Rate==11
		UBRRL=3;
#endif
//**********************************************************************************************************
//**********************************************************************************************************
}*/

void UART_VidTransmitChar(u8 value)
{
	while(GET_BIT(UCSRA,UDRE)==0);
		UDR=value;
}



/*
void UART_VidTransmitChar(u8 value)
{
	/*if(1==(GET_BIT(UCSRA,5)))//check if USART Data Register Empty
	{
		UDR=value;
	}
	UDR=value;
	while(GET_BIT(UCSRA,5)==0);


}*/

u8 UART_U16ReciveChar(void)
{
	u8 Data=0;
	if(GET_BIT(UCSRA,RXC)!=0)
		Data=UDR;
	return Data;
}



/*
u16 UART_U16ReciveChar(void)
{
	u16 recive_value=0;
	/*if(1==(GET_BIT(UCSRA,7)))//check if USART Receive Complete
	{
		recive_value=UDR;
	}
	if(0!=(GET_BIT(UCSRA,7)))
		recive_value=UDR;
	return recive_value;
}*/
void UART_VidTransmit_string(const u8 *string)
{
	//u8 i=0;
	while(*string!='\0')
	{
		UART_VidTransmitChar(*string);
		string++;
		/*UART_VidTransmit(string[i]);
		i++;*/
	}
}
void UART_U8GetString(u8 *str)
{
	u8 i=0;
	str[i]=UART_U16ReciveChar();
	while(str[i]!='#')
	{
		i++;
		str[i]=UART_U16ReciveChar();
	}
	str[i]='\0';

}



