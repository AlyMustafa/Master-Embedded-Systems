
/*
 * LCD.c
 *
 * Created: 10/09/2023 10:44:04 PM
 *  Author: Aly Enaya
 */ 
#include "LCD.h"


void lcd_init(){
	_delay_ms(20);
	Dir_lcd_port = 0xFF;
	Dir_lcd_control_port |= ( (1<<RS) | (1<<RW) | (1<<EN) );
	lcd_control_port &= ~( (1<<RS) | (1<<RW) | (1<<EN) );
	_delay_ms(15); //finish initialization
	lcd_Clear_Screen();
	

	#ifdef EIGHT_BIT_MODE
	lcd_send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	#endif
	
	lcd_send_command(LCD_ENTRY_MODE);
	lcd_send_command(LCD_BEGIN_AT_FIRST_ROW);
	lcd_send_command(LCD_DISP_ON_CURSOR_BLINK);
	
	
	

}
void lcd_kick(void){
	lcd_control_port |= (1<<EN);
	_delay_ms(50);
	lcd_control_port &=~ (1<<EN);
}

void lcd_check_isbusy(){
	Dir_lcd_port &=~ (0xff<<DATA_shift);
	lcd_control_port &=~ (1<<RS);
	lcd_control_port |= (1<<RW); //to read
	lcd_kick();
	lcd_control_port &=~ (1<<RW);
	Dir_lcd_port |= (0xff<<DATA_shift);
}




void lcd_send_command(unsigned char command){
	#ifdef EIGHT_BIT_MODE
	lcd_check_isbusy();
	lcd_port = command;
	lcd_control_port &= ~( (1<<RS) | (1<<RW) | (1<<EN) );
	lcd_kick();
	#endif

	//#ifdef FOUR_BIT_MODE
	//#endif
	
	
}

void lcd_send_character(unsigned char character){
	
	#ifdef EIGHT_BIT_MODE
	lcd_check_isbusy();
	lcd_control_port |= (1<<RS);
	lcd_control_port &=~ (1<<RW);
	lcd_port = character;
	lcd_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	#endif
}

void lcd_send_string(unsigned char* string){
	
	#ifdef EIGHT_BIT_MODE
	lcd_check_isbusy();
	lcd_control_port |= (1<<RS);
	lcd_control_port &=~( (1<<RW) | (1<<EN) );
	
	int i=0; // to tell how much the display fills
	
	while(*string > 0){
		lcd_send_character(*string++);
		i++;
		if(i == 16)
		lcd_set_cursor(2,0);
		if (i == 32)
		{
			lcd_set_cursor(1,0);
			i=0;
		}
		
	}
	#endif
	
	#ifdef FOUR_BIT_MODE
	#endif
	
}


void lcd_Clear_Screen(){
	lcd_send_command(LCD_CLEAR_SCREEN);
}

void lcd_set_cursor(unsigned char line , unsigned char position ){
	if (line == 1)
	{
		if(position >= 0 && position < 16)
		lcd_send_command(LCD_BEGIN_AT_FIRST_ROW + position);
	}
	if (line == 2)
	{
		if(position >= 0 && position < 16)
		lcd_send_command(LCD_BEGIN_AT_SECOND_ROW + position);
	}
	
	
}