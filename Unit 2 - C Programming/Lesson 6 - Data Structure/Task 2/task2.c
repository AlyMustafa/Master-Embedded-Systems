/*
 * task2.c
 *
 *  Created on: ٢٤‏/١٠‏/٢٠٢٢
 *      Author: metro
 */


#include <stdio.h>
struct Sdistance {
    int ft;
    float in ;
} d1 , d2 ;
int main() {
    int sumft ;
    float sumin ;
    printf("Enter The information for 1st distance\n");
    printf("Enter Feet: ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%d" , &d1.ft);
    printf("Enter Inch: ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%f" , &d1.in);

    printf("Enter The information for 2st distance\n");
    printf("Enter Feet: ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%d" , &d2.ft);
    printf("Enter Inch: ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%f" , &d2.in);

    sumft = d1.ft + d2.ft ;
    sumin = (d1.in + d2.in);
    if (sumin > 12)
    {
        ++sumft;
        sumin = sumin - 12 ;
    }
    printf("Sum of Distances = %d - %0.1f" , sumft , sumin );

    return 0;
}
