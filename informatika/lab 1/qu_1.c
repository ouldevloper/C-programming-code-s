/*
	gcc 10.2.0 Debian 10.2.0-15
	plaise use -lm option while compiling program by gcc or cc
	gcc qu_1.c -o foo -lm
*/

#include <stdio.h>
#include <math.h>

int main(void){
	int x,y;
	float result=0.0f;
	printf("Enter x :");
	scanf("%d",&x);
	printf("Enter y : ");
	scanf("%d",&y);
	result=pow((pow((2+y),2)+pow((sin(y+5)),(1/7))),(1/2))/(log(x+1)-pow(y,3));
	printf("F : %f\n",result);
	return 0;
}
