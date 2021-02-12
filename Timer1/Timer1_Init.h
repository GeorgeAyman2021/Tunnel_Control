/*************************************************************************/
/******Auther   : George Ayman Sedky                                    */
/******Date     : 16/12/2020                                           */
/******Version  : V1.0                                                */
/*Description   : Timer 1 Initializtion 							      */
/********************************************************************/

#ifndef TIMER1_INIT_H_
#define TIMER1_INIT_H_



extern u8 flag;
extern u16 snap1;
extern u32 snap2;
extern u32 snap3;
extern u8 ov;



void Timer1_voidInit(void);
void Timer1_voidSetDutyCHA(f32 Copy_F32Duty);
void Timer1_voidSetDutyCHB(f32 Copy_F32Duty);
#endif /* TIMER1_INIT_H_ */
