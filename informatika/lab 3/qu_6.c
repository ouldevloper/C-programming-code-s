#include <stdio.h>
#include <math.h>
#define i 1
#define k 3
#define kk k+7
double fact(int n,int x){
    if(n==0)return 0;
    else{
        double s=pow(-1,k-1)/(k-5)*pow(x,k);
        return s+fact(n-1,x);
    }
}
double product(int l){
    if(l==1)return 1;
    else{
        double a=(pow(i,3)-27)/(i-7);
        return a*product(l-1);
    }
}
int main(void){
    int n,x;
    scanf("%d %d",&n,&x);
    double a=product(kk)*fact(n,x);
    printf("%lf\n",a);
    return 0;
}