#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*=======[Begging Of Global Variables Declaration]=======*/

static char MDatabase[]="ManagerDataBase.dat";
static char CDatabase[]="ClientDataBase.dat";
static char ch;
static int id;

/*=======[   End Of Global Variables Declaratio  ]=======*/
#define clear() begin: \
				ch=getchar();\
				if(ch=='\n')\
					system("clear");\
				else \
					goto begin;
/*=======[Begging Of Client Struct]=======*/
typedef struct {
	int    Id;
    char   UserName[50];
    char   UserPass[50];
	char   name[255];
	char   address[255];
	float  solde;
	char   Email[50];
	char   Telephone[20];
}Client;
/*=======[  End of Client Struct  ]=======*/
/*=======[Begging Of Manager Struct]=======*/
typedef struct{
  char type[50];
  char UserID[50];
  char UserPass[50];
}Responsable;
/*=======[  End of Manager Struct  ]=======*/

/*=======[Begging Of Manager Functions Declaration]=======*/

static int  Manager_Login(int nbArgc,char *argvs[]);
static int  IsMDEmpty();
static void CheckInformationFromLogin(int a,char *b[]);
static void menuM();
//static void addClientToDAtaBase(int id,char name[],char address[],double solde,char Email[],char Telephone[],char userName[],char userPass[]);
static void addClientToDAtaBase(Client *swp);
static int  RetureClientIndex(int id);
static void RemoveClientFromDataBase(int id);
static void DumpSolde(float solde,int id);
static void AddSolde(float solde,int id);

/*=======[   End Of Manager Functions Declaratio  ]=======*/
/*=======[Begging Of Manager Functions Boddy]=======*/

int Manager_Login(int nbArgc,char *argvs[]){
	int choix;
	int found=0;
	Responsable *swp=malloc(sizeof(Responsable));
	char type[2][10]={"Derictore","Employe"};
	FILE *fd=fopen(MDatabase,"ab+");
	if(fd==NULL) exit(1);
	else{
		if(nbArgc==4){
			if(argvs[1]==type[1]||argvs[1]==type[2]){
				while(!feof(fd)&&!found){
					fread(swp,sizeof(Responsable),1,fd);
					if((strcmp(swp->UserID,argvs[2])==0)&&
						(strcmp(swp->UserPass,argvs[3])==0)
						){
						found=1;
						break;
					}else{
						found=0;
						continue;
					}
				}				

			}else{
				found=0;
			}

		}else{
			found=0;
		}
	}
	fclose(fd);
	if(found){
		return 1;
	}
	else{
		printf("invalide Password Or UserName Try Again ....\n");
		return 0;
	}

}

int IsMDEmpty(){
	FILE *fd=fopen(MDatabase,"ab+");
	Responsable * swp;
	if(fd==NULL) exit(1);
	else{
		fseek(fd,0,SEEK_SET);
		fread(swp,sizeof(Responsable),1,fd);
		if(swp==NULL) 1;
		else return 0;
	}
	fclose(fd);
}
void CheckInformationFromLogin(int a,char *aa[]){
	char *type=aa[1];
	if(Manager_Login(a,b)){
		menuM();
	}else{
		exit(1);
	}
}
static void menuM(){
	int choise,id;
	float solde=0.0;
	Client *swp =(Client *)malloc(sizeof(Client));
	Client
	do{
		printf("\n\n\t\t==================={%s panel}===================",type);
		printf("\n\t\t\t 1 : ADD CLIENT\n");
		printf("\n\t\t\t 2 : REMOVE CLIENT\n");
		printf("\n\t\t\t 3 : DUMP SOLDE\n");
		printf("\n\t\t\t 4 : ADD SOLDE\n");
		printf("\n\t\t\t 5 : ADD SOLDE\n");
		printf("\n\t\t\t 0 : QUITTER\n");
		printf("\n\t\t\t>");
		scanf("%d",&choise);
		switch(choise){
			case 1:{
				printf("Enter ID > ");
				scanf("%d",&swp->Id);
				printf("Enter Full Name > ");
				scanf("%s",&swp->name);
				printf("Enter Address > ");
				scanf("%s",&swp->address);
				printf("Enter Solde > ");
				scanf("%f",&swp->solde);
				printf("Enter Email > ");
				scanf("%s",&swp->Email);
				printf("Enter Telephone > ");
				scanf("%s",&swp->Telephone);
				printf("Enter UserName > ");
				scanf("%s",&swp->UserID);
				printf("Enter UserPass > ");
				scanf("%s",&swp->userPass);
				addClientToDAtaBase(swp);
				printf("Client Added Successfully ...\n");
				clear();
				break;
			}
			case 2:{
				printf("Enter ID > ");
				scanf("%d",&id);
				RemoveClientFromDataBase(id);
				printf("Client Removed Successfully ...\n");
				clear();
				break;
			}
			case 3:{

				printf("Enter ID > ");
				scanf("%d",&id);
				printf("Enter Solde > ");
				scanf("%d",&solde);
				DumpSolde(solde,id);
				printf("Solde Dumped Successfully ...\n");
				clear();
				break;
			}
			case 4:{

				printf("Enter ID > ");
				scanf("%d",&id);
				printf("Enter Solde > ");
				scanf("%d",&solde);
				DumpSolde(solde,id);
				printf("Solde Added Successfully ...\n");
				clear();
				break;
			}
			default :printf("Command Not Exist...\n");
		}
	}while(choise!=0);	
}
static void addClientToDAtaBase(Client *swp){//int id,char name[],char address[],double solde,char Email[],char Telephone[],char userName[],char userPass[]){
        /***********************
         *=====Members===========
         * int   Id;
         * char  name[255];
         * char  address[255];
         * float solde;
         * char  Email[50];
         * char  Telephone[20];
         **********************/
        FILE *fd=fopen(CDatabase,"ab+");
        if(fd==NULL) 
    	{
    		exit(1);
    	}
        else{
	        //Client *swp =(Client *)malloc(sizeof(Client));
	        /*swp->Id=id;
	        strcpy(swp->name,name);
	        strcpy(swp->address,address);
	        swp->solde=solde;
	        strcpy(swp->Email,Email);
	        strcpy(swp->Telephone,Telephone);
			strcpy(swp->UserName,userName);
			strcpy(swp->UserPass,userPass);*/
        	fwrite(swp,sizeof(Client),1,fd);
    	}
		fclose(fd);
		free(swp);
}
static int RetureClientIndex(int id){
//static int RetureClientID(){
	int index=-1;
	FILE *fd=fopen(CDatabase,"ab+");
	Client *swp=NULL;
	while(!feof(fd)){
		fread(swp,sizeof(Client),1,fd);
		if(swp->Id==id){
			//index=swp->Id;
			index++;
			break;
		}else{
			index++;
			continue;
		}
	}
	return index;
}
static void RemoveClientFromDataBase(int id){
	FILE *fd=fopen(CDatabase,"ab+");
	Client *swp=(Client *)malloc(sizeof(Client));
	int index=RetureClientID(id);
    if(index!=-1){
		if(fd==NULL){
			exit(1);
		}else{
			fseek(fd,index*sizeof(Client),SEEK_SET);
			fwead(swp,sizeof(Client),1,fd);
		}
	}else{
		printf("Client Not Found ...\n");
	}
	fclose(fd);
	free(swp);
}
static void DumpSolde(float solde,int id){
	int index=RetureClientIndex(id);
	Client *swp=(Client *)malloc(sizeof(Client));
	FILE *fd=fopen(CDatabase,"ab+");
	if(fd==NULL) exit(1);
	else{
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fread(swp,sizeof(Client),1,fd);
		swp->solde-=solde;
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fwead(swp,sizeof(Client),1,fd);
	}
	fclose(fd);
	free(swp);
}
static void AddSolde(float solde,int id){
	int index=RetureClientIndex(id);
	Client *swp=(Client *)malloc(sizeof(Client));
	FILE *fd=fopen(CDatabase,"ab+");
	if(fd==NULL) exit(1);
	else{
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fread(swp,sizeof(Client),1,fd);
		swp->solde+=solde;
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fwead(swp,sizeof(Client),1,fd);
	}
	fclose(fd);
	free(swp);
}
/*=======[   End Of Manager Functions Boddy ]=======*/

/*=======[Begging Of Client Functions Declaration]=======*/

static int IsCDEmpty();
static void Client_login();
static int SearchClient(int a,char b[],char c[]);
static void CMenu();
static void dumpClientSolde(float solde);
static void ChangeClientPassword(char *pass);
/*=======[   End Of Client Functions Declaratio  ]=======*/
/*=======[Begging Of Client Functions Boddy]=======*/
int IsMDEmpty(){
	FILE *fd=fopen(CDatabase,"ab+");
	Client * swp;
	if(fd==NULL) exit(1);
	else{
		fseek(fd,0,SEEK_SET);
		fread(swp,sizeof(Client),1,fd);
		if(swp==NULL) return 1;
		else return 0;
	}
	fclose(fd);
}
static int Client_login(){
	  Client * swp=(Client *)malloc(sizeof(Client));
	  FILE *fd=fopen(CDatabase,"ab+");
	  if(fd==NULL)exit(1);
	  begging:
	  if(!IsMDEmpty()){
		  system("clear");
		  printf("\n\t============[Login]============\n\n");
		  printf("\t      Enter UserID   : ");
		  scanf("%d",&swp->Id);
		  printf("\t      Enter UserNAme : ");
		  scanf("%s",&swp->UserName);
		  printf("\t      Enter UserPass : ");
		  scanf("%s",&swp->UserPass);
		  if(SearchClient(swp->Id,swp->UserName,swp->UserPass)){
		      id=swp->Id;
		      return 1;
		  }
		  else{
		    goto begging;
		  }
		}else{
			system("clear");
			printf("DataBase Is Empty ...\n");
			clear();
		}
}

static int SearchClient(int a,char b[],char c[]){
      int found=0;
      Client *swp=(Client *)malloc(sizeof(Client));
      FILE *fd=fopen(CDatabase,"rb+");
      if(fd==NULL) exit(1);
      else{
        while(!feof(fd)){
          fread(swp,sizeof(Client),1,fd);
          if(swp->Id==a&&
            (strcmp(swp->UserName,b)==0)&&
            (strcmp(swp->UserPass,c)==0)){
              found=1;
              break;
            }
            else{
            	found=0;
            }
        }
      }
      return found;
}

static void CMenu(){
	int choix;
	float solde;
	char *pass;
	if(Client_login()){
		do{
			system("clear");
			printf("\n\n\t\t============[Client Login============\n");
			printf("\n\t\t\t 	1 : Show Solde");
			printf("\n\t\t\t 	2 : Dump Solde");
			printf("\n\t\t\t 	3 : Change Password");
			printf("\n\t\t\t 	0 : Quitter");
			printf("\n\t\t\t     > ");
			scanf("%d",&choix);
			switch(choix){
				case 1:{
					ShowClientSolde();	
					clear();
					break;
				}
				case 2:{
					printf("Enter Solde > ");
					scanf("%f",&solde);
					dumpClientSolde(solde);
					clear();
					break;
				}
				case 3:{
					printf("Enter New PassWord >");
					scanf("%s",&pass);
					ChangeClientPassword(pass);
					clear();
					break;
				}
				default:printf("Command not valide ....\n");
				clear();
			}
		}while(choix!=0);
	}else{
		Client_login();
	}
}

static void dumpClientSolde(int id,float solde){
	FILE *fd=fopen(CDatabase,"ab+");
	int index=RetureClientIndex(id);
	Client *swp=(Client *)malloc(sizeof(Client));
	if(fd==NULL) exit(1);
	else{
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fread(swp,sizeof(Client),1,fd);
		swp->solde-=solde
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fwead(swp,sizeof(Client),1,fd);
		printf("Solde Dumped Seccussfully...\n");
	}
	fclose(fd);
	free(swp);
}

static void ChangeClientPassword(char *pass){
	FILE *fd=fopen(CDatabase,"ab+");
	Client *swp=(Client *)malloc(sizeof(Client));=
	int index=RetureClientIndex(id);
	if(fd==NULL) exit(1);
	else{
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fread(swp,sizeof(Client),1,fd);
		strcpy(swp->userPass,pass);
		fseek(fd,index*sizeof(Client),SEEK_SET);
		fwead(swp,sizeof(Client),1,fd);
		printf("Password Changed Seccussfully...\n");
	}
	fclose(fd);
	free(swp);
}
/*=======[   End Of Client Functions Boddy ]=======*/

static void Desplay(int a,char *b[]){
	Responsable *swp=(Responsable *)malloc(sizeof(Responsable));
	FILE *fd;
	if(IsMDEmpty()){
		fd=fopen(MDatabase,"ab+");
		if(fd==NULL) exit(1);
		strcpy(swp->type,b[1]);
		strcpy(swp->UserID,b[2]);
		strcpy(swp->userPass,b[3]);
		fwrite(swp,sizeof(Responsable),1,fd);
		fclose(fd);
		free(swp);
		menuM();
	}
	else if(a==4&&Manager_Login(a,b)){
		menuM();
	}else if(IsCDEmpty()){
		printf("Empty Client DataBase....\n");

	}else{
		CMenu();
	}
}


int main(int argc, char const *argv[])
{
	Desplay(argc,argv);
	return 0;
}