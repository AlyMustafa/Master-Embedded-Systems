/*
 * IncFile1.h
 *
 * Created: 10/09/2023 09:47:56 PM
 *  Author: Ali Enaya
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


#ifndef LCD_H_
#define LCD_H_

#define lcd_port					PORTA
#define Dir_lcd_port				DDRA
#define lcd_control_port			PORTB
#define Dir_lcd_control_port		DDRB
#define DATA_shift  0
#define RS			1
#define RW			2
#define EN			3

//Modes

#define	EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

//COMMANDS_VALUES
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80) //default DDRAM address (10000000) to get first line and 1 position ,to set any position ,it will be added to the default 
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

//LCD_Functions

void lcd_check_isbusy(void);
void lcd_init(void);
void lcd_send_command(unsigned char command);
void lcd_send_character(unsigned char character);
void lcd_send_string(unsigned char* string);
void lcd_kick(void);
void lcd_set_cursor(unsigned char line , unsigned char position );
void lcd_Clear_Screen();

#endif /* LCD_H_ */