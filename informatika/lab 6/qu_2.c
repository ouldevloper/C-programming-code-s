#include <stdio.h>
#include <stdlib.h>
struct array{
    void * item;
    struct array * next;
};
typedef struct array * List;
int count(List l){
    int counter=0;
    List tmp=l;
    while(tmp){tmp=tmp->next;counter++;}
    return counter;
}
void display(List list){
    List tmp=list;
    if(tmp!=NULL){
        while(tmp!=NULL){
            printf("%d\n",tmp->item);
            tmp=tmp->next;
        }
    }
}
List new(void * item){
    List new = (List)malloc(sizeof(List));
    new->item = item;
    new->next = NULL;
    return new;
}
List update(List list,void * item,void * item_){
    if(list){
        List tmp=list;
        while(tmp->next){
            if(tmp->item==item){
                tmp->item=item_;
            }else
                tmp=tmp->next;
        }
        return list;
    }
    return NULL;
}
List append(List list,void * item){
    List new=(List)malloc(sizeof(List));
    new->item=item;
    new->next=NULL;
    if(list==NULL){
        return new;
    }else{
        List tmp=list;
        while(tmp->next!=(void*)0) tmp=tmp->next;
        tmp->next = new;
        return list;
    } 
}
List insert(List list,void * item,int index){
    List new=(List)malloc(sizeof(List));
    new->item=item;
    new->next=NULL;
    if(list==NULL) return new;
    else{
        List tmp=list;
        int counter=0;
        int len=count(list);
        while(counter<=len){
            if(counter==index){
                tmp->next=tmp;
                tmp->item=item;
            }
            else if (counter<index){
                tmp=tmp->next; 
            }else{
                tmp->next=tmp;
            }
            counter++;
        }
        return list;
    }
}
List delete(List list,void * item){
    List tmp=list;
    while(tmp->next){
       if(tmp->next->next){
           
       }
    }
    tmp=NULL;
    return list;
}
int main(void){
    List list=new((void*)1);
    list=append(list,(void*)3);
    list=append(list,(void*)3);
    list=append(list,(void*)3);
    list=append(list,(void*)3);
    list=append(list,(void*)3);
    list=append(list,(void*)5);
    list=append(list,(void*)7);
    list=update(list,(void*)3,(void*)-1);
    list=delete(list,(void*)-1);
    list=delete(list,(void*)-1);
    list=delete(list,(void*)-1);
    list=delete(list,(void*)-1);
    list=delete(list,(void*)-1);
//

    display(list);
    return 0;
}