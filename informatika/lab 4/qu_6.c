#include<stdio.h> 
#include <stdlib.h> 
#define len 15
int rev(int num){
    if(num<10&&num>-10)return num*10;
    int res=0;
    while (num!=0)
    {
        res=res*10+(num%10);
        num/=10;
    }
    return res;
}
int rand_int(int min,int max){
    return min+rand()%(max+1-min);
}
void one_dim(int lenght,int arr[lenght]){
    for (unsigned short int i=0;i<lenght;i++)
        arr[i] = rand_int(-99,99);
}
int main(void)    
{    
    int arr[len];
    one_dim(len,arr);
    for(int i=0;i<len;i++) {printf("%d\t",arr[i]);arr[i]=rev(arr[i]); printf("%d\n",arr[i]);}  
    return 0;  
}   