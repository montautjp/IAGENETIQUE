# IAGENETIQUE
Intelligence Artificiel Génétique


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

