/*
 * test.c
 *
 *  Created on: ١٢‏/٠٢‏/٢٠٢٣
 *      Author:ALy Mustafa
 */

typedef unsigned int   uint32_t;
typedef volatile unsigned int vuint32_t;
#define Rcc_BASE   0x40021000
#define GPIO_BASE   0x40010800
#define RCC_APB2ENR *((volatile uint32_t*)(Rcc_BASE + 0x18 ))
#define GPIO_CHR    *((volatile uint32_t*)(GPIO_BASE + 0x04))
#define GPIO_ODR    *((volatile uint32_t*)(GPIO_BASE + 0x0C))

//unsigned char g_vars[3]= {1,2,3};
//unsigned char const const_vars[3]= {1,2,3};
typedef union {
	
		vuint32_t  all_Bits ;
		struct
		{
			vuint32_t reversed : 13 ;
			vuint32_t pin13 : 1 ;
		}pins;
}GPIO_ODR_t ;
volatile GPIO_ODR_t* R_ODR = (volatile GPIO_ODR_t*)(GPIO_BASE + 0x0C) ;


int i=0;
int main () {

	RCC_APB2ENR |= (1<<2);
	GPIO_CHR &= 0xff0fffff;
	GPIO_CHR |= 0x00200000;
	while (1) {

		R_ODR -> pins.pin13 = 1 ;
		for (i =0; i<5000 ;i++);
		R_ODR -> pins.pin13 = 0 ;
		for (i =0; i<5000 ;i++);
	}

	return (0);
}



