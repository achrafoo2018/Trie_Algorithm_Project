#ifndef DEF_DICO
#define DEF_DICO
#include "arbre.h"
int piocherMot(char **motPioche);
int nombreAleatoire(int nombreMax);

void dicoAfficher(TArbre *a);
void dicoAfficherRecursive(TArbre *a, char *mot);
void dicoInsererMot(char *mot, int pos, TArbre **pa);
int dicoNbOcc(char mot[], int pos, TArbre *a);
int dicoNbMotsDifferents(TArbre *a); 
int dicoNbMotsTotal(TArbre *a);

#endif