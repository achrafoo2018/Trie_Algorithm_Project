#ifndef DEF_DICO
#define DEF_DICO
#include "arbre.h"
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

void dicoAfficher(TArbre *a, char mot[]);
TArbre *dicoInsererMotRecursive(char mot[], int pos, TArbre *pa);
void dicoInsererMot(char mot[], TArbre *pa);
int dicoNbOcc(char mot[], TArbre *a);
int dicoNbMotsDifferents(TArbre *a); 
int dicoNbMotsTotal(TArbre *a);

#endif