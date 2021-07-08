#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Enter a : ");
    scanf("%d",&a);
    printf("Enter b : ");
    scanf("%d",&b);
    printf("Enter c : ");
    scanf("%d",&c);
    if ((a%2==0 || b%2==0)&&(a%3==0 && b%3==0 && c%3==0)){
        printf("ok");
    }else{
        printf("No");
    }
    return 0;
}