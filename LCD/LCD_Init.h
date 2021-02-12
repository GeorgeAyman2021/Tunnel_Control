//*************************************************************************/
/******Auther   : George Ayman Sedky                                     */
/******Date     : 30/11/2020                                            */
/******Version  : V1.0                                                 */
/*Description   : 16x2  LCD Initialization And Control Header         */
/*********************************************************************/

#ifndef LCD_LIB_LCD_INIT_H_
#define LCD_LIB_LCD_INIT_H_



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


void LCD_VoidInit(void);

void LCD_VoidSendCmd(u8 Copy_U8Cmd);

void LCD_VoidSendChar(u8 Copy_U8Char);

void LCD_VoidSendStr (u8* Ptr_Str);

void LCD_VoidSendNum(u16 Copy_U16Num);

void LCD_VoidGoToXY(u8 Copy_U8Row,u8 Copy_U8Col);

void LCD_VoidSendSpcial(u8 *Ptr_SpcialArray);

void LCD_VoidSendSpcial_and_Print (u8 Copy_U8Row,u8 Copy_U8Col,u8 *Ptr_SpcialArray);

#endif /* LCD_LIB_LCD_INIT_H_ */
