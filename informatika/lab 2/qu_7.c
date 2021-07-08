#include <stdio.h>
int main(void){
    int num,index;
    char *keys[]={"копейка","копеек","копейки"};
    do{printf("Enter number [1-99]");scanf("%d",&num);}while(num>99 || num<1);
    num==1?index=0:((num>1&&num<6)?index=1:(index=2));
    printf("%d %s\n",num,keys[index]);
    return 0;
}