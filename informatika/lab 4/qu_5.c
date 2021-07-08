#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define index 15
int rand_int(int min,int max){
    return min+rand()%(max+1-min);
}
void one_dim(int lenght,int arr[lenght]){
    for (unsigned short int i=0;i<lenght;i++)
        arr[i] = rand_int(-99,99);
}

int main(void){
    int arr[index],largest_index=0,max=0;
    one_dim(index,arr);
    for (unsigned short int i = 0; i < index; i++){
        printf("%d \n",arr[i]);
        if(arr[i]>0&&arr[i]>max&&arr[i]%2!=0)largest_index=i;
    }
    printf("res : %d\n",largest_index);
    return 0;
}