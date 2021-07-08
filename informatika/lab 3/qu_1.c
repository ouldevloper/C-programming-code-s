#include <stdio.h>
int main(void){
    int N,index=2;
    double res=1.0;
    scanf("%d",&N);
    while(index<=N){
        res=res+(1/index++);
    }
    printf("%.2lf\n",res);
    return 0;
}