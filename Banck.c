/************************************************************************
*	@author      : Abdellah ElMghribi (Oulahyane Abdellah)				*
*	@Description : xxxxxxxxxxxxxxxxxxxxxxx 								*
*	@Licence     : free											        *
*	@Tested      : On Linux								                *
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _MAX_PASS_LENGHT  9999


typedef struct
{
	char *Id;
	int pin;
	double solde;
}user;
user 	user1; //variable de type user
int 	userpass;
int 	x;
int 	i=0;
int 	newSolde=0;
int 	newpass,newpass1;
char 	*usr;
int pass;
int y=0;

int main(int argc, char const *argv[])
{
	//strcpy(user1.Id,"abdellah");

	//user1.pin   = 1234;
	//user1.solde = 250050;
	printf("*********************[ Welcome To Your Bank ]*****************\n\n");
	do{

		login:
		printf("*********************[ Login ]*****************\n\n");
		printf("Enter ID       :");
		scanf("%s",&usr);
		printf("Enter UserPass :");
		scanf("%s",&pass);
		if(usr==user1.Id&& pass==user1.pin){
				do
				{

					//system("clear");
					bigin:
					printf("\t1 : Afficher Le Soulde \n");
					printf("\t2 : Ajouter Le Solde\n");
					printf("\t3 : Tirer Le Solde\n");
					printf("\t4 : Changer Le Mote De Pass\n");
					printf("\t0 : deconnection\n");
					printf("\n\t \t=> ");
					scanf("%d",&x);
					switch(x){
						case 1:
						{
							//bigin1:
							//system("clear");
							printf("Le Solde Est : %f $ \n",user1.solde);
							goto bigin;

						}
						break;
						case 2 :
						{
							//bigin2:
							//system("clear");
							printf("Enter le solde que vous vouler Ajouter : ");
							scanf("%ld", &newSolde);
							user1.solde+=newSolde;
							newSolde=0;
							x=100;
						}
						break;
						case 3:
						{
							//bigin3:
							printf("Entre Le solde que voulez vous tirer :");
							scanf("%ld",&newSolde);
							if(newSolde<=user1.solde)
							{
								user1.solde-=newSolde;
								newSolde=0;
							}else
							{
								printf("le solde que vous voulez entre est superieur que voutre solde Essayer un autre fois." );
							}
							x=100;
							break;
						}
						case 4:
						{
							bigin4:
							//system("clear");
							printf("Entre Le Nouvo Mote De pass : ");
							scanf("%s",&newpass);
							printf("Confirmer Le Mote De Pass   : ");
							scanf("%s",&newpass1);
							if(newpass==newpass1){
								if(isdigit(newpass)&&isdigit(newpass1)){
									if(newpass >=_MAX_PASS_LENGHT){

											user1.pin=newpass;

									}else{
										printf("\nLe Mote De Pass Makhasouch Idepasser 4 d l2ar9am Essayer... \n");
										goto bigin4;
									}
								}
								else
								{
											printf("l mte de pass khassou ikon ghir l2ar9am hhhh\n");
								}
							}
							else
							{
								printf("\nles Mote de pass not b7al b7a hhhh Essayer (MIX 3 Language) \n");
								goto bigin4;
							}

						}
						case 0:
						{
							//system("clear");
							goto login;
						}
						x=100;

					}
				} while (x!=0);
		}else{
			printf("Error les info incorrect ....\n");
			goto login;
			y++;
	}
	}while(y<3);
	printf("*********************[ Bay See You Next Time ]*****************\n");
	return 0;
}

