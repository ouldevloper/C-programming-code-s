#include <stdio.h>

int main(void){
    int year;
    printf("Enter year :");
    scanf("%d",&year);
    printf("The year %4d is %d\n",year,(year%4 == 0 && year%100 != 0 || year%400 == 0));
    return 0;
}