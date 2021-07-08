#include <stdio.h>
int main(void){
    float res=0.0;
    int day=5,time=6,duration=88;
    float price=10.0f;
    
    for(int i=1;i<duration;i++){              
        if (day>=6 || day<=7){           
            if(time>=22 || time>8){
                res+=price*0.30;
            }else{
                res+=price*0.10;
            }
        }else{            
            if(time>=22 || time>8){
                res+=price*0.20;
            }else{
                res+=price;
            }
        }   
        if (i%59==0){
            if(time==23){
                if(day==7){
                    day=1;
                }else{
                    day++;
                }
                time=0;
            }else{
                time++;
            }
        }
        //res+=price*(discount/100); 
        
    }
    printf("%f\n",res);
    return 0;
}
