#include <stdio.h>
int main(void){
    int day_num,index=1;
    char *keys[]={"jun","fev","mar","ap","may","ju","juil","aug","sp","oct","nov","dec"};
    do{
        scanf("%d",&day_num);
    }while(day_num<1||day_num>365);
    while(day_num>=30){
        index>8?(index!=2?(index%2?(day_num-=30):(day_num-=31)):(day_num-=28)):(index%2?(day_num-=31):(day_num-=30));
        index++;
    }
    printf("%d %s\n",day_num,keys[index-1]);
    return 0;
}