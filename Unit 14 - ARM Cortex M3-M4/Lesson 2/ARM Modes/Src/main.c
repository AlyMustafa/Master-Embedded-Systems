
/**
 ******************************************************************************
 * file           : main.c
 * Board		  :STM32f103c6_Cortex-M3
 * author         : Aly_Mustafa_Enaya
 * brief          : Main program body
 * Date			  : 15/12/2023
 ******************************************************************************
 */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//#include "../Stm32_F103C6_Drivers/inc/STM32F103x6.h"
//#include "../Stm32_F103C6_Drivers/inc/Stm32f103c6_GPIO_driver.h"
#include "STM32F103x6.h"
#include "GPIO.h"
#include "EXTI.h"

uint8_t flag = 0;
void EXT0_CallBack(){
	flag = 1;
}

int main(void)
{
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	
	EXTI_Config_t EXT_cfg = { EXTI0PB0, EXTI_IRQ_Enable , EXTI_Trigger_RISING , EXT0_CallBack };
	MCAL_EXTI_GPIO_Init (&EXT_cfg);
	
	flag = 1;
	
	while(1)
	{
		if (flag)
		{
			flag=0;
		}
	}
}
