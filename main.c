#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int choix,i,j,nb=3,n=0,exe,indexx,trimontont;
char cin[6];
float montant,t ;
typedef struct{
  char CIN[6];
  char Nom[20];
  char Prenom[20];
  float Montant;
}information;
information T ;
information info[]={{"H456","Ahmed","ALAMI",10000},{"H358","omar","hakimi",12000},{"H789","meriam","ben",13000}};
void Affichage(int nb){//fonction Affichage
    	for(i=0;i<nb;i++){
			printf("\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
	}
}
int rechercheCIN(){ //fonction test CIN
	for(i=0;i<nb+n;i++){	
                if(strcmp(info[i].CIN,cin)==0){
        				 exe=0;
        				 indexx=i;
        				 break;
					}else{
						exe=1;
			}
			indexx=i;
	}
	return exe;		
}
void Ascendant(){
	for(i=0;i<nb+n-1;i++){
           	 		for(j=i+1;j<nb+n;j++){
           	 			if(info[i].Montant>info[j].Montant){
           	 			   T= info[i];
           	 			   info[i]=info[j];
           	 			   info[j]=T;
						}//fin if
					 } 	//fin for j
					}//fin for i
}
void Descendant(){
	for(i=0;i<nb+n-1;i++){
           	 		for(j=i+1;j<nb+n;j++){
           	 			if(info[i].Montant<info[j].Montant){
           	 			   T = info[i];
           	 			   info[i]=info[j];
           	 			   info[j]=T;
						}//fin if
					 } 	//fin for j
					}//fin for i
}

int main() {

    Menu:
    printf("\n*	*	*	*	*	*	*	**Menu**	*	*	*	*	*	*\n\n");
    printf("\t\t\t\t1-Introduire un compte bancaire\n\t\t\t\t2-Introduire plusieurs comptes bancaires\n\t\t\t\t3-Operations\n\t\t\t\t4-Affichage\n\t\t\t\t5-Fidelisation\n\t\t\t\t6-Quitter l'application\n");
    printf("\n*	*	*	*	**************************************	*	*	*	*	*	*\n");
	printf("Entrez Votre Choix : ");
    scanf("%d",&choix);
    switch(choix){
        case 1://///////////////////////////////////////////////1///////////////////////////////////////////////////
        	printf("Entrez Votre CIN : ");
        	scanf(" %s",cin);
        	for(i=0;i<nb+n;i++){	
                if(strcmp(info[i].CIN,cin)==0){
        				 exe=0;
        				 break;
					}else{
						exe=1;
			}	
			}
			if(exe==0){
			printf("\nle compte exist\n");
			Affichage(nb);
			//system("cls") ;
			//goto Menu;
			
			}else{
		    //i=nb+1;
  	        printf("\nle compte non exist\n");         	
		    strcpy(info[nb].CIN,cin);
            printf("\nNom : ");
            scanf("%s",info[i].Nom);
            printf("\nPrenom : ");
            scanf("%s",info[i].Prenom);
            printf("\nMontant : ");
            scanf("%f",&info[i].Montant);
			nb+=1;	
            Affichage(nb);
			}
	  	 goto Menu;
        break;
        case 2://////////////////////////////////////////////////2////////////////////////////////////////////////
        	printf("Donnez le nombre des client qui vous Ajoute ");
        	scanf("%d",&n);			
        for(i=nb;i<n+nb;i++){
          printf("**Entrez les information compt %d",i-1);
          printf("CIN : ");
          scanf("%s",&cin);
          if((strcmp(info[i].CIN,cin))==0){
          	printf("Les exist ");
         	goto Menu;
          	break;
		  }else{
		  	strcpy(info[i].CIN,cin);
		    printf("Nom : ");
            scanf("%s",&info[i].Nom);
            printf("Prenom : ");
            scanf("%s",&info[i].Prenom);
            printf("Montant : ");
            scanf("%f",&info[i].Montant);
		  } 
     	}
		 	nb+=n;
     //	printf("nb=%d",nb);
     //	Affichage(nb);
     	 goto Menu;
        break;
        case 3://////////////////////////////////////////////////////3////////////////////////////////////////////////////////
         printf("\t\t3-1 Retrait \n\t\t3-2 Depot\n");
         printf("Entrez operation ");
         scanf("%d",&choix);
         if(choix==1){
         	printf("Entrez CIN de compte: ");
         	scanf("%s",&cin);
         	rechercheCIN();
         	if(exe==0){
               printf("\nEntrez la montant: ");
         	     scanf("%f",&montant);
         	     if(montant>info[i].Montant){
         	     	printf("le montant plus grand!!!!!");
				  }else{
				  	 info[indexx].Montant-=montant;
				  } 
			 }else{
			 	printf("\nCin non Exist !!");
			 }
          
		 }else{
		 	printf("Entrez CIN de compte: ");
         	scanf("%s",&cin);
         	rechercheCIN();
         	if(exe==0){
               printf("\nEntrez la montant: ");
         	     scanf("%f",&montant);
         	     printf("index:%d",indexx);
         	   	  info[indexx].Montant+=montant;
			 }else{
			 	printf("\nCin non Exist !!");
			 }	
		 }
	  	 goto Menu;
        break;
        case 4:////////////////////////////////////////////////////4//////////////////////////////////////////////////////////
        	printf("\t\t4-1 Par Ordre Ascendant\n\t\t4-2 Par Ordre Descendant\n\t\t4-3 Par Ordre Ascendant par chiffre\n\t\t4-4 Par Ordre Descendant par chiffre\n\t\t4-5 Recherche par CIN\n");
        	printf("Entrez votre choix: ");
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
                printf("Entrez un chiffre : ");
             	scanf("%f",&montant);
             	Ascendant();
                for(i=0;i<nb;i++){
             			if(montant<info[i].Montant){
             				indexx=i;
						 }
		     	}
		     	 for(i=indexx-1;i<nb;i++){
		       	    printf("\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
		        }
		         goto Menu; 
             break;
             case 4:////////////Descendant par chiffre
	            printf("Entrez un chiffre : ");
             	scanf("%f",&montant);
             	Descendant();
             	//Affichage(nb+n);
             	for(i=0;i<nb;i++){
             			if(montant>info[i].Montant){
             				indexx=i;
						 }
		     	}
		     //	Affichage(nb);
		     	printf("\nindex= %d",indexx);
		     	for(i=0;i<indexx;i++){
		       	printf("\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
		       }
		       goto Menu;
             break;
             case 5://////////recherche 
              printf("Entrez CIN de compte: ");
           	  scanf("%s",&cin);
         	  rechercheCIN();
         	  if(exe==0){
         	  	printf("CIN : %s",info[indexx].CIN);
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
	//	  Affichage(3);
		  goto Menu;
        break;
        case 6:
        	Affichage(nb);
		  goto Menu;
        break;
        break;
        default:
        //	while(choix !=1 && choix!=2 ){// && choix!=3 && choix!=4 && choix!=5 && choix!=6 &&choix!=7|| 
        		printf("Voullez Entrez les nombre que exist dans le Menu ");
        		goto Menu;
		//	}
        break;
    }//fin switch
//     	for(i=0;i<nb;i++){
//			printf("\nCIN %s\nNom %s\nPrenom %s\nMontant %.2f",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
//	}
	}