#include <stdio.h>
#include <stdlib.h>
#define rand_int(a,b) (a+rand()%(b+1-a))
#define tow_dim(len1,len2,arr1) ({for (int i=0;i<len1;i++) {for(int j=0;j<len2;j++){arr[i][j]=rand_int(-99,99);}}})
#define index1 3
#define index2 3
void answare(int len1,int len2,int arr[len1][len2]){
    int min=arr[0][0],column=0;
    int num,counter=0;
    scanf("%d",&num);
    for (int i = 0; i < len1; i++)
        for (int j= 0; j < len2; j++) (arr[i][j]==num)?counter++:(counter+=0);      
    printf("the numbre %d repeted  %d times \n", num,counter);
}
int main(void){
    int arr[index1][index2];
    tow_dim(index1,index2,arr);
    answare(index1,index2,arr);     
    return 0;

}