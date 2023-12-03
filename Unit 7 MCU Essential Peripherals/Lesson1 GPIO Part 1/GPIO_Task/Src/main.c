/*
 ******************************************************************************
 * file           : main.c
 * Board		  :STM32f103c6_Cortex-M3
 * author         : Aly_Mustafa_Enaya
 * brief          : Main program body
 * Date			  : 1/9/2023
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//Clock registers address
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE+0x18))

// GPIOA register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE + 0x0C))
#define GPIOA_CRL *((volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_IDR *((volatile uint32_t *)(GPIOA_BASE + 0x08))
//GPIOB register address
#define GPIOB_BASE 0x40010C00
#define GPIOB_CRH *((volatile uint32_t *)(GPIOB_BASE + 0x04))
#define GPIOB_ODR *((volatile uint32_t *)(GPIOB_BASE + 0x0C))
#define GPIOB_CRL *((volatile uint32_t *)(GPIOB_BASE + 0x00))

void clock_init ()
{
	//Init Clock
	RCC_APB2ENR |= (1<<2); //IO portA clock enable
	RCC_APB2ENR |= (1<<3); //IO portB clock enable
}

void GPIO_init ()
{
	GPIOA_CRL = 0x0;
	GPIOA_CRH = 0x0;
	GPIOB_CRL = 0x0;
	GPIOB_CRH = 0x0;
	//PA1 floating pull_up single pressing
	GPIOA_CRL &=~ (0b11<<4);  //00: Input mode (reset state)
	GPIOA_CRL |= (0b01<<6);    //01: Floating input (reset state)

	//PA15 floating pull_down multi pressing
	GPIOA_CRH &=~ (0b11<<28);  //00: Input mode (reset state)
	GPIOA_CRH |= (0b01<<30);    //01: Floating input (reset state)

	//PB1 Push_Pull zero
	GPIOB_CRL |= (0b01<<4); //01: Output mode, max speed 10 MHz.
	GPIOB_CRL &=~ (0b11<<6); //00: General purpose output push-pull

	//PB13 Push_Pull zero
	GPIOB_CRH |= (0b01<<20); //01: Output mode, max speed 10 MHz.
	GPIOB_CRH &=~ (0b11<<22); //00: General purpose output push-pull
}
void wait_ms(int x){

	int i,j;
	for(i=0 ; i<j ; i++){
		for(j=0 ; j<255 ; j++);
	}
}
int main(void)
{
	clock_init ();
	GPIO_init ();
	GPIOB_ODR |= 1<<1;
	GPIOB_ODR &= ~(1<<1) ;

	GPIOB_ODR |= 1<<13;
	GPIOB_ODR &= ~(1<<13) ;
	/* Loop forever */
	while(1)
	{
		if(((GPIOA_IDR & (1<<1)) /*>> 1*/) == 0)
		{
			GPIOB_ODR ^= 1<<1;
			while(((GPIOA_IDR & (1<<1))/* >> 1*/) == 0); //single press
		}
		if(((GPIOA_IDR & (1<<15)) >> 15) == 1)
		{
			GPIOB_ODR ^= 1<<13;	//multi press
		}
		wait_ms(1);
	}
}
