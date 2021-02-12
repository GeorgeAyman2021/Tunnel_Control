/*
 * ADC_Interface.h
 *
 *  Created on: Dec 7, 2020
 *      Author: neutr
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define CHANNEL_0	0
#define CHANNEL_1	1
#define CHANNEL_2	2
#define CHANNEL_3	3
#define CHANNEL_4	4
#define CHANNEL_5	5
#define CHANNEL_6	6
#define CHANNEL_7	7

void ADC_init();

void ADC_EN(u8 ON_OFF);

u16 ADC_Read_Channle(u8 Channle);

#endif /* ADC_INTERFACE_H_ */
