/*
     Author:Aly mustafa
 */

#include <stdio.h>

int check_prime (int num);

int main () {
	int start ;
	int end , flag ;
	printf("Enter Two Numbers (Intervals) :");
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	scanf("%d %d" , &start , &end);
	printf("The Primary Numbers between %d and %d is :" , start , end);
	for (start ; start <end ;start++)
	{
		flag = check_prime(start);
		if (flag == 1)
			printf("%d\t" ,start);
	}
	return 0;
}

int check_prime (int num)
{
	int j;
	int flag =1;
	for (j=2; j < num ; j++)
	{
		if(num % j == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag ;
}

