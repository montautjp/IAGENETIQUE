/* 
Fonction TEMPS qui permet de calculer le temps de chaque appel
DATE DE CREATION 14 JUILLET 2004
ENTRER SORTIE
Pour l'appeller il faut faire :
	Timer t;	//l'objet t a sa destruction donnera la dur≈e d'ex≈cution de compute()
*/

class Timer{
	clock_t start;
	
	public:
		Timer(){start=clock();}
		~Timer(){
			clock_t fin=(clock()-start)/CLK_TCK;
			clock_t cpu=(clock()-start);
			/* Modifier le 6 fevrier 2005 */
   if (IA_DEBUG==1){
            FILE* fichier_temps;
            fichier_temps=fopen("temps.log","w");
            assert(fichier_temps!=NULL);  
            fprintf(fichier_temps,"%s","Calculez en : "); 
            fprintf(fichier_temps,"%d ",fin); 
                   }    
         cout<<"Temps cpu :"<<cpu<<endl;
			cout<<"Calculez en "<<fin<<"seconde(s)"<<endl;
}
};
