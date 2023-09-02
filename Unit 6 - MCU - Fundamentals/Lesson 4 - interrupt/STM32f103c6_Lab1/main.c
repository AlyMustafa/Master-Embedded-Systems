/**
 ******************************************************************************
 * file           : main.c
 * Board		  :STM32f103c6_Cortex-M3
 * author         : Aly_Mustafa_Enaya
 * brief          : Main program body
 * Date			  : 25/8/2023
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//EXTI
#define EXTI_BASE 0x40010400
#define EXTI_IMR *((volatile uint32_t *)(EXTI_BASE+0x00))
#define EXTI_RTSR *((volatile uint32_t *)(EXTI_BASE+0x08))  //Rising
#define EXTI_PR *((volatile uint32_t *)(EXTI_BASE+0x14)) //pending

//AFIO
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *((volatile uint32_t *)(AFIO_BASE+0x08))

//NVIC
#define NVIC_EXTI0 *((volatile uint32_t *)(0xE000E100))

//Clock registers address
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE+0x18))

// GPIO register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)

void clock_init (){
	//Init Clock
	RCC_APB2ENR |= (1<<0); //Alternate function IO clock enable
	RCC_APB2ENR |= (1<<2); //IO port A clock enable
	AFIO_EXTICR1 = 0x00; //These bits are written by software to select the source input for EXTI0 external interrupt.
}

void GPIO_init (){
	//Pin13 POARTA OUTPUT
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	//Pin0 POARTA INPUT floating
	GPIOA_CRL |= (1<<2);
}

void EXTI0_init (){
	//Init EXTI
	EXTI_IMR |=(1<<0); //Interrupt Mask on line 0
	EXTI_RTSR |=(1<<0); //Rising trigger event configuration bit of line 0
	//NVIC
	NVIC_EXTI0 |= (1<<6);

}

int main(void)
{
	clock_init ();
	GPIO_init ();
	EXTI0_init ();
	while(1);
}


void EXTI0_IRQHandler (){
	//Toggle Led
	GPIOA_ODR ^=(1<<13);
	//Clear The EXTI0 Pending request
	EXTI_PR |=(1<<0);

}
