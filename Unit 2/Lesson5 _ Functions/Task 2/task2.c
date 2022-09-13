/*
 * task3.c
 *
 *  Created on: ?????
 *      Author: Aly Mustafa
 */

#include <stdio.h>
#include <string.h>
void main() {
	int i;
	char name[30];
	printf ("Enter The Sentence : \n");
	gets (name);
	printf ("You Entered : ");
    puts(name);
	int length = strlen(name);

	char reverse[length];

	for(i=0 ; i < length ; i++ )
	{
		reverse[i]= name[length-1-i] ;
	}
	printf ("The Reverse Sentence : %s" , reverse);
	//puts(reverse);

}

