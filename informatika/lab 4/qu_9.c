#include <stdio.h>
#include <stdlib.h>
#define rand_int(a,b) (a+rand()%(b+1-a))
#define sum(arr,len,num) ({int sum_val=0,counter=0; for(int i=0;i<len;i++){sum_val+=arr[i][num];} sum_val;})
#define min(arr,len) ({int min_val=arr[0];for(int i=1;i<len;i++){(min_val>arr[i])?:(min_val=arr[i]);} min_val;})
#define max(arr,len) ({int max_val=arr[0];for(int i=1;i<len;i++){(max_val<arr[i])?:(max_val=arr[i]);} max_val;})
#define tow_dim(len1,len2,arr1) ({for (int i=0;i<len1;i++) {for(int j=0;j<len2;j++){arr[i][j]=rand_int(-99,99);}}})
#define index1 3
#define index2 3
void answare(int len1,int len2,int arr[len1][len2]){
    for(int row=0;row<len1;row++) printf("row %d [min %d|max %d]\n",row,min(arr[row],len2),max(arr[row],len2));
    for(int column=0;column<len2;column++) printf("column %d [sum %d]\n",column,sum(arr,len2,column));
    printf("\n");
}
int main(void){
    int arr[index1][index2];
    tow_dim(index1,index2,arr);
    answare(index1,index2,arr);     
    return 0;

}