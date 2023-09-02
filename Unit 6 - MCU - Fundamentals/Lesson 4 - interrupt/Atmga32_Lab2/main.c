/*
 * GccApplication1.c
 *
 * Created: 26/08/2023 01:38:11 Õ
 * Author : ALy Mustafa
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//GPIO config
#define GPIO_PORTD   *(volatile unsigned char *)(0x32)
#define GPIO_DDRD	 *(volatile unsigned char *)(0x31)
#define GPIO_PIND    *(volatile unsigned char *)(0x30)

//INTERRUPT config
#define GICR	     *(volatile unsigned char *)(0x20 + 0x3B)
#define SREG		 *(volatile unsigned char *)(0x20 + 0x3F)
#define MCUCR		 *(volatile unsigned char *)(0x20 + 0x35)
#define MCUCSR		 *(volatile unsigned char *)(0x20 + 0x34)

//INTERRUPT init
void interrupt_init(){
	
	//enable general Interrupt contro; register
	GICR |= (0b111 << 5);
	
	//enable Global Interrupt contro; register
	SREG |= ((0b1 << 7));
	
	//any change of INT0
	MCUCR |= (0b01 << 0);
	//The Rising edge of INT1
	MCUCR |= (0b11 << 2);
	//The Falling edge on INT2
	MCUCSR &=~(1 << 6);
	
} 


int main(void)
{
	interrupt_init();
    //PORTD_PIN.5.6.7 OUTPUT 
	GPIO_DDRD |= (0b1 << 5);
	GPIO_DDRD |= (0b1 << 6);
	GPIO_DDRD |= (0b1 << 7);
	
    while (1) 
    {
		//Turn off all Leds
		GPIO_PORTD &=~ (1<<5);
		GPIO_PORTD &=~ (1<<6);
		GPIO_PORTD &=~ (1<<7);
    }
}

ISR(INT0_vect){
	GPIO_PORTD |= (1<<5);
	_delay_ms(100);
}

ISR(INT1_vect){
	GPIO_PORTD |= (1<<6);
	_delay_ms(100);
	
}

ISR(INT2_vect){
	GPIO_PORTD |= (1<<7);
	_delay_ms(100);
	
}
