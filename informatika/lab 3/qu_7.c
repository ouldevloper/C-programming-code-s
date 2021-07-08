#include <stdio.h>
#include <unistd.h>

int divs_sum(int n){
    int res=0;
    for(int i = 1;i<n;i++)n%i==0?(res+=i):(res+=0); 
    return res;
}
int main(void){
    for(int i =1;i<300;i++) 
        for(int y=1;y<300;y++)
            !((divs_sum(i)==y)&&(divs_sum(y)==i)&&i!=y)?:printf("%d %d\n",i,y);
    return 0;
}