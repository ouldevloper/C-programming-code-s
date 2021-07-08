#include <stdio.h>
int main(void){
    int x,y;
    scanf("%d %d",&x,&y);
    int a = ((x > -1 && x < 1 && y > -1 && y < 1))&&
            ((x < 0 && (y > (x + 1) || y < (-x – 1))) ||
             (x > 0 && (y > (-x + 1) || y < x – 1))));
    if (a)
    	printf("Yes");
    else
    	printf("No");
    return 0;
}
