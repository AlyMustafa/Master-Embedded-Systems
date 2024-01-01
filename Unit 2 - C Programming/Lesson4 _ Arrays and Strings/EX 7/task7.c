/*
 * task7.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly mustafa Enaya
 */
#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	char string[30];
	int counter =0;
	printf("Enter The string : ");
	gets(string);
	for(int i=0 ; i<30 ; i++)
	{
		if(string[i]!=0)
			counter++ ;
		else
			break;
	}
printf("Length of String: %d" , counter);
}
