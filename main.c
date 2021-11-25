#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char CIN[6];
  char Nom[20];
  char Prenom[20];
  float Montant;
}information;
int code;
int choix,i,j,nb=3,n=0,exe,indexx,trimontont,indexAffichage,indexrech,indexcase2;
char cin[6];
float montant,t ;

information T ;
information info[]={{"H456","Ahmed","ALAMI",10000},{"H789","omar","hakimi",12000},{"H123","meriam","benSalah",13000}};

void rechercheCIN(char CIN[6]){ //fonction test CIN
	for(indexrech=0;indexrech<nb+n;indexrech++){	
                if(strcmp(info[indexrech].CIN,CIN)==0){
        				 exe=0;
        				 indexx=indexrech;
        				 break;
					}else{
						exe=1;
			}
	}
	//return exe;		
}
void creercompt(){
	CIN:
		printf("\t\t\t\tEntrez Votre CIN : ");
        	scanf(" %s",cin);
        	rechercheCIN(cin);
			if(exe==0){
			printf("\n\tle compte exist\n");
			goto CIN;
			}else{        	
		    strcpy(info[nb].CIN,cin);
            printf("\n\t\t\t\tNom : ");
            scanf("%s",info[nb].Nom);
            printf("\n\t\t\t\tPrenom : ");
            scanf("%s",info[nb].Prenom);
            printf("\n\t\t\t\tMontant : ");
            scanf("%f",&info[nb].Montant);
           // Affichage(nb);
            // nb++;
			}
}

void Ascendant(){
	for(i=0;i<nb+n;i++){
           	 		for(j=i+1;j<nb+n;j++){
           	 			if(info[i].Montant>info[j].Montant){
           	 			   T = info[i];
           	 			   info[i]=info[j];
           	 			   info[j]=T;
						}//fin if
					 } 	//fin for j
					}//fin for i
					
}
void Descendant(){
	for(i=0;i<nb+n;i++){
           	 		for(j=i+1;j<nb+n;j++){
           	 			if(info[i].Montant<info[j].Montant){
           	 			   T = info[i];
           	 			   info[i]=info[j];
           	 			   info[j]=T;
						}//fin if
					 } 	//fin for j
					}//fin for i
					
}

void Affichage(int nb){//fonction Affichage
    	for(i=0;i<nb;i++){
			printf("__________________\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
	}
}
int main() {
	printf("\t\t\tBienvenue dans mon proposition de projet sas :)\n ");
	do{
		
     	printf("\t\t\t\tEntrez le code: ");
        scanf("%d",&code);
        printf("le code inccorecte!!\n");
     	}while(code!=1234);
     	system("cls") ;
    Menu:
    printf("\n__________________________________**Menu**_______________________________\n\n");
    printf("\t\t\t\t1-Introduire un compte bancaire\n\t\t\t\t2-Introduire plusieurs comptes bancaires\n\t\t\t\t3-Operations\n\t\t\t\t4-Affichage\n\t\t\t\t5-Fidelisation\n\t\t\t\t6-Quitter l'application\n");
    printf("\n________________________________________________________________________\n");
	printf("\t\t\t\tEntrez Votre Choix : ");
    scanf("%d",&choix);
    switch(choix){
        case 1://///////////////////////////////////////////////1///////////////////////////////////////////////////
          creercompt();
          	nb+=1;
            Affichage(nb);	
            
	  	 goto Menu;
        break;
        
        
        case 2://////////////////////////////////////////////////2////////////////////////////////////////////////
            printf("\t\t\t\tDonnez le nombre des client qui vous Ajoute ");
        	scanf("%d",&n);
        	for(i=nb;i<nb+n;i++){
        	 CIN:
        	 printf("\t\t\t\tEntrez Votre CIN : ");
        	scanf(" %s",cin);
        	rechercheCIN(cin);
			if(exe==0){
			printf("\n\t\t\t\tle compte exist\n");
			goto CIN;
			}else{         	
		    strcpy(info[i].CIN,cin);
            printf("\n\t\t\t\tNom : ");
            scanf("%s",info[i].Nom);
            printf("\n\t\t\t\tPrenom : ");
            scanf("%s",info[i].Prenom);
            printf("\n\t\t\t\tMontant : ");
            scanf("%f",&info[i].Montant);
			}
			}//FIN FOR
				nb=nb+n;
		     	Affichage(nb);
     	 goto Menu;
        break;
        
        
        
        case 3://////////////////////////////////////////////////////3////////////////////////////////////////////////////////
         printf("\t\t3-1 Retrait \n\t\t3-2 Depot\n");
         printf("\t\tEntrez operation ");
         scanf("%d",&choix);
         switch(choix){
		 case 1:
		 Retrait:
         	printf("\nEntrez CIN de compte: ");
         	scanf("%s",&cin);
         	rechercheCIN(cin);
         	if(exe==0){
         		montantgrande:
               printf("\nEntrez la montant: ");
         	     scanf("%f",&montant);
         	     if(montant>info[indexx].Montant){
         	     	printf("le montant plus grand!!!!!");
         	     	goto montantgrande;
				  }else{
				  	 info[indexx].Montant-=montant;
				  	 printf("\n\tOperation bien Fait");
				  } 
			 }else{
			 	printf("\nCin non Exist !!");
			 	goto Retrait;
			 }
			 break;
          case 2:
		    Depot:
		 	printf("Entrez CIN de compte: ");
         	scanf("%s",&cin);
         	rechercheCIN(cin);
         	if(exe==0){
               printf("\nEntrez la montant: ");
         	     scanf("%f",&montant);
         	     printf("index:%d",indexx);
         	   	  info[indexx].Montant+=montant;
         	   	   printf("\nOperation bien Fait");
			 }else{
			 	printf("\nCin non Exist !!");
			 	goto Depot;
			 }	
		 }//fin switch case 4
		   goto Menu;
        break;
        
        
        case 4:////////////////////////////////////////////////////4//////////////////////////////////////////////////////////
        	printf("\t\t\t\t4-1 Par Ordre Ascendant\n\t\t\t\t4-2 Par Ordre Descendant\n\t\t\t\t4-3 Par Ordre Ascendant par chiffre\n\t\t\t\t4-4 Par Ordre Descendant par chiffre\n\t\t\t\t4-5 Recherche par CIN\n");
        	printf("\t\t\t\tEntrez votre choix: ");
        	scanf("%d",&choix);
        	switch(choix){
           	 case 1:
           	 	Ascendant();
				Affichage(nb);
				goto Menu;
             break;
             case 2:
            	Descendant();
				Affichage(nb);
				goto Menu;
             break;
             case 3:///////////Afficher les compte plus grand montant////////////
                printf("\t\t\t\tEntrez un chiffre : ");
             	scanf("%f",&montant);
             	Ascendant();
                for(i=0;i<nb+n;i++){
                	for(j=i+1;j<nb+n;j++){
             			if(montant<info[i].Montant){
             				indexx=i;
						 }
					}
		     	}
		     	 for(i=indexx;i<nb;i++){
		       	    printf("\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
		        }
		         goto Menu; 
             break;
             case 4:////////////Descendant par chiffre
	            printf("Entrez un chiffre : ");
             	scanf("%f",&montant);
             	Descendant();
             	for(i=0;i<nb+n;i++){
             			if(montant<info[i].Montant){
             				indexx=i;
						 }
					
		     	}
		     	for(i=0;i<=indexx;i++){
		       	printf("\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
		       }
		       goto Menu;
             break;
             case 5://////////recherche 
              printf("\t\tEntrez CIN de compte: ");
           	  scanf("%s",&cin);
         	  rechercheCIN(cin);
         	  if(exe==0){
         	  	printf("\t\tCIN : %s",info[indexx].CIN);
         	    printf("\tNom : %s",info[indexx].Nom);
         	    printf("\tPrenom : %s",info[indexx].Prenom);
         	    printf("\tMontan : %.2f",info[indexx].Montant);
			   }else{
			   	printf("le compt non exest!!!");
			   }
			   goto Menu;
         	  break;
		   }//fin switch  
        break;//break case 4 swirch2
        case 5:///////////////////////////////////////////////////5/////////////////////////////////////////////////////
           Descendant();
           // Affichage(nb);
            for(i=0;i<3;i++){
            	info[i].Montant+=((info[i].Montant)*0.013);
		   }
           printf("\nOperation bien Fait");
		  goto Menu;
        break;
        case 6:
        	printf("Veux-vous vraiment quitter!!!\n\t1-oui\t2-nom\n->");
        	scanf("%d",&choix);
        	if(choix==1){
        		system("cls") ;
        		exit(0);
			}else goto Menu;
        break;
        break;
        default:  
        		printf("Voullez Entrez les nombre que exist dans le Menu ");
        		goto Menu;
        break;
    }//fin switch
	}