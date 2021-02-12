/*
 * FAN_Init.h
 *
 *  Created on: Jan 1, 2021
 *      Author: 20122
 */

#ifndef FAN_FAN_INIT_H_
#define FAN_FAN_INIT_H_

#define FAN_Speed0	0
#define FAN_Speed1	1
#define FAN_Speed2	2
#define FAN_Speed3	3
#define FAN_Speed4	4
#define FAN_Speed5	5

#define FAN_ClockWise		0
#define FAN_ClockOtherWise	1


void FAN_VidInit(void);
void FAN_VidSetSpeed(u8 Copy_U8Speed);
void FAN_VidSetDirection(u8 Copy_U8Dir);


#endif /* FAN_FAN_INIT_H_ */
