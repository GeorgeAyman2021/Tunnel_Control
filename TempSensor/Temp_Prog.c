/*
 * Temp_Prog.c
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */
#include "Temp_Config.h"
#include "../LIB/STD_TYPES.h"
#include "../ADC/ADC_Interface.h"

void Temp_VidInit(void)
{
	ADC_init();
}
u8 Temp_U8Read(void)
{
	u16 Dig_Read,Anlg_Read,Temp;
	Dig_Read= ADC_Read_Channle(Temp_Channel);
	Anlg_Read=((Dig_Read * 5000UL)/1023);
	Temp=(Anlg_Read/10);
	return Temp;
}
