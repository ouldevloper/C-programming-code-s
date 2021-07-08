#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void){
    char *num=(char *)malloc(sizeof(char)*1024);
    if(num!=NULL){
        for(int i=1;i<10000000000;i++){
            sprintf(num,"%lld",i*i);
            int length = strlen(num);
            int a=-1,b=length;
            int isOk=1;
            while (a++<(length/2) && b-->(length/2))
            {
                if(num[a]!=num[b]){
                    isOk=0;
                    break;
                }
            }
            isOk?printf("%s => Palindrom\n",num):printf("%s => Not a Palindrom\n",num);
        }
    }
    return 0;
}