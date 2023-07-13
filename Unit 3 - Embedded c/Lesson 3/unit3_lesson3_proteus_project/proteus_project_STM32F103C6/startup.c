
#include "stdint.h"

void Rest_Handler(void) ;
extern int main(void);

extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
extern unsigned int _E_text;
extern unsigned int _stack_top ;

void Default_Handler() 
{
	Rest_Handler();
}


void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void MM_fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Bus_Fault(void)__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;


unsigned int vectors[] __attribute__((section(".vectors"))) = {
	
(unsigned int )&_stack_top ,
(unsigned int ) &Rest_Handler,
(unsigned int ) &NMI_Handler,
(unsigned int ) &H_fault_Handler,
(unsigned int ) &MM_fault_Handler,
(unsigned int ) &Bus_Fault,
(unsigned int ) &Usage_Fault_Handler,
};


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