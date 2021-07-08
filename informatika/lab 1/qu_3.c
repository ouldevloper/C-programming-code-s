/*
	gcc 10.2.0 Debian 10.2.0-15
	plaise use -lm option while compiling program by gcc or cc
	gcc qu_3.c -o foo -lm
*/

#include <stdio.h>
#include <math.h>


int main(void){
    float a,b,c,delta;
    do{
        printf("Enter a :");
        scanf("%f",&a);
    }while(a==0);
    printf("Enter b :");
    scanf("%f",&b);
    printf("Enter c :");
    scanf("%f",&c);
    delta = (b*b)-(4*a*c);
    if (delta == 0){
        float res=(-1*b)/(2*a);
        printf("Solution : %f\n",res);
    }else if(delta >0){
       float res1,res2;
       res1=((-1*b)+sqrt(delta))/(2*a);
       res2=((-1*b)-sqrt(delta))/(2*a);
       printf("Solutions : %f %f\n",res1,res2);
    }else{
        printf("Equation have no solution\n");
    }
    return 0;
}