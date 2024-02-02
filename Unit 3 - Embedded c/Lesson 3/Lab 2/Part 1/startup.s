/*Learn-in-depth
Unit3_Lesson3_Lab2 
Aly mustafa Enaya-2023*/

.section .vectors

.word 0x20001000 /*stack top address*/
.word _reset     /*1 Reset*/
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler

.section .text
_reset:
	bl main
	b .
	
.thumb_func
Vector_handler:
		b _reset
		