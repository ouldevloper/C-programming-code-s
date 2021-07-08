#include <stdio.h>
#include <math.h>
#define PI 3.14
int fact(int n){
    if(n==1) return 1;
    else return n+fact(n-1);
}
int main(void){
    int x=0,end;
    scanf("%d %d",&x,&end);
    double res=1.00;
    for(int i=1;i<=end;i++){
        res+=(sin(i*(PI/4)))*pow(x,i)/fact(i);
    }
    printf("%lf\n",res);
}