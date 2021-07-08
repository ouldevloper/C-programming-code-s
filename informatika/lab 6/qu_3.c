#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void spaces(int len,char sp[len]){
    for (int i=0;i<len;i++) sp[i]=' ';
}
void print_format(FILE *fp,int line,int space){
    char *tmp=(char*)malloc(sizeof(char*));
    int pos=0;
    int l=0;
    char sp[space];
    for(;pos<space;pos++)sp[pos]=' ';
    sp[pos]='\0';
    pos=0;
    while (fscanf(fp, "%s", tmp) != EOF) {
        l=strlen(tmp)/2;
        if(l+pos>=line){
            putchar('\n');
            pos=0;
        }
        printf("%s%s",tmp,sp);
        pos+=space+l+1;
    }
    free(fp);
}
int main(int argc, char *argv[])
{
    //usage : ./foo <filename> <line_lenght> <space_lenght> >> output.txt
    FILE *fp;
    char *name=(argc>=2)?argv[1]:"input.txt";
    int   line=(argc>=3)?atoi(argv[2]):100;
    int  space=(argc>=4)?atoi(argv[3]):1;
    if ((fp = fopen(name, "r")) == NULL) {

        puts("Usage ./prgram_name <file_name> <line_lenght> <space_lenght>");
        puts("      line_lenght : how much chars in one line");
        puts("      space_lebnt : how much space we put for each space");
        exit(-1);
    }
    print_format(fp,line,space);
    return 0;
}

