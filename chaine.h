/*
CHAINE.H AVEC ALLOCATION MEMOIRe
CREER LE 18 JUILLET 2004
CREation de la fonction modifie caractere LE 19 Juillet 2004
Et Retourne longueur caractere

*/
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream.h>
#endif

#ifndef STRING
#define STRING
#include <string.h> 		// utilise pour fonctions strcpy et strlen
#endif

class Chaine {
     private:
		int lg;      // nb caracteres de chaine
			     // non compris marqueur de fin
		char *ch;
     public:                 // initialise une chaine vide
	     Chaine(){
		     lg=0;
		     ch=NULL;
		     };

	     Chaine(const Chaine &c) // init une chaine a partir d'une chaine
		{
		//cout<<"appel du deuxieme constructeur :"<<endl;
		lg=strlen(c.ch);   // recupere la longueur de la chaine c.ch
		ch=new char[lg];   // allocation de place pour chaine c.ch
		strcpy(ch,c.ch);   // copie de c.ch dans ch
		};

		Chaine(const char *s)// init chaine a partir chaine caracteres
		  {
		  //cout<<"appel du premier constructeur:"<<endl;
		  lg=strlen(s);
		  ch=new char [lg+1];
		  strcpy(ch,s);
		  };
		  
  		  Chaine(const int _longeur)
  		  {
  		  lg=_longeur;
  		  ch=new char[lg];
  		  };
		  
		  
		  char affiche(int _position)
		  {
		  return ch[_position];
		  
		  
		  };
        int longueur () //retourne la longueur de la chaine 
        {
        //lg=strlen(ch);
        return lg;
        };
        
        void modifie (char _val,int _pos) // Modifie le carac à la position
        {
        if (_pos>lg-1)
        {
                 cerr<<"ERREUR POSITION"<<endl;
                 exit(-1);
        }
        else
        {
        ch[_pos]=_val;
        }
        };    
        
		Chaine & operator=(const Chaine & s)
		  {
		  //cout<<"appel du troisieme constructeur:"<<endl;
		  if (&s != this)      //si chaine s.ch est <> chaine s.ch
		  {                    // on ne fait rien pour y=y
		  lg=strlen(s.ch);     // recupere longueur chaine s.ch
		  delete ch;           // suppression chaine s.ch
		  ch=new char[s.lg+1]; // reallocation de place
		  strcpy(ch,s.ch);
		  };
		  return *this;        // retourne chaine z.ch
		  }

		  ~Chaine()            // detruit allocation du pointeur *ch
		  {
		  //cout<<"appel du destructeur :"<<endl;
		  delete[]ch;};

		  friend ostream & operator<<(ostream & sortie,
			const Chaine & une_chaine)
		  {return sortie<<une_chaine.ch;}};



