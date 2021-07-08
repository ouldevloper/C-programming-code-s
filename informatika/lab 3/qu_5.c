#include <stdio.h>
#include <math.h>
#define i -2
int fact(int k){
    if(k==1) return 1;
    else return k*fact(k-1);
}
int main(void){
    int k;
    scanf("%d",&k);
    double res=0.0;
    for (int j=0;j<=k;j++){
        res+=(pow(-1,i)*fact(i+3))/(2*(i-4));
    }
    printf("%lf",res);
    return 0;
}