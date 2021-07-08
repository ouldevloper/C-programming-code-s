#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_char(char * str,char b){ 
    int count=0,len=strlen(str);
    for(int i=0;i<len;i++) if(*(str+i) == b )count++;
    return count; 
}
int main(void){
    char a;
    char *b=(char *)malloc(sizeof(char *)*4);
    scanf("%c",&a);
    scanf("%s",b);
    int res = count_char((char *)b,a);
    printf("the count of [%c] in the str is : %d\n",a,res);
    return 0;
}