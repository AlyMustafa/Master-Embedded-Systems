/**
 ******************************************************************************
 * @file           : startup.c
 * @author         : Aly Mustafa
 * @brief          : lab3 in lesson4 in Embedded C
 * @kit            : TivaC
 * @date           : 15/7/2023
 * @board          : TM4C123
 * @processor      : ARM Cortex M4
 ******************************************************************************
**/
void Rest_Handler(void) ;
extern int main(void);
void Default_Handler() 
{
	Rest_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;


//reserve stack size 
static unsigned long Stack_top[256]; 
//create vector table as array of pointers to function
       void (* const g_p_fn_Vectors[])()__attribute__((section(".vectors"))) =
	   {
		(void(* const)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
		&Rest_Handler,
		&NMI_Handler,
		&H_fault_Handler 
	   };

extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
extern unsigned int _E_text;

void Rest_Handler(void)
{
	//copy data from flash to sram 
unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
unsigned char* P_src = (unsigned char*)&_E_text ;
unsigned char* P_dis = (unsigned char*)&_S_DATA ;

int i=0;
	for (i; i < DATA_size ; i++ ) {
		
		*((unsigned char*)P_dis++) = *((unsigned char*)P_src++);
	}
	
	//init the .bss section
unsigned int BSS_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
P_dis = (unsigned char*)&_S_bss ;
i=0;
	for (i ; i < BSS_size ; i++ ) {
		
		*((unsigned char*)P_dis++) = (unsigned char)0;
	}
	//jump to main
	main();
}