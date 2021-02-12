/*************************************************************************/
/******Auther   : George Ayman Sedky                                    */
/******Date     : 16/12/2020                                           */
/******Version  : V1.0                                                */
/*Description   : Timer 1 Configuration file    				      */
/********************************************************************/

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

//Scroll Down To Get The Configure
/*Don't Change Any of That */
/////////////////////////////////////////////////////////////////////////////////////////////////////
/*Time1 PreScaller Scale*/
#define SCALE_1				1
#define SCALE_8				8
#define SCALE_64			64
#define SCALE_256			256
#define SCALE_1024			1024
#define EXT_CLK_FALLING		12 	//External clock source on T0 pin. Clock on falling edge
#define EXT_CLK_RISING		13  //External clock source on T0 pin. Clock on rising edge

/*Timer1 Modes*/

#define NORMAL						0
#define PWM_Phase_Correct_8bit		1
#define PWM_Phase_Correct_9bit		2
#define PWM_Phase_Correct_10bit		3
#define CTC_TOP_OCR1A				4
#define Fast_PWM_8bit				5
#define Fast_PWM_9bit				6
#define Fast_PWM_10bit				7
#define PWM_PHFC_TOP_ICR1			8
#define PWM_PHFC_TOP_OCR1A			9
#define PWM_PHC_TOP_ICR1			10
#define PWM_PHC_TOP_OCR1A			11
#define CTC_TOP_ICR1				12
#define Fast_PWM_TOP_ICR1			14
#define Fast_PWM_TOP_OCR1A			15


#define NORMALPORT 		1		//Stop OC0 From PWM , Normal port operation, OC0 disconnected
#define Mode15			2		/*WGM13:0 = 15,9,14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
 	 	 	 	 	 	 	 	 For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected */
#define NonInvert		3		//(FAST_PWM)Clear OC0 on compare match, set OC0 at TOP
									//(PWM_PHC)Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
#define Invert			4		//(FAST_PWM)Set OC0 on compare match, clear OC0 at TOP
									//(PWM_PHC)Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.

#define PWM							1
#define CTC							2

#define ENABLE						1
#define DISABLE						0
//////////////////////////////////////////////////////////////////////////////////////////////////

/*You Will Configure This Bits To Config Timer 1*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
#define Timer_Mode  		PWM				//Select From (NORMAL,PWM,CTC)
#define PRESCALLER			SCALE_256    	//Select from (SCALE_1,SCALE_8,SCALE_64,SCALE_256,SCALE_1024,EXT_CLK_RISING,EXT_CLK_FALLING)
#define OC1A_Mode 			NonInvert		//Select from (NORMALPORT,Mode15,NonInvert,Invert)
#define OC1B_Mode 			NonInvert		//Select from (NORMALPORT,Mode15,NonInvert,Invert)
#define Cupture_Mode		DISABLE			//select Cupture_Mode (ENABLE , DISABLE)

//NORMAL OVERFLOW MODE
#if Timer_Mode == NORMAL
#define PRELOAD				0				//PreLoad value to 16-bit Register from 0-->65536
#define count_check 		0				//Number of over flow of the timer Register

//CTC MODE
#elif Timer_Mode == CTC
#define CTC_Mode			CTC_TOP_OCR1A	/*Select From(CTC_TOP_OCR1A,CTC_TOP_ICR1)  */
#define OCR1A_CTC_Data			200				//The data put in OCR1A Register to compare
#define OCR1B_CTC_Data			200				//The data put in OCR1B Register to compare
#define ICR1_CTC_Data			600				//The data put in ICR1 Register to compare
#define count_checkCHA		2000
#define count_checkCHB		2000

//PWM MODE
#elif Timer_Mode == PWM
#define PWM_Mode			Fast_PWM_TOP_ICR1
												/*Select From
												(PWM_Phase_Correct_8bit,
												PWM_Phase_Correct_9bit,
												PWM_Phase_Correct_10bit,
												Fast_PWM_8bit,
												Fast_PWM_9bit,
												Fast_PWM_10bit
												PWM_PHFC_TOP_ICR1
												PWM_PHFC_TOP_OCR1A
												PWM_PHC_TOP_ICR1
												PWM_PHC_TOP_OCR1A
												Fast_PWM_TOP_ICR1
												Fast_PWM_TOP_OCR1A
												)*/
#define PWM_Init_DutyCHA	0				//put here any value from 0-->100
#define PWM_Init_DutyCHB	0				//put here any value from 0-->100
#define ICR1_PWM_DATA		625
#define OCR1A_PWM_DATA		0
#endif



#endif /* TIMER1_CONFIG_H_ */
