/*************************************************************************/
/******Auther   : George Ayman Sedky                                    */
/******Date     : 16/12/2020                                           */
/******Version  : V1.0                                                */
/*Description   : Time 1 Program    							      */
/********************************************************************/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO/DIO_INTERFACE.h"
#include "Timer1_Config.h"
#include "Timer1_Private.h"
#include "util/delay.h"

u16 count1=0;
u16 countCTCA=0;
u16 countCTCB=0;

u8 flag;
u16 snap1;
u32 snap2;
u32 snap3;
u8 ov;

void __vector_9()	 //Timer/Counter1 Overflow
{
#if Timer_Mode == NORMAL

	ov++;
	//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	/*count1++;
	if(count1==count_check)
	{
		TCNT1=PRELOAD;
		count1=0;
		DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
	}*/
#endif
}
void __vector_8()	//Timer/Counter1 Compare Match B
{
#if Timer_Mode == CTC
	countCTCA++;
	if(countCTCA==count_checkCHA)
	{
		DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
		countCTCA=0;
	}
#endif
}
void __vector_7()	//Timer/Counter1 Compare Match A
{
#if Timer_Mode == CTC
	countCTCB++;
	if(countCTCB==count_checkCHB)
	{
		DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
		countCTCB=0;
	}

#endif
}
void __vector_6() 	//Timer/Counter1 Capture Event
{

	if(flag == 0)
	{
		snap1=ICR1;
		ov=0;
		CLR_BIT(TCCR1B,ICES1);
		flag=1;
	}
	else if( flag == 1 )
	{
		snap2=ICR1 +(ov*65536);
		flag=2;
		SET_BIT(TCCR1B,ICES1);
		//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);

	}
	else if (flag ==2)
	{
		snap3=ICR1 +(ov*65536);
		flag=3;

	}
	//_delay_ms(1000);
	//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
	//SET_BIT(TIFR, ICF1);
}

void Timer1_voidSetDutyCHA(f32 Copy_F32Duty)
{
#if PWM_Mode == PWM_Phase_Correct_8bit
	u16 Duty=(u16)((Copy_F32Duty/100)*256);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=256-Duty;
#endif
#elif PWM_Mode == PWM_Phase_Correct_9bit
	u16 Duty=(u16)((Copy_F32Duty/100)*512);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=512-Duty;
#endif
#elif PWM_Mode == PWM_Phase_Correct_10bit
	u16 Duty=(u16)((Copy_F32Duty/100)*1024);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=1024-Duty;
#endif
#elif PWM_Mode == Fast_PWM_8bit
	u16 Duty=(u16)((Copy_F32Duty/100)*256);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=256-Duty;
#endif
#elif PWM_Mode == Fast_PWM_9bit
	u16 Duty=(u16)((Copy_F32Duty/100)*512);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=512-Duty;
#endif
#elif PWM_Mode == Fast_PWM_10bit
	u16 Duty=(u16)((Copy_F32Duty/100)*1024);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=1024-Duty;
#endif
#elif PWM_Mode == PWM_PHFC_TOP_ICR1
	u16 Duty=(u16)((Copy_F32Duty/100)*ICR1_PWM_DATA);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=ICR1_PWM_DATA-Duty;
#endif
#elif PWM_Mode == PWM_PHFC_TOP_OCR1A
	u16 Duty=(u16)((Copy_F32Duty/100)*OCR1A_PWM_DATA);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=OCR1A_PWM_DATA-Duty;
#endif
#elif PWM_Mode == PWM_PHC_TOP_ICR1
	u16 Duty=(u16)((Copy_F32Duty/100)*ICR1_PWM_DATA);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=ICR1_PWM_DATA-Duty;
#endif
#elif PWM_Mode == PWM_PHC_TOP_OCR1A
	u16 Duty=(u16)((Copy_F32Duty/100)*OCR1A_PWM_DATA);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=OCR1A_PWM_DATA-Duty;
#endif
#elif PWM_Mode == Fast_PWM_TOP_ICR1
	u16 Duty=(u16)((Copy_F32Duty/100)*ICR1_PWM_DATA);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=ICR1_PWM_DATA-Duty;
#endif
#elif PWM_Mode == Fast_PWM_TOP_OCR1A
	u16 Duty=(u16)((Copy_F32Duty/100)*OCR1A_PWM_DATA);
#if  OC1A_Mode  == NonInvert
	OCR1A=Duty;
#elif OC1A_Mode == Invert
	OCR1A=OCR1A_PWM_DATA-Duty;
#endif

#endif

}
void Timer1_voidSetDutyCHB(f32 Copy_F32Duty)
{
#if PWM_Mode == PWM_Phase_Correct_8bit
	u16 Duty=(u16)((Copy_F32Duty/100)*256);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=256-Duty;
#endif
#elif PWM_Mode == PWM_Phase_Correct_9bit
	u16 Duty=(u16)((Copy_F32Duty/100)*512);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=512-Duty;
#endif
#elif PWM_Mode == PWM_Phase_Correct_10bit
	u16 Duty=(u16)((Copy_F32Duty/100)*1024);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=1024-Duty;
#endif
#elif PWM_Mode == Fast_PWM_8bit
	u16 Duty=(u16)((Copy_F32Duty/100)*256);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=256-Duty;
#endif
#elif PWM_Mode == Fast_PWM_9bit
	u16 Duty=(u16)((Copy_F32Duty/100)*512);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=512-Duty;
#endif
#elif PWM_Mode == Fast_PWM_10bit
	u16 Duty=(u16)((Copy_F32Duty/100)*1024);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=1024-Duty;
#endif
#elif PWM_Mode == PWM_PHFC_TOP_ICR1
	u16 Duty=(u16)((Copy_F32Duty/100)*ICR1_PWM_DATA);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=ICR1_PWM_DATA-Duty;
#endif
#elif PWM_Mode == PWM_PHFC_TOP_OCR1A
	u16 Duty=(u16)((Copy_F32Duty/100)*OCR1A_PWM_DATA);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=OCR1A_PWM_DATA-Duty;
#endif
#elif PWM_Mode == PWM_PHC_TOP_ICR1
	u16 Duty=(u16)((Copy_F32Duty/100)*ICR1_PWM_DATA);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=ICR1_PWM_DATA-Duty;
#endif
#elif PWM_Mode == PWM_PHC_TOP_OCR1A
	u16 Duty=(u16)((Copy_F32Duty/100)*OCR1A_PWM_DATA);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=OCR1A_PWM_DATA-Duty;
#endif
#elif PWM_Mode == Fast_PWM_TOP_ICR1
	u16 Duty=(u16)((Copy_F32Duty/100)*ICR1_PWM_DATA);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=ICR1_PWM_DATA-Duty;
#endif
#elif PWM_Mode == Fast_PWM_TOP_OCR1A
	u16 Duty=(u16)((Copy_F32Duty/100)*OCR1A_PWM_DATA);
#if  OC1B_Mode  == NonInvert
	OCR1B=Duty;
#elif OC1B_Mode == Invert
	OCR1B=OCR1A_PWM_DATA-Duty;
#endif

#endif
}
void Timer1_voidInit(void)
{
#if Cupture_Mode == ENABLE
	SET_BIT(TCCR1B,ICES1);
	SET_BIT(TIMSK,TICIE1);
#endif

#if Timer_Mode == NORMAL
	TCNT1=PRELOAD;
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	SET_BIT(TIMSK,TOIE1);
#elif Timer_Mode == CTC
#if CTC_Mode == CTC_TOP_ICR1
	ICR1=ICR1_CTC_Data;
	OCR1A=OCR1A_CTC_Data;
	OCR1B=OCR1B_CTC_Data;
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

#elif CTC_Mode == CTC_T OP_OCR1A
	ICR1=ICR1_CTC_Data;
	OCR1A=OCR1A_CTC_Data;
	OCR1B=OCR1B_CTC_Data;
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);

#endif
#elif Timer_Mode == PWM
	Timer1_voidSetDutyCHA(PWM_Init_DutyCHA);
	Timer1_voidSetDutyCHB(PWM_Init_DutyCHB);
#if PWM_Mode == PWM_Phase_Correct_8bit
	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif PWM_Mode == PWM_Phase_Correct_9bit
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif PWM_Mode == PWM_Phase_Correct_10bit
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif PWM_Mode == Fast_PWM_8bit
	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif PWM_Mode == Fast_PWM_9bit
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif PWM_Mode == Fast_PWM_10bit
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif PWM_Mode == PWM_PHFC_TOP_ICR1
	ICR1=ICR1_PWM_DATA;
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif PWM_Mode == PWM_PHFC_TOP_OCR1A
	OCR1A=OCR1A_PWM_DATA;
	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif PWM_Mode == PWM_PHC_TOP_ICR1
	ICR1=ICR1_PWM_DATA
			CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif PWM_Mode == PWM_PHC_TOP_OCR1A
	OCR1A=OCR1A_PWM_DATA;
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif PWM_Mode == Fast_PWM_TOP_ICR1
	ICR1=ICR1_PWM_DATA;
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif PWM_Mode == Fast_PWM_TOP_OCR1A
	OCR1A=OCR1A_PWM_DATA;
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

#endif
#endif

#if OC1A_Mode==NORMALPORT
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif OC1A_Mode==Mode15
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif OC1A_Mode==NonInvert
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#elif OC1A_Mode==Invert
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif

#if OC1B_Mode==NORMALPORT
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
#elif OC1B_Mode==Mode15
	SET_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
#elif OC1B_Mode==NonInvert
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#elif OC1B_Mode==Invert
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#endif



#if PRESCALLER == SCALE_1
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
#elif PRESCALLER ==SCALE_8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
#elif PRESCALLER ==SCALE_64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
#elif PRESCALLER ==SCALE_256
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
#elif PRESCALLER ==SCALE_1024
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
#elif PRESCALLER ==EXT_CLK_FALLING
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
#elif PRESCALLER ==EXT_CLK_RISING
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
#endif

}
