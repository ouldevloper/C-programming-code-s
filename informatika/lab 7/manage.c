#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cls system("clear");
#define check(file) if(file==NULL) return;
#define ACTIVE_DB_NAME  "active.bin"
#define DELETED_DB_NAME "deleted.bin"
typedef struct db_struct{
    int id;                      
    char title[25];              
    char distination_address[55];
    char email_subject[55];      
    char email_body[1024];       
    int distination_address_id;  
}db;
FILE * active_database;
FILE * deleted_record;
void print(db d){
    printf("ID:                  %4d\n",d.id);
    printf("Titele:              %s\n",d.title);
    printf("Distination Address: %s\n",d.distination_address);
    printf("Email Subject:       %s\n",d.email_subject);
    printf("Email Body:          %s\n",d.email_body);
    printf("Dist Addrr Id:       %d\n",d.distination_address_id);
}
void addNew(){
    cls;
    active_database=fopen(ACTIVE_DB_NAME,"ab");
    if(active_database!=NULL){
        db *d=(db*)malloc(sizeof(db));
        printf("Enter ID                   : ");
        scanf("%d",&d->id);
        printf("Enter Email Title          : ");
        scanf("%s",d->title);
        printf("Enter Distaination Address : ");
        scanf("%s",d->distination_address);
        printf("Enter Email Subject        : ");
        scanf("%s",d->email_subject);
        printf("Enter Email Body           : ");
        scanf("%s",d->email_body);
        printf("Enter Distination ID       : ");
        scanf("%d",&d->distination_address_id);
        fwrite(d,sizeof(db),1,active_database);
    }
    fclose(active_database);
    getchar();
}
void deleteById(){
    cls;
    int id;
    active_database = fopen(ACTIVE_DB_NAME,"rb");
    deleted_record = fopen(DELETED_DB_NAME,"wb");
    FILE *tmp = fopen("tmp.bin","wb");
    if(active_database!=NULL && deleted_record!=NULL && tmp!=NULL){
        db d;
        printf("\nEnter ID: ");scanf("%d",&id);
        while(fread(&d,sizeof(d),1,active_database)==1){
            if(d.id==id){
                fwrite(&d,sizeof(db),1,deleted_record);
            }else{
                fwrite(&d,sizeof(db),1,tmp);
            }
        } 
    }
    remove(ACTIVE_DB_NAME);
    rename("tmp.bin",ACTIVE_DB_NAME);
    fclose(active_database);
    fclose(deleted_record);
    fclose(tmp);
    getchar();
    cls;
}
void displayById(){
    cls;
    int id;
    db d;
    active_database = fopen(ACTIVE_DB_NAME,"rb");
    if(active_database!=NULL){
        printf("\nEnter ID: ");scanf("%d",&id);
        while(fread(&d,sizeof(d),1,active_database)==1){
            if(d.id==id)
                print(d);
        }
    }
    fclose(active_database);
    getchar();
}
void displayByFromId(){
    cls;
    int id;
    active_database = fopen(ACTIVE_DB_NAME,"rb+");
    db d;
    printf("\nEnter Distination ID: ");scanf("%d",&id);
    while(fread(&d,sizeof(d),1,active_database)==1){
        if(d.distination_address_id==id)
            print(d);
    }
    fclose(active_database);
    getchar();
}
void searchInBody(){
    cls;
    char word[55];
    active_database = fopen(ACTIVE_DB_NAME,"rb");
    db d;
    printf("\nEnter a keyword: ");scanf("%s",word);
    while(fread(&d,sizeof(d),1,active_database)==1){
        if(strstr(d.email_body,word)!=NULL)
            print(d);
    }
    fclose(active_database);
    getchar();
}
void displayAll(){
    cls;
    active_database = fopen(ACTIVE_DB_NAME,"rb");
    db d;
    while(fread(&d,sizeof(d),1,active_database)==1)
        print(d);
    fclose(active_database);
    getchar();
}
void run(){
    int choice;
    do{  
        cls;
        printf("[1] Add New Recorde \n");
        printf("[2] Delete Record By ID\n");
        printf("[3] Search by ID\n");
        printf("[4] Search by Distination ID\n");
        printf("[5] Search in BODY\n");
        printf("[6] Display All Recordes\n");
        printf("[0] Exit\n");
        printf("\n$ ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addNew();
                break;
            case 2:
                deleteById();
                break;
            case 3:
                displayById();
                break;
            case 4:
                displayByFromId();
                break;
            case 5:
                searchInBody();
                break;
            case 6:
                displayAll();
                break;          
        }
        getchar();
    }while(choice !=-1);
}
int main(void){
    run();
    free(active_database);
    return 0;
}