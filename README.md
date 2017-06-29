# IAGENETIQUE
Intelligence Artificiel Génétique

->   En cours de rajout pour les librairies et fichiers manquant ->

De nombreux parametres vous ont alors demandes.
Je les explique ci-dessous:


- L'identificateur de donnnees

	Vous devez entrer ici l'identificateur de vos donnees.
Si ce message apparait :

	Le nombre de villes ne correspond pas a la table.
	Il vous est conseille de recompiler avec la bonne valeur.

Alors vous devez recommencer l'edition du source et changer la variable
x pour qu'elle corresponde a vos fichiers.

Sinon le programme affiche la table chargee et les solutions. Si
l'affichage ne correspond pas a ce que vous pensiez verifiez la
syntaxe de vos deux fichiers table et solutions, il se peut qu'un
espace en trop ait ete oublie.


- N_iteration

	Indique le nombre de generations que le programme doit 
effectuer avant de se terminer.


- modulo

	ceci permet de limiter l'affichage des resultats afin que le
	programme affiche seulement toutes les 'modulo' generations
	les statistiques sur la generation.


- pm

	Ce parametre indique la probabilite de mutation. C'est le
pourcentage de chromosomes mutes dans une generation.
8 indique par exemple que 8% des chromosomes seront mutes.

- px

	ce parametre existe seulement dans la version 10a du programme.
Si vous utilisez la verision 10, vous n'avez pas a vous soucier de ce
parametre.

Il indique la probabilite de croisement. c'est le pourcentage de
chromosomes qui vont etre croises. Par exemple 0.4 indique que 40% des
chromosomes seront croises.

- coef_min
- coef_max

ces parametres indique les coefficients de  ponderation minimal et
maximal utilise lors de la selection. 
Une valeur nulle pour coef_min fait que les chromosomes les plus faibles
seront elimines. Nous vous conseillons de toujours mettre cette valeur
a 0 afin d'obtenir de bons resultats.

- coef_mutation

Ce parametre est utilise lorsque la population de la generation devient
unique. Il indique le nombre de chromosomes qui va etre genere a
partir de cet individu unique.
Il doit etre superieur ou egal a 2 car il faut regenerer au moins deux
chromosomes pour permettre de nouveau un croisement.




- TOP N, N=

ce parametre indique le nombre de solution qui vont etre
stockees dans le TOP_N. Le N contient les meilleurs chromosomes
rencontres au cours des generations.
	


----------------------------------------------------------------------------------------
3eme partie: les resultats du programme

Apres avoir entre tous les parametres le programme affiche la
generation 0 constituee des solutions initiales :

Exemple:

Generation 0
(0) - 0 3 1 2 0  [18 ] 
(1) - 0 2 3 1 0  [10 ] 
(2) - 0 1 2 3 0  [14 ] 
N=3


Le nombre entre parentheses indique le numero de la solution. Ensuite
nous avons la solution elle meme et entre crochets le cout de la
solution
N indique le nombre de chromosomes de la generation.


Ensuite le programme affiche les informations relatives a la generation
courante. Le premier nombre est le numero de la generation, le second
entre crochets indique le cout de la meilleure solution dans la
generation, le troisieme nombre indique le nombre de chromosomes
de la generation.

Exemple:

1 [10] 3
2 [10] 2
3 [10] 5
4 [10] 4
5 [10] 3
6 [10] 5
7 [10] 3
8 [10] 5


Lorsque le programme se termine, la generation finale et le topfive
sont affiches.
L'affichage de generation est explicite plus haut.
L'affichage du topfive est quasiment le meme que l'affichage d'une
generation.

Exemple:

 ** Population apres 8 iterations **
Generation 8
(0) - 0 3 2 1 0  [14 ] 
(1) - 0 1 2 3 0  [14 ] 
(2) - 0 2 3 1 0  [10 ] 
(3) - 0 2 3 1 0  [10 ] 
(4) - 0 1 3 2 0  [10 ] 


 *** TOP  ***
0 2 3 1 0  [10 ] 
0 1 3 2 0  [10 ] 
0 1 3 2 0  [10 ] 
0 2 3 1 0  [10 ] 
0 2 3 1 0  [10 ] 


Historique :


05- 1996
version 0.8.9.0:
-Initialisation de l'algorithme de base
-generation aleatoire d"une population initiale de n_solutions
-classe generation : partie declarative
-definition des procedures
-classe chromosome : partie declarative
-classe population : partie declarative
-classe implementee et destructeurs
bugs :
problème mémoire


version 0.9.0.1:
-selection
-croisement
-definition du constructeur
-fonction affiche
-fonction afficher()
bugs :
-problème mémoire


version 0.9.0.2:
-test avec liste implementee
-Test Croiser avec xxX 
-Croisement probabiliste
-les genes c'est des entiers ... voila !
-On passe sur gamay 
-Implementation de xxx
-Correction des pbs de memoire
-Mutation
-x devient constante meilleur optimisation mémoire !


version 0.9.0.4:
-version avec des coordonnees 
-limite de population
-le programme traite 2 types de fichiers: tableau de distances et table de coordonnees.

version 0.9.0.5:
-reconnaissance automatique du type de fichier 
-TOP 5 -> La Puissance !!!!!
bug : 
erreur mémoire volatile ..............................................................


version 1.0.0.0:
-Correction du Bug memoire volatile avec optimisation avec cyclique des adresses mémoires .
-creation d'un Timer 
-Amélioration en mémoire de l'affichage .


version 1.0.1.0:

-Pour 128 ,  256 ,  512 et 1024 villes 
-demande pourla version 1024 villes --> 10 Mo dispo en mémoire vive
 

version 1.0.2.0:
-pour 5000 et 10000 villes
-DEMANDE POUR 5000 VILLES -- > 150 mo de dispo en mémoire vive 
-Pour la version 10000 Villes il faut au moins 700 Mo de dispo en mémoire vive 

version 1.0.2.1: 

-+ pour Evolution de calcul 
-pour 128 villes 

version 1.0.2.2: 
-Pour 1024 villes 
-demande +/- 15 Mo vive
-creation d'un fichier result.log (vierge pour l'instant )
bug connus :
(0x00001) pas de verification de la saisie des chiffres pm , .

version 1.1.1.1 :
Creation des logs mais suppression dans l'affichage des résultats qui sont dans le log ...
Correction d'un bug mineur Affichage (non génant ) avec les float
Optimisation de certaines variables à cause de + 1024 villes 


Version 1.1.1.2:
Modification des couts 
Modifications d'une classe Principal
En cours de certification


version  1.1.1.3:
Certification pour la version 1.2.0.0
creation d'un log pop.log permettant de verifier les tailles populations !
Creation d'un fichier log temps pour Debug 


version 1.1.1.4:
Creation d'un module Iteratif (Pour comparaison )
Creation Fermeture des fichiers
-Rajouter module Iteratif
Creation d'un log Allocation 
Creation de la version à X villes mais :Mais probleme avec dessallocation mémoire 
d'ou abandont ponctuelle du probleme

-bug :(0x00002) Bug Allocation mémoire si on alloue dynamiquement .



version 1.1.1.5:
Creation de la version multi-villes avec villes de 2 à 1024 villes 
Attention nécessite + de mémoire vive car j'ai du faire une astuce prog en C++ pour pouvoir y arriver .
Pour parametre 1000 pour I et 5000 pour POP demande en moyenne 130 Mo puis +/- tout ceci avec 128 villes 
Modification d'une constante permettant d'avoir au max 1024 villes.
Commencement d'optimisation combinatoire mais demande un peu + de mémoire vive (gain 1%).
Module Brute de Force Inclus au demarrage


-bug :(0x00003) bug affichage pop_debug.log


version 1.1.1.6:
-Certification du programme pour préversion 1.2.0.0
-Analyse du programme .
-Correction bug 0x00003
-Creation valeur MAX des variables 
-Amélioration mémoire affichage (Module Francais )
-Modification de la saisie des probas .



version 1.2.0.0
-Version Certifier pour résultats 



TOTAL BUGS 
bug connues :
(0x00001) pas de verification de la saisie des chiffres pm
(0x00002) Bug Allocation mémoire si on alloue dynamiquement (dispo que sur la version 1.1.1.4).
(0x00003) bug affichage pop_debug.log (Corriger à partir de la version 1.1.1.6)


Astuces  :
(1x0001) Pour des calculs rapident , augmentez l'iteration plutot la population

