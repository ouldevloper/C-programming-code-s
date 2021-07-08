#include <stdio.h>
int main(void){
    int i;
    int p = 1,n;
    scanf("%d",&n);
    for(i=0; p<=n; i++)  p*=10;
    p /= 10;
    for(int j=0; j<i; j++) {
        printf("%d",n/p);
        n %= p;
    }
    return 0;
}