/*
 * Timer0_confid.h
 *
 *  Created on: Dec 15, 2020
 *      Author: 20122
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define SCALE_1				1
#define SCALE_8				8
#define SCALE_64			64
#define SCALE_256			256
#define SCALE_1024			1024
#define EXT_CLK_FALLING		12 	//External clock source on T0 pin. Clock on falling edge
#define EXT_CLK_RISING		13  //External clock source on T0 pin. Clock on rising edge

#define Normal				0
#define PWM_PHC				1
#define CTC					2
#define Fast_PWM			3

#define PWM_NORMALPORT 		1		//Stop OC0 From PWM , Normal port operation, OC0 disconnected
#define PWM_Reserved		2		//Don't Use
#define PWM_NonInvert		3		//(FAST_PWM)Clear OC0 on compare match, set OC0 at TOP
									//(PWM_PHC)Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
#define PWM_Invert			4		//(FAST_PWM)Set OC0 on compare match, clear OC0 at TOP
									//(PWM_PHC)Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.


/*You Will Configure This Bits To Config Timer 0*/
#define Timer_Mode  		Normal			//Select From (Normal,PWM_PHC,CTC,Fast_PWM)
#define PRESCALLER			SCALE_64      //Select from (SCALE_1,SCALE_8,SCALE_64,SCALE_256,SCALE_1024,EXT_CLK_RISING,EXT_CLK_FALLING)
#define PRELOAD				0				//PreLoad value to 8-bit Register from 0-->255
#define count_check 		30				//Number of over flow of the timer Register
#define OCR0Data			200				//The data put in OCR0 Register to compare
#define PWM_Mode 			PWM_NonInvert	//Select from (PWM_NORMALPORT,PWM_Reserved,PWM_NonInvert,PWM_Invert)
#define PWM_Init_Duty		50				//put here any value from 0-->100

#endif /* TIMER0_CONFIG_H_ */
