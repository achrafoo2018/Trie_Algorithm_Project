#include<stdio.h>
#include <stdlib.h>
#include "arbre.h"
// ***********arbre.c*******

TArbre* arbreConsVide(){
    TArbre* arbre=NULL;
    return arbre; 
}

int arbreEstVide(TArbre* a){
    if(a==NULL)
        return 1;
    else
        return 0;
}

TArbre* arbreCons(char c, int n, TArbre* fg, TArbre* fd){
    TArbre* abr = arbreConsVide();
    TArbre* node=(struct TArbre*)malloc(sizeof(struct TArbre));
    node->lettre=c;
    node->nbOcc=n;
    node->FG=fg;
    node->FD=fd;
    abr=node;
    return abr;
}

char arbreRacineLettre(TArbre* a){
    return a->lettre;
}

int arbreRacineNbOcc(TArbre* a){
    return a->nbOcc;
}


TArbre* arbreFilsGauche(TArbre* a){
    return a->FG;
}
TArbre* arbreFilsDroit(TArbre* a){
    return a->FD;
}

void arbreSuppr(TArbre* a){
    if(a!=NULL){
        arbreSuppr(arbreFilsGauche(a));
        arbreSuppr(arbreFilsDroit(a));
        free(a);
    }
}