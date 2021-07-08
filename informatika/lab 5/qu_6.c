#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void){
    int sum=0,i=0;
    char *str=(char *)malloc(sizeof(char *)*32);
    scanf("%s",str);
    while(*(str+i)!='\0'){
        if(isdigit(*(str+i))) sum+=(int)*(str+i)-48;
        i++;
    }
    printf("the sum of digites in the string is %d\n",sum);
    return 0;
}