/*
 * Utils.h
 *
 * Created: 04/09/2023 05:21:58 م
 *  Author: Metro
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(Reg,Bit)		(Reg |=(1<<Bit)) //  (Reg = Reg|(1<<Bit))
#define ResetBit(Reg,Bit)	(Reg &=~(1<<Bit)) //  (Reg = Reg &~(1<<Bit))
#define ToggleBit(Reg,Bit)	(Reg ^=(1<<Bit)) //  (Reg = Reg^(1<<Bit))
#define ReadBit(Reg,Bit)	((Reg >>Bit)&1)



#endif /* UTILS_H_ */