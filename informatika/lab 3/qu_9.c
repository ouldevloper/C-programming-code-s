#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void){
    char *num=(char *)malloc(sizeof(char)*1024);
    if(num!=NULL){
        scanf("%s",num);
        int length = strlen(num),res=0;
        char str[length];
        for (int i=0;i<length;i++) res+=pow((num[i]-'0'),length);
        snprintf( str, length + 1, "%d", res );
        strcmp(num,str)?printf("It's Not OK\n"):printf("It Ok\n");      
    }
    return 0;
}