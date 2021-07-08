/*
	gcc 10.2.0 Debian 10.2.0-15
	plaise use -lm option while compiling program by gcc or cc
	gcc qu_2.c -o foo -lm
*/

#include <stdio.h>
#include <math.h>


int main(void){
    float t=0.0f;
    float result=0.0f;
    printf("Enter t : ");
    scanf("%f",&t);
    result=pow(t,3)+3*pow(t,2)+2;
    printf("S : %f \n",result);
    return 0;
}