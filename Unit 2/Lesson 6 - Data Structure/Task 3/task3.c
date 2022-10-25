/*
 * task3.c
 *
 *  Created on: ٢٤‏/١٠‏/٢٠٢٢
 *      Author: metro
 */
#include <stdio.h>
struct snumber {
    float real ;
    float img ;
};
struct snumber readnum (char name[] ) {
    struct snumber c ;
    printf("Enter %s complex number (Ex: 4,-3) : " , name);
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
     scanf ("%f" , &c.real);
     setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
     scanf ("%f" , &c.img);
     return c;
}
struct snumber addnum (struct snumber x , struct snumber y){
    struct snumber c ;
    c.real = x.real + y.real ;
    c.img = x.img + y.img ;
    return c;
}
void printnum (struct snumber z){
    printf ("\nSum = %0.2f + %0.2fj" , z.real,z.img);
}
int main() {
    struct snumber x,y,z ;
    x = readnum ("x");
    y = readnum ("y");
    z = addnum(x, y);
    printnum(z);
    return 0;
}
