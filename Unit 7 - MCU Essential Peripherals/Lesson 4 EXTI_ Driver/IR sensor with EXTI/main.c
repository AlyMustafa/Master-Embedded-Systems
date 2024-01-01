
/**
 ******************************************************************************
 * file           : main.c
 * Board		  :STM32f103c6_Cortex-M3
 * author         : Aly_Mustafa_Enaya
 * brief          : Main program body
 * Date			  : 6/11/2023
 ******************************************************************************
 */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//#include "../Stm32_F103C6_Drivers/inc/STM32F103x6.h"
//#include "../Stm32_F103C6_Drivers/inc/Stm32f103c6_GPIO_driver.h"
#include "STM32F103x6.h"
#include "stm32f103c6_GPIO.h"
#include "stm32f103c6_EXTI.h"
//int flag=0;


void EXT0_CallBack(){
	Led_on();

}


void wait_ms(int x){

	int i,j;
	for(i=0 ; i<j ; i++){
		for(j=0 ; j<255 ; j++);
	}
}

void Led_on()
{
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);

}
void Led_off()
{
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);

}

int main(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	GPIO_config_t x1 =  {GPIO_PIN_0 , GPIO_MODE_INPUT_FLO ,GPIO_SPEED_10M };
	GPIO_config_t x2 =  {GPIO_PIN_1 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };
	GPIO_config_t x3 =  {GPIO_PIN_2 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };
	GPIO_config_t x4 =  {GPIO_PIN_3 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };

	EXTI_Config_t EXT_cfg = { EXTI0PB0, EXTI_IRQ_Enable , EXTI_Trigger_FALLING , EXT0_CallBack };

	MCAL_EXTI_GPIO_Init (&EXT_cfg);

	MCAL_GPIO_Init(GPIOB, &x1);
	MCAL_GPIO_Init(GPIOA, &x2);
	MCAL_GPIO_Init(GPIOA, &x3);
	MCAL_GPIO_Init(GPIOA, &x4);

	Led_off();
	while(1)
	{
		if ( (MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1) )
		{
			Led_off();
			//flag=0;

		}


	}
}
