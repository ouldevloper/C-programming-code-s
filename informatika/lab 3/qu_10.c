#include <stdio.h>
int main(void){
    int n,m,index=0;
    do{
        scanf("%d %d",&n,&m);
    }while(n==0||m==0);
    n>m ?(index=n):(index=m);
    for(int i=index;i>0;i--){
        if(n%i==0 && m%i==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}