/* Unit3_Lesson4_Lab3 
Aly Mustafa 2023 */


#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R  (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long*)0x4002551c))
#define GPIO_PORTF_DATA_R  (*((volatile unsigned long*)0x400253fc))

int main(void) {
	volatile unsigned long delay_count ;
	SYSCTL_RCGC2_R = 0x00000020 ;
	for(delay_count = 0 ;delay_count<200 ; delay_count++ );
	GPIO_PORTF_DIR_R |= (1<<3);
	GPIO_PORTF_DEN_R |= (1<<3);
	while (1)
	{
	GPIO_PORTF_DATA_R |= (1<<3);
	for(delay_count = 0 ;delay_count<5000 ; delay_count++ );
	GPIO_PORTF_DATA_R &=~(1<<3);
	for(delay_count = 0 ;delay_count<5000 ; delay_count++ );

	}
	return(0);
}

//############################## to test my knowledge #################################
/*typedef union {
	volatile unsigned long all_bits;
	struct {
		volatile unsigned long reversed : 3 ;
		volatile unsigned long pin3 : 1  ;
	}Pins ;
	
}GPIO_PORTF_DATA_T ;

volatile  GPIO_PORTF_DATA_T* PORTF_DATA_R = (volatile  GPIO_PORTF_DATA_T*)0x400253fc ;


PORTF_DATA_R -> Pins.pin3 = 1 ;
for(delay_count = 0 ;delay_count<5000 ; delay_count++ );
PORTF_DATA_R -> Pins.pin3 = 0 ;
for(delay_count = 0 ;delay_count<5000 ; delay_count++ );
*/