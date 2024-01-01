
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
enum CPUAccessLevel
{ 	Privileged ,
		unPrivileged
};
	
void SWITCH_CPU_AccessLevel(enum CPUAccessLevel level)
	{
	switch(level){
		case Privileged : 
		{ 
			//Clear Bit 0 in CONTROL register
			__asm(" MRS r0,CONTROL \n\t "
						" LSR r0,r0,#0x1 \n\t "
						" LSL r0,r0,#0x1 \n\t "
						" MSR CONTROL,r0 \n\t " );
			break;
		}
		case unPrivileged : 
		{ 
			//Set Bit 0 in CONTROL register
			__asm(" MRS r0,CONTROL \n\t "
						" ORR r0,r0,#0x1 \n\t "
						" MSR CONTROL,r0 \n\t " );
			break;
		}
}
}
void EXT0_CallBack(){
		MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		SWITCH_CPU_AccessLevel(Privileged);

}

int main(){
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	
	GPIO_config_t PB1 =  {GPIO_PIN_1 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };
	MCAL_GPIO_Init(GPIOB, &PB1);
	
	EXTI_Config_t EXT_cfg = { EXTI0PB0, EXTI_IRQ_Enable , EXTI_Trigger_RISING , EXT0_CallBack };
	MCAL_EXTI_GPIO_Init (&EXT_cfg);
	
	SWITCH_CPU_AccessLevel(unPrivileged);
	SWITCH_CPU_AccessLevel(Privileged);

	while(1)
	{
		if (MCAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))
		{
			MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		}
	}
}
