/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Aly Mustafa
 * @brief          : Main program body
 * @Board		   : STM32F103c6
 ******************************************************************************
 */

#include "STM32F103x6.h"
#include "GPIO.h"
#include "EXTI.h"
#include "TIM.h"

////###############################___Flags___###############################
	extern int _estack;
	uint32_t TASK_A_flag=0;
	uint32_t TASK_B_flag=0;
	uint32_t flag=0;

	uint32_t _S_MSP;
	uint32_t _E_MSP;

	uint32_t _S_PSP_TA;
	uint32_t _E_PSP_TA;
	uint32_t _S_PSP_TB;
	uint32_t _E_PSP_TB;

void OS_main(void)
{
	//###############################___SIZES___###############################

#define TASKA_STACK_SIZE 100
#define TASKB_STACK_SIZE 100

	 _S_MSP = &_estack;
	 _E_MSP = (_S_MSP -512);
	//Task A
	 _S_PSP_TA = (_E_MSP - 8);
	 _E_PSP_TA = (_S_PSP_TA + TASKA_STACK_SIZE);
	//Task B
	 _S_PSP_TB = (_E_PSP_TA - 8);
	 _E_PSP_TB = (_S_PSP_TB + TASKB_STACK_SIZE);
}


//#######################___OS_ref___#######################
enum CPUAccessLevel
{ 	Privileged,
	unPrivileged
};

enum CPU_SP_SELECT
{ 	MSP,
	PSP
};
//###############################___OS_APIs___###############################
#define OS_SET_PSP(task)  __asm volatile ("MOV r0, %0 \n\t MSR PSP, r0 " :: "r" (task))

#define OS_SET_SP(SP)  { switch (SP ){\
		case MSP : { __asm volatile (" MRS r0,CONTROL \n\t AND r0,r0,#0x2 \n\t MSR CONTROL,r0"); break;}\
		case PSP : { __asm volatile (" MRS r0,CONTROL \n\t ORR r0,r0,#0x2 \n\t MSR CONTROL,r0"); break; }}}


#define SWITCH_CPU_AccessLevel(level)  { switch(level){\
		case Privileged   : { __asm volatile(" MRS r0,CONTROL \n\t LSR r0,r0,#0x1 \n\t LSL r0,r0,#0x1 \n\t MSR CONTROL,r0 " ); break; }\
		case unPrivileged : { __asm volatile(" MRS r0,CONTROL \n\t ORR r0,r0,#0x1 \n\t MSR CONTROL,r0" ); break; }}}


#define OS_Generate_Exception  __asm("SVC #0x3")

void SVC_Handler()
{
	SWITCH_CPU_AccessLevel(Privileged);
}
void EXT0_CallBack()
{
	if (flag == 0){
		TASK_A_flag=1;
		TASK_B_flag=0;
		flag=1;
	}
	else if (flag == 1){
		TASK_B_flag=1;
		TASK_A_flag=0;
		flag=0;
	}
}
void TASK_A(void)
{
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 1);
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
}

void TASK_B(void)
{
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 0);
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
}

int main(){
	RCC_GPIOB_CLK_EN();

	GPIO_config_t PB9 =  {GPIO_PIN_9 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };
	MCAL_GPIO_Init(GPIOB, &PB9);

	GPIO_config_t PB7 =  {GPIO_PIN_7 , GPIO_MODE_OUTPUT_PP ,GPIO_SPEED_10M };
	MCAL_GPIO_Init(GPIOB, &PB7);


	EXTI_Config_t EXT_cfg = { EXTI0PB0, EXTI_IRQ_Enable , EXTI_Trigger_RISING , EXT0_CallBack };
	MCAL_EXTI_GPIO_Init (&EXT_cfg);

	OS_main();

	while(1)
	{
		if (TASK_A_flag == 1)
		{
			//PSP --> TASKA
			OS_SET_PSP (_S_PSP_TA);
			//SP --> PSP
			OS_SET_SP(PSP);
			//switch from Privileged to Unprivileged
			SWITCH_CPU_AccessLevel(unPrivileged);
			//Call Task A
			TASK_A();
			//***********************Reverse***********************//
			//switch from UnPrivileged to privileged
			OS_Generate_Exception;
			//SP --> MSP
			OS_SET_SP(MSP);
		}
		else if (TASK_B_flag == 1)
		{
			//PSP --> TASKB
			OS_SET_PSP (_S_PSP_TB);
			//SP --> PSP
			OS_SET_SP(PSP);
			//switch from Privileged to Unprivileged
			SWITCH_CPU_AccessLevel(unPrivileged);
			//Call Task B
			TASK_B();
			//***********************Reverse***********************//
			//switch from UnPrivileged to privileged
			OS_Generate_Exception;
			//SP --> MSP
			OS_SET_SP(MSP);

		}
	}
}
