// 5.05.97
// classe implementee
// 6.05.97
// destructeurs


// ce fichier contient les classes liste et iterliste et la classe cellule
// dont elles se servent

// Debugger en 2004 09 25
//Correction d'un bug suite Assert (NULL)

#ifndef IOSTREAM
#define IOSTREAM 
#include<iostream.h>
#endif

#ifndef ASSERT 
#define ASSERT 
#include<assert.h>
#endif

//on explicite la presence des classes
template <class T> 
class IterListe;

template <class T>
class Cellule;

// ============
// CLASSE LISTE
// ============

template <class T>
class Liste{
protected:
	Cellule<T> * _ptrtete;
public:
	Liste();		//constr par defaut
	Liste(const Liste &);	//constr par copie
	virtual ~Liste();	

	virtual void affecter(Liste<T>);	//affecter une liste a une liste vide 	
	virtual void ajoute(T);		//ajoute un element en tete
	virtual void efface();		//efface la liste
	T premier()const;		//retourne val de tete
//	virtual int appartient(T)const;	//teste appartenance
	int vide()const;		//liste vide ?
//	Liste& operator=(const Liste&){	delete this; return new Liste<T>(liste); };
 virtual void suprprem();	//supprime le premier element
//	void affiche();		
	friend class IterListe<T>;	//classe amie
};

//===========================
// DEFINITIONS DE LISTE
//===========================

template <class T>
Liste<T>::Liste(){
	_ptrtete=NULL;		//liste vide
}

template <class T>
Liste<T>::Liste(const Liste<T> & l){
/*	assert(l._ptrtete!=NULL);*/

	Cellule<T> * ptcac;		//pointeur sur cellule a copier
	ptcac=l._ptrtete;		//prend la valeur de ptrtete
	_ptrtete=ptcac->duplique();	//duplique la cellule
	ptcac=_ptrtete->_ptrsuivant;	//pointe sur la suivante


	while(ptcac!=NULL){			// fin de liste ?
		ptcac=ptcac->duplique();	// non ... on duplique	
		ptcac=ptcac->_ptrsuivant;	// cellule suivante
	}		
}

template <class T>
Liste<T>::~Liste(){
	while(_ptrtete!=NULL){
		suprprem();	// on supprime tous les elements 
	}
}

template <class T>
void Liste<T>::affecter(Liste<T> l){
	Cellule<T> * ptcac;		//pointeur sur cellule a copier
	ptcac=l._ptrtete;		//prend la valeur de ptrtete
	_ptrtete=ptcac->duplique();	//duplique la cellule
	ptcac=_ptrtete->_ptrsuivant;	//pointe sur la suivante


	while(ptcac!=NULL){			// fin de liste ?
		ptcac=ptcac->duplique();	// non ... on duplique	
		ptcac=ptcac->_ptrsuivant;	// cellule suivante
	}
}

template<class T>
void Liste<T>::ajoute(T val){
	_ptrtete=new Cellule<T>(val,_ptrtete);	//sans commentaire
}

template <class T>
void Liste<T>::suprprem(){
	Cellule<T> * _tmp;		// on travaille sur une cellule
					// temporaire
	_tmp=_ptrtete->_ptrsuivant;	// nouvelle tete
	delete _ptrtete;		// on efface la cellule
	_ptrtete=_tmp;			// on recupere la nouvelle cellule de
					// tete
}	

template <class T>
T Liste<T>::premier()const{
	return _ptrtete->_val;		//renvoie la valeur correspondante
}

/*
template <class T>
int Liste<T>::appartient(T val)const{
	Cellule<T>* _tmp=_ptrtete;
	while(_tmp!=NULL){		// parcours de la liste
		if(_tmp->_val==val)	// egalite ?
			return 1;	// oui alors on retourne VRAI (1)
		_tmp=_tmp->_ptrsuivant;	// au suivant !	
	}
	return 0;			// n'appartient pas
}
*/

template <class T>
void Liste<T>::efface(){
	while(!vide()){
		suprprem();
	}
}


/*
template <class T>
void Liste<T>::affiche(){
	Cellule<T> * _ptc=_ptrtete;
	while(_ptc!=NULL){
		cout<<_ptc->_val<<" <- ";
		_ptc=_ptc->_ptrsuivant;
	}
	cout<<endl;
}	
*/

template <class T>
int Liste<T>::vide()const{
	return (_ptrtete==NULL);	// vide==_ptrtete==NULL
}



//============================================
//          CLASSE CELLULE
//============================================

template <class T>
class Cellule{
	Cellule(T val,Cellule<T> * _ptc);	//constructeur
	Cellule * duplique();		// duplique une cellule (avec retour)
	T _val;				// donnee : valeur de la cellule
	Cellule * _ptrsuivant;		// donnee : ptr sur cellule suivante
	
	
	//classes amies
	friend class Liste<T>;	
	friend class IterListe<T>;
public:
	Cellule * insere(T);		// insere une cellule (retour)
};	

//======================
//DEFINITIONS DE CELLULE
//======================

template <class T>		
Cellule<T>::Cellule(T val,Cellule<T> * _ptc){
	_ptrsuivant=_ptc;
	_val=val;	
}

	
template <class T>
Cellule<T> * Cellule<T>::duplique(){
	Cellule<T> * ptcel=new Cellule<T>(_val,_ptrsuivant);
	return ptcel;	// retourne la cellule cree (identique)
}			

template <class T>
Cellule<T> * Cellule<T>::insere(T val){
	_ptrsuivant=new Cellule<T>(val,_ptrsuivant);
	return _ptrsuivant;	// retourne nouvelle cellule (liee)
}

// =============================
//   CLASSE ITERLISTE
// =============================

template <class T>
class IterListe{

	Cellule<T>* courant;	// pointeur sur cellule courante
	Cellule<T>* precedent;	// pointeur sur cellule precedente
 Liste<T> _liste;	// la liste

public:
	int count;

	IterListe(Liste<T> &);		// constructeur
	IterListe():courant(NULL),precedent(NULL),count(0){}
	~IterListe(); 
	virtual void init();		// reinitialise la position courante
	void efface();			// efface le liste
	T acces();			// retourne valeur courante
	T acces(int p);	
	void positionne(int p);	 
	virtual void suivant();		// position suivante
	virtual int fin();		// test fin de liste
	virtual void modifie(T);	// modifie valeur courante
	void supprimecourant();		// supprime valeur courante
	void ajoute(T);			// ajoute un element
//	void insereDerriere(T);		// insere un element (derriere)
	void affecter (Liste<T>);
	IterListe<T> & operator =(Liste<T> &);	// affectation d'une liste 
};

// ------------------------
// DEFINITIONS DE ITERLISTE
// ------------------------

template <class T>
IterListe<T>::IterListe(Liste<T>& l):_liste(l){
	courant=_liste._ptrtete;
	precedent=NULL;
}

template <class T>
void IterListe<T>::init(){
	courant=_liste._ptrtete;	// on retourne a la tete
	precedent=NULL;
}

template <class T>
void IterListe<T>::efface(){
	_liste.efface();
	courant=_liste._ptrtete;	// on retourne a la tete
	precedent=NULL;
	count=0;
}

template<class T>
T IterListe<T>::acces(){
	return (courant->_val);
}

template<class T>
T IterListe<T>::acces(int p){
	positionne(p);
	return (acces());
}

template<class T>
void IterListe<T>::positionne(int p){

	int i(0);
	init();

	while(i<p){
		suivant();
		i++;
	}
}

template<class T>
void IterListe<T>::suivant(){
	if (courant!=NULL){		// dernier element ?
   		precedent=courant;	// non ,alors on recupere
   		courant=courant->_ptrsuivant;	// le pointeur sur element
   						// suivant. 
  	}
}


template<class T>
int IterListe<T>::fin(){
	 return (courant==NULL);	
}

template<class T>
void IterListe<T>::modifie(T val){
	courant->_val=val;
}

template<class T>
void IterListe<T>::supprimecourant(){
	if(courant==_liste._ptrtete){
		_liste.suprprem();
	}
	else{
	 if(courant!=NULL)
    {
    // assert(courant);  //Correction 2004
	     Cellule<T>* tmp;
     	 tmp=courant->_ptrsuivant;	
	     delete courant;
    	      if ( precedent )
		    	      precedent->_ptrsuivant=tmp;
     		    	      }    
       	/*(precedent->_ptrsuivant)=(courant->_ptrsuivant);
		delete courant;
		courant=precedent->_ptrsuivant;
*/	
 }

	count--;

}

template<class T>
void IterListe<T>::ajoute(T val){
	 if (courant==_liste._ptrtete){		// cas du premier element
   		_liste.ajoute(val);
   		courant=_liste._ptrtete;
		precedent=NULL;
  	 }
 	 else{					// cas general
		assert(precedent!=NULL);
   		courant=precedent->insere(val);
	}

	count++;

}


template <class T>
IterListe<T> & IterListe<T>::operator =(Liste<T> & l){
	_liste.affecter(l);
	courant=_liste._ptrtete;
	precedent=NULL;
	return *this;
}


template <class T>
void IterListe<T>::affecter(Liste<T> l){
	_liste.affecter(l);
	courant=_liste._ptrtete;
	precedent=NULL;
}

template <class T>
IterListe<T>::~IterListe(){
	_liste.efface();
	courant=_liste._ptrtete;	
	precedent=NULL;
	count=0;
}

