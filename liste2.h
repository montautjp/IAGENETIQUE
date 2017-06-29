template <class T> 
class IterListe;

template <class T>
class Cellule;

template <class T>
class Liste;

template <class T>
class Cellule
{
	T		_valeur		;
	Cellule*	_ptrSuivant	;

	Cellule		(T,Cellule *)	;
	Cellule *	dupliquer()	;
	
	friend	class	Liste<T>	;
	friend	class	IterListe<T>	;

public:

	Cellule*	inserer(T)	;
};


template <class T>
Cellule<T>::Cellule(T val,Cellule *c)
{
	_valeur 	= val	;
	_ptrSuivant 	= c	;
}

template <class T>
Cellule<T> * Cellule<T>::dupliquer()
{
	return new Cellule<T>(_valeur,_ptrSuivant);
}

template <class T>
Cellule<T> * Cellule<T>::inserer(T val)
{
	_ptrSuivant=new Cellule<T>(_valeur,_ptrSuivant);
	return _ptrSuivant;
}




template <class T>
class Liste
{
	Cellule<T>*	_ptrTete	;

	public:

	Liste();
	Liste(const Liste &);
	virtual ~Liste();

	virtual void ajouter(T);
	virtual void efface();
	T	premier() const;
	virtual Bool appartient(T) const;
	Bool	vide() const;
	virtual void suprprem();
	Liste& operator=(const Liste&);
	friend  class IterListe<T>;
};

template <class T>
Liste<T>::Liste()
{
	_ptrTete = NULL ;
}

template <class T>
Liste<T>::Liste(const Liste &l)
{
	Cellule<T> *l1 = l._ptrTete 		;
	
	_ptrTete = l1->dupliquer()		;
	Cellule<T> *l2=_ptrTete			;
	l1->dupliquer()				; 
	l1=l1->_ptrSuivant			;

	while ( l1 )
	{
		l2->_ptrSuivant=l1->dupliquer();
		l2 = l2->_ptrSuivant		;	
		l1 = l1->_ptrSuivant		;
	}
}

template <class T>
Liste<T>::~Liste()
{
	Cellule<T>* tmp=_ptrTete;

	while ( tmp )
	{
		tmp=_ptrTete->_ptrSuivant;
		delete _ptrTete;
		_ptrTete=tmp;
	}
}

template <class T>
void Liste<T>::ajouter(T val)
{
	Cellule<T> *tmp = new Cellule<T>(val,_ptrTete)	;
	assert(tmp)					;
	_ptrTete = tmp					;
}

template <class T>
void Liste<T>::efface()
{
	Cellule<T>	*tmp;	
	
	while ( tmp )
	{
		tmp=_ptrTete->_ptrSuivant		;
		delete _ptrTete				;
		_ptrTete = tmp				;
	}
}

template <class T>
T Liste<T>::premier() const
{
	assert(_ptrTete);
	return _ptrTete->_valeur;
}

template <class T>
Bool Liste<T>::appartient(T val) const
{
	assert(_ptrTete)				;
	
	Cellule<T>*	tmp = _ptrTete			;
	Bool		res = FALSE			;

	while ( tmp && ! res )
	{
		if ( tmp->_valeur == val ) res=TRUE 	;
		else
			tmp = tmp->_ptrSuivant		;
	}

	return res ;
}

template <class T>
Bool Liste<T>::vide() const
{
	return _ptrTete == NULL ;
}

template <class T>
void Liste<T>::suprprem()
{
	assert(_ptrTete)			;
	Cellule<T> *tmp=_ptrTete->_ptrSuivant	;
	delete _ptrTete				;
	_ptrTete = tmp				;
}
/*
template <class T>
Liste<T>* Liste<T>:operator=(const Liste<T> liste)
{
	delete this;
	return new Liste<T>(liste);
}
*/













template <class T>
class Iterateur
{
	public:
	virtual void	init()=0	;
	virtual T	acces()=0	;
	virtual void	suivant()=0	;
	virtual Bool	fin()=0		;
	virtual void	modifier(T)=0	;
};












template <class T>
class IterListe:public Iterateur<T>
{
public:
    int count;
    IterListe(Liste<T> &)		;
    IterListe():courant(NULL),precedent(NULL),count(0){}
    virtual void init()		;
	virtual T acces()		;
	virtual void suivant()		;
	virtual Bool fin()		;
	virtual void modifier(T)	;
	void	supprimecourant()	;
	void	insereDevant(T)		;
	void	insereDerriere(T)	;
private:
	Cellule<T>*	courant	;
	Cellule<T>*	precedent	;
	Liste<T>&	_liste		;
};


template <class T>
IterListe<T>::IterListe(Liste<T> &liste):_liste(liste)
{
}

template <class T>
void IterListe<T>::init()
{
	courant 	= _liste._ptrTete	;
	precedent	= NULL			;
}

template <class T>
T IterListe<T>::acces()
{
	assert(courant)			;
	return courant->_valeur		;
}

template <class T>
void IterListe<T>::suivant()
{
	precedent=courant;
	courant=courant->_ptrSuivant;
}

template <class T>
Bool IterListe<T>::fin()
{
	return _ptrCourant==NULL;
}

template <class T>
void IterListe<T>::modifier(T val)
{
	assert(_ptrCourant);
	_ptrCourant->_valeur=val;
}

template <class T>
void IterListe<T>::supprimecourant()
{
	assert(_ptrCourant);
	Cellule<T>* tmp=_ptrCourant->_ptrSuivant;	
	delete _ptrCourant;
	if ( _ptrPrecedent )
		_ptrPrecedent->_ptrSuivant=tmp;
}

template <class T>
void IterListe<T>::insereDevant(T val)
{
	assert(_ptrCourant);
	_ptrCourant->inserer(val);
	_ptrPrecedent=_ptrCourant;
	_ptrCourant=_ptrPrecedent->_ptrSuivant;
}

template <class T>
void IterListe<T>::insereDerriere(T val)
{
	assert(_ptrCourant);
	Cellule<T> *cel=new Cellule<T>(val,_ptrCourant->_ptrSuivant);	
	assert(cel);
	_ptrCourant->_ptrSuivant=cel;
}

