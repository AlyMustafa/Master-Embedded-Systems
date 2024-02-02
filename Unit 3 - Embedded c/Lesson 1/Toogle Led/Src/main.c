/*
 * test.c
 *
 *  Created on: ١٢‏/٠٢‏/٢٠٢٣
 *      Author:ALy Mustafa
 */

typedef unsigned int   uint32_t;
#define Rcc_BASE   0x40021000
#define GPIO_BASE   0x40010800
#define RCC_APB2ENR *((volatile uint32_t*)(Rcc_BASE + 0x18 ))
#define GPIO_CHR    *((volatile uint32_t*)(GPIO_BASE + 0x04))
#define GPIO_ODR    *((volatile uint32_t*)(GPIO_BASE + 0x0C))


int main () {

	RCC_APB2ENR |= (1<<2);
	GPIO_CHR &= 0xff0fffff;
	GPIO_CHR |= 0x00200000;
	while (1) {

		GPIO_ODR |= (1<<13);
		for (int i =0; i<5000 ;i++);
		GPIO_ODR &=~ (1<<13);
		for (int i =0; i<5000 ;i++);
	}

	return (0);
}



