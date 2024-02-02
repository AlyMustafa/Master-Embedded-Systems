/*
 * MemMap.h
 *
 * Created: 04/09/2023 05:14:09 م
 *  Author: Metro
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define PORTA (*(volatile unsigned char*)0x3A)
#define DDRA  (*(volatile unsigned char*)0x3B)
#define PINA  (*(volatile unsigned char*)0x39)


#define PORTD (*(volatile unsigned char*)0x32)
#define DDRD  (*(volatile unsigned char*)0x31)
#define PIND  (*(volatile unsigned char*)0x30)




#endif /* MEMMAP_H_ */