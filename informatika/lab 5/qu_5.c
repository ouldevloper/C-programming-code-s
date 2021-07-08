#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char * input(char * str){
    char t;
    while((t=getchar())!='\n') *(str++)=t;
    return str;
}
int main(void){
    int i=0,tmp=0;
    int sum=0;
    char *str=(char *)malloc(sizeof(char *)+1);
    str=input(str);
    strcat(str,"a0");
    while(*(str+i)!='\0'){
        if(isdigit(*(str+i)))
            tmp=(tmp*10)+(*(str+i)-48);
        else
        {
            sum+=tmp;
            tmp=0;
        }
        i++;
    }
    printf("the sum of digites in the string is %d\n",sum);
    return 0;
}