#include <stdio.h>

int calc(int n){
    if(n==0) return 0;
    return n+calc(n-1);
}
int pwr(int n,int os){
    if(os==0) return 1;
    return n*pwr(n,os-1);
}
int main(void){
    int n;
    printf("Enter n ");
    scanf("%d",&n);
    printf("%d\n%d\n",pwr(2,n),calc(n));
    return 0;
}