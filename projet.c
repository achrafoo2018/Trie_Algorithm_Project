/* -------------------------------------------------------*/
/* Eval TP 1 ING 2021 (ISI) */
/* fichier "projet.c" */
/* -------------------------------------------------------*/
#include <stdio.h>
#include "dico.h"
#include "arbre.h"
#include <string.h>

/* -------------------------------------------------------*/
int main(int argc, char **argv){
    TArbre *dico;
    char buffer[100];
    dico = arbreConsVide();
    strcpy(buffer, "gallon");
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "munier");
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "abenia");
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "munier");
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "mumu");
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "alpha");
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "alphabet");
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "albenia");
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    dicoInsererMot(buffer,0, &dico);
    strcpy(buffer, "aa");
    dicoInsererMot(buffer,0, &dico);
    dicoAfficher(dico, ""); 

    // printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
    // printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
    // printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
    // printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
    // printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
    // printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa",dico)); 
    printf("\n"); 
    /* -------------------------------------------------------*/
}