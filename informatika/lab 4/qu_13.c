//PS sizeof(arr)/sizeof(arr[0]) doesn't work
#include <stdio.h>
#include <stdlib.h>
void tow_dim(int len,int arr[len][len]){
    for (int i=0;i<len;i++) 
        for(int j=0;j<len;j++)
            arr[i][j]=0;
}
void y(int len,int arr[len][len]){
    int j;
    int val=len*len-1;
    for(int i=0;i<len/2;i++){
        for (    j = i; j < len-i; j++)     arr[i][j]=val--;   
        for (int l = i+1; l <len-i; l++)    arr[l][j-1]=val--;
        for (int m = j-2; m >= i ; m--)     arr[j-1][m]=val--;
        for (int n = j-2; n > i ; n--)      arr[n][i]=val--;
    }
}
int main(void){
    int l;
    scanf("%d",&l);
    int arr[l][l];
    tow_dim(l,arr);
    y(l,arr);
    for(int i=0;i<l;i++){ 
        for(int y=0;y<l;y++) 
            printf("%3d ",arr[i][y]);
        printf("\n");
    }
    return 0;
}