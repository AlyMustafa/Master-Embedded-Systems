/*
Unit3_Lesson3_Lab2
Aly Mustafa
*/

MEMORY
{
	flash(RX)	:ORIGIN	 = 0X08000000, LENGTH = 128K
	sram(RWX)	:ORIGIN	 = 0X20000000, LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
	} > flash
	
	.data : {
		*(.data)
		
	} > flash
	
	
	.bss : { *(.bss*) } > sram 
	

}
