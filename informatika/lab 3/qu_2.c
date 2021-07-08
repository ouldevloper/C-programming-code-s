#include <stdio.h>
int main(void){
    int N,index;
    scanf("%d",&N);
    index=N;
    while(--index)(N%index)?:printf("%d\n",index);
    return 0; 
}