/*
 * LCD_Config.h
 *
 *  Created on: Nov 30, 2020
 *      Author: 20122
 */

#ifndef LCD_LIB_LCD_CONFIG_H_
#define LCD_LIB_LCD_CONFIG_H_

#define D0				DIO_PIN0
#define	D1				DIO_PIN1
#define D2				DIO_PIN2
#define	D3				DIO_PIN3
#define D4				DIO_PIN4
#define	D5				DIO_PIN5
#define D6				DIO_PIN6
#define	D7				DIO_PIN7

#define EIGHT_BIT		0
#define FOUR_BIT		1
#define LCD_2_16		0
#define LCD_4_20		1
////////////////////////////////////////////////////////////
/*Change From Here*/
#define MODE  			FOUR_BIT
#define LCD_Choose		LCD_2_16
#define DATA_PORT		DIO_PORTA
#define CONTROL_PORT 	DIO_PORTC

#define	RS				DIO_PIN7
#define RW				DIO_PIN6
#define En				DIO_PIN5
/////////////////////////////////////////////////////////////

#define LCD_CLEAR    			    0X01
#define LCD_HOME       				0x02
#define LCD_ENTERYMODE 				0x06
#define LCD_DISPLAYOFF 				0x08
#define LCD_DISPLAYON			 	0x0c
#define LCD_SETCURSER0              0x80
#define LCD_SETCURSER1              0xc0
#define LCD_FUNCTION_RESET  		0x30
#define LCD_FUNCTIONSET_8BIT        0x38
#define LCD_FUNCTIONSET_4BIT        0x28
#define LCD_SHIFT_LEFT				0x18
#define LCD_SHIFT_RIGHT				0x1c
#define LCD_CGRAM_ADD0				0x40
#define LCD_DDRAM_ADD0				0x80
#define LCD_SETCURSER2				0x94
#define LCD_SETCURSER3				0xD4






#endif /* LCD_LIB_LCD_CONFIG_H_ */
