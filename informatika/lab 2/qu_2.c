#include <stdio.h>
int main(void){
    double res,price=1;
    int day,time,duration;    
    do{
        printf("Enter the day [1-7] : ");scanf("%d",&day);
    }while(day<=0 || day>7);
    do{
        printf("Enter the stared time [0-23]: ");scanf("%d",&time);
    }while(time<0 || time >23);
    do{
        printf("Enter the duration of call by minutes : ");scanf("%d",&duration);
    }while(duration<0);
    printf("Enter the price of minute : ");scanf("%f",&price);

    for(int i=1;i<=duration;i++){    
       if (day>=6 || day<=7){           
            if(time>=22 || time>8){res=res+(price*0.30);}
            else{res=res+(price*0.10);}
        }else{            
            if(time>=22 || time>8){
                res=res+(price*0.20);
            }else{
                res=res+price;
            }
        }   
        if (i%59==0){
            if(time==23){
                if(day==7){day=1;}
                else{day++;}
                time=0;
            }else{
                time++;
            }
        }      
    }
    printf("Call cost : %f \n",res);
    return 0;
}