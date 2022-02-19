/* -------------------------------------------------------*/
/* Eval TP 1 ING 2021 (ISI) */
/* fichier "projet.c" */
/* -------------------------------------------------------*/
#include <stdio.h>
#include "dico.h"
#include "arbre.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* -------------------------------------------------------*/
int main(int argc, char **argv){
    srand(time(NULL));  
    TArbre *dico;
    dico = arbreConsVide();
    // printf("\"%s\" \t -> %d\n", "albenia", dicoNbOcc("albenia", 0, dico));
    // printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu", 0, dico));
    // printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier", 0, dico));
    // printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro", 0, dico));
    // printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa", 0, dico)); 
    char *mot = (char * )malloc(sizeof(char) * 100);
    for(int i=0; i < 100; ++i){
        piocherMot(&mot);
        dicoInsererMot(mot, 0, &dico);
    }
    dicoAfficher(dico);
    printf("\n"); 
    /* -------------------------------------------------------*/
}