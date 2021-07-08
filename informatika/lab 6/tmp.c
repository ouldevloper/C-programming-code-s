#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string * String;
struct string{
    //properties
    char item;
    struct string * next;
    //methods
    void (*append) ( char);
    void (*append_)(char *);
    void (*tostring)();
    int (*count)();
};
String this=NULL;
void append(char  _char){
    String new=(String)malloc(sizeof(String));
    new->item=_char;
    new->next=NULL;
    if(this==NULL) this=new;
    else{
        String tmp=this;
        while (tmp->next!=NULL) tmp=tmp->next;
        tmp->next = new;
    }
}
void append_(char *_chars){
    String new=(String)malloc(sizeof(String));
    String swap=NULL;
    while(*_chars!='\0'){
        append(*_chars++);       
    }
}
void tostring(){
    String str=this;
    while(str){
        printf("%c",str->item);
        str=str->next;
    }
}
int count(){
    String str=this;
    int counter=0;
    while(str->next){
        counter++;
        str=str->next;
    }
    return counter;
}
String new(){
    this=(struct string *)malloc(sizeof(struct string));
    this->append=&append;
    this->append_=&append_;
    this->tostring=&tostring;
    this->count=&count;
    return this;
}
int main(void){
    this =new();
    this->append('A');
    this->append('A');
    this->append('A');
    this->append('A');
    this->append('A');
    this->append(' ');
    this->append_("\nAbdellah");
    this->append_(" Oulahyane");
    this->tostring();
    printf("\nThe counter is %d\n",this->count());
    return 0;
}