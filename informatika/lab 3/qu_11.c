#include <stdio.h>
#include <math.h>
int fact(int n){
    if(n==1) return 1;
    else return n+fact(n-1);
}
int main(void){
    int x=0,end,index=3;
    scanf("%d %d",&x,&end);
    double res=1.00;
    for(int i=1;i<=end;i++){
        res+=((i+2)*pow(x,(i*2)))/fact(i);
    }
    printf("%lf\n",res);
}