/*
 * task4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: metro
 */

/*
 * task4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ali Mustafa
 */

#include <stdio.h>
int power (int a , int b){
	static i = 0 , f=1 ;
	if (i < b)
	{
		f*= a;
		i++ ;
		power(a,b);
	}
    return (f);
}

void main()
{
	int num ,pow ;
	printf ("Enter Base Number : ");
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	scanf ("%d" , &num);
    printf ("Enter Power Number : ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	scanf ("%d" , &pow);
	printf ("%d ^ %d = %d" , num ,pow, power(num ,pow));
}

