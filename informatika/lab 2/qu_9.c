#include <stdio.h>
int main(void){
    int day,month;
    char *keys[]={"Козерог","Водолей","Рыбы","Овен","Телец","Близнецы","Рак","Лев","Дева","Весы","Скорпион","Стрелец","Козерог"};
    do{
        scanf("Enter Day Month : %d %d",&day,&month);
    }while((day<1||day>31)||(month<1||month>12));
    day>=22?printf("%s",keys[month]):printf("%s",keys[month-1]);
    return 0;
}