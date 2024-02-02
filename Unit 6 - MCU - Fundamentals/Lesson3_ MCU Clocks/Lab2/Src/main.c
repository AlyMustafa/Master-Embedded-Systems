//Learn-in-depth
//Aly mustafa
//Mastering_Embedded System online diploma
typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address

//1: internal 8 MHz RC oscillator ON



//00: HSI selected as system clock


/*

 Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock
(PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16

 */



/*
 Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
 */

/*
 Bits 7:4 HPRE: AHB prescaler
Set and cleared by software to control the division factor of the AHB clock.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512
 */
//Init clocks
#define RCC_BASE 0x40021000
#define RCC_CR *((volatile uint32_t *)(RCC_BASE+0x00))
#define RCC_CFGR *((volatile uint32_t *)(RCC_BASE+0x04))
#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE+0x18))
//Init GPIOA
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
int main(void)
{
	//Init clocks
	RCC_CR |= (1<<0);
	RCC_CFGR |= (0b00<<0);
	RCC_CFGR |= (0b0000<<4);
	RCC_CFGR |= (0b0000<<4);
	RCC_CFGR |= (0b100<<8);
	RCC_CFGR |= (0b101<<11);

	RCC_APB2ENR |= 1<<2;
	//Init GPIOA

	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}



