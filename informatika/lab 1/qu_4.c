

#include <stdio.h>
#include <math.h>


int main(void){
    int secs,day,hour,min,sec;
    printf("enter number of seconds : ");
    scanf("%d",&secs);
    day=secs/60/60/24;
    hour=secs/60/60%24;
    min=secs/60%60%24;
    sec=secs%60%60%24;
    printf("%d days and %d hours and %d minutes and %d sec's\n",day,hour,min,sec);
    return 0;
}