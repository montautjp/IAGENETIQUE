#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>


/* Module de Itératif testant par brute de force 
Creer le 6 février 2005
Entrer : table1
sortie Neant 
*/

int *Ville;   		//contient les villes traversees
int *Chemin;		//indique le chemin le plus court
int *Traversee;		//indique si la ville a ete ou non traversee
int **Distance;		//indique les distances separant chaque villes

int N;			//Nombre de villes
int CheminMin=32000;
FILE * ptr_fichier;

void ChercheMeilleurChemin(int);

/* recupere un mot du fichier ptr_fichier*/
void new_fgets2(char * chaine,FILE * ptr_fichier){

	int i(0);
	char c;
	
	do{
		c=(char) fgetc(ptr_fichier);
		chaine[i++]=c;
	}while(c!=' ' && c!='\n');
		
	chaine[i]='\0';
}






void Affiche(int n)
{ 
   int i,j ;
   cout<< "Table des distances:"<<endl;
   cout<<endl;
   cout<<"   ";
   for(i=0;i<n;i++)
     cout<<i<<" ";
   cout<<endl;
   for(i=0;i<n;i++){
      cout<<endl;
      cout<<i<<" ";
      for(j=0;j<n;j++){
	 cout<< " " <<Distance[i][j];
      }
   }
   cout<<endl;
}
 

void Saisie(void)
{
  	int N1(10);		// caracteres recuperes
	int i,j,type,e;
	char tmp[10];
   
    
   
     
      
// Ouverture du fichier de la table


	if(ptr_fichier==NULL){
		cout<<"Impossible d'ouvrir le fichier "<<endl;
		exit(0);
	}
	fgets(tmp,N1,ptr_fichier);
	type=atoi(tmp);
	cout<<"Type :"<<type<<endl;
	
	 fgets(tmp,N1,ptr_fichier);	// recuperation du nombre de villes
	 N=atoi(tmp);
	  cout<<"Nombre de ville :"<<N<<endl;
   

   //Allocation dynamique de la memoire (tableaux)
   Ville=new int[N+1];
   Chemin=new int[N+1];
   Traversee=new int[N];
   Distance=new int*[N];
   for(i=0;i<N;i++)
   {
      Distance[i]=new int[N];
      //initialisation des tableaux
      Traversee[i]=0;
   }




 for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			new_fgets2(tmp,ptr_fichier);
			Distance[i][j]=atoi(tmp);
		}
	  }		

	  fclose(ptr_fichier);


 /*  //Saisie des distances separant les villes
   for(i=0;i<N;i++)
     for(j=0;j<N;j++)
       if (i!=j)
       {
	  cout << "Entrez la distance separant la ville " << i << " de la ville " << j << " (en km, valeur entiere) :" << endl;
	  cin >> Distance[i][j];
       }
       else
          Distance[i][j]=0;
          
          
          */
}

void ChercheMeilleurChemin(int M)
{
   int i;
   int Somme=0;
   if (M==0)
   {
      //Calcul de la distance totale et affichage du chemin trouve
      for(i=0;i<N;i++)
      {
	 Somme+=Distance[Ville[i]][Ville[i+1]];
      //   cout << Ville[i] << " -> ";
      }
    //  cout << "0 , soit une distance de " << Somme << " km" << endl;
      //Est-ce le chemin le plus court trouve jusqu'a present
      if (Somme<CheminMin)
      {
	 CheminMin=Somme;
	 for(i=0;i<N+1;i++)
            Chemin[i]=Ville[i];
      }
   }
   else
   {
      //Test l'ensemble des chemins possibles a partir de celui deja parcouru
      //On ne passe pas deux fois par la meme ville
      //On par a i=1 du fait que la ville 0 ne peut pas etre retraversee
      for(i=1;i<N;i++)
      {
	 if (Traversee[i]==0)
	 {
	    Traversee[i]=1;
	    Ville[N-M]=i;
	    ChercheMeilleurChemin(M-1);
            Traversee[i]=0;
         }
      }
   }
}

void Calcul_Brute_Force(char * nom_table)
{
   
   // Ouverture du fichier de la table
    ptr_fichier=fopen(nom_table,"rt");

	if(ptr_fichier==NULL){
		cout<<"Impossible d'ouvrir le fichier "<<nom_table<<"."<<endl;
		exit(0);
	}

   
   int i;
   //Saisie des variables du probleme
   Saisie();
   Affiche(N);
   Ville[0]=0;  	//La ville de depart est la ville 0
   Ville[N]=0;          //La ville d'arrivee est la ville 0
   Traversee[0]=1;      //La ville 0 est initialement traversee
   cout << endl << "Calcul en cours ... (CRTL C pour annuler la recherche)" << endl;
   ChercheMeilleurChemin(N-1);
   //Affichage du resultat
   cout << endl << "Le chemin le plus court est : " << endl;
   for(i=0;i<N;i++)
      cout << Chemin[i] << " -> ";
   cout << " 0" << endl;
   cout << "La distance pour ce chemin vaut : " << CheminMin << " km"<<endl;
}




