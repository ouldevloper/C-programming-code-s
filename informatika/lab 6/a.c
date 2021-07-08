#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char * string;
char * String(){
    return (char*)malloc(sizeof(char*));
}
int main(){
    string *a;
    *a=String();
    FILE *file=fopen("vim.txt","r+");
   // char *t=malloc(sizeof(char*));
   // while (fgets(t,1024,file)!=NULL)
   // {
   //     //a=realloc(a,sizeof(char*)); 
   //     strncat(*a++,t,8);       
   // }
   //puts(a);
    *(a++)=(char*)malloc(sizeof(char*));
    strcat(*(*a),"sfdgsdgfsdfgsdfg"); 
    *(a++)=(char*)malloc(sizeof(char*));
    strcat(*(*a),"sfdgsdgfsdfgsdfg"); 
    *(a++)=(char*)malloc(sizeof(char*));
    strcat(*(*a),"sfdgsdgfsdfgsdfg"); 
    fclose(file);
    return 0;
}