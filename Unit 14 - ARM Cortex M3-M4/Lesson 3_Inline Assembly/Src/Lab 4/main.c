
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

#include "STM32F103x6.h"
#include "GPIO.h"
#include "EXTI.h"
//int flag=0;

uint8_t flag = 0;
void EXT0_CallBack(){
		MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
}
int out;
int in1 = 2;
int in2 = 1;
int main(void)
{
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	
	GPIO_config_t PB1 =  {GPIO_PIN_1 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };
	MCAL_GPIO_Init(GPIOB, &PB1);
	
	EXTI_Config_t EXT_cfg = { EXTI0PB0, EXTI_IRQ_Enable , EXTI_Trigger_RISING , EXT0_CallBack };
	MCAL_EXTI_GPIO_Init (&EXT_cfg);
	
	__asm("nop \n\t nop \n\t nop \n\t nop");
	__asm("add %[out],%[in1],%[in2]"
	 :[out] "=r"(out)
	 :[in1] "r"(in1) ,
		[in2] "r"(in2) );
	__asm("nop \n\t nop \n\t nop \n\t nop");

	while(1)
	{
		if (MCAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))
		{
			MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		}
	}
}
