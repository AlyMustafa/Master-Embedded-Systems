/*
 * main.c
 *
 * Created: 14/09/2023 02:12:44 ص
 *  Author: Metro
 */ 
/*
 * LCD_Driver.c
 *
 * Created: 07/09/2023 10:40:19 م
 * Author : Ali Enaya
 */
#include "LCD.h"
#include "Keypad.h"

int main(void)
{
lcd_init();
keypad_init();
int i =0;
while (1)
{
	char pressed_key = keypad_get_key();

	switch(pressed_key)
	{
		case ('?'):
		{
			lcd_set_cursor(2,0);
			lcd_send_string("Invalid value");
			_delay_ms(600);
			lcd_Clear_Screen();
			break;
		}
		
		case ('A'):
		break;
		
		default: {
					lcd_send_character(pressed_key);
					if (i==16)
					{
						lcd_set_cursor(2,0);
					}
					i++;

		}
	}
	
}

}