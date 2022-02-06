#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"


void dicoAfficher(TArbre *a, char mot[]){
    if(arbreEstVide(a))
        return;
    if(a->lettre == '\0'){
        printf("%s_%d         ", mot, a->nbOcc);
        dicoAfficher(a->FD, mot);
        return;
    }
    char *tmp = strdup(mot);
    strncat(tmp, &(a->lettre), 1);
    dicoAfficher(a->FG, tmp);
    dicoAfficher(a->FD, mot);
};


void dicoInsererMot(char mot[], int pos, TArbre **tree){
    if(pos == strlen(mot)){
        if(!arbreEstVide(*tree) && (*tree)->lettre == '\0'){
            (*tree)->nbOcc++;
            return;
        }
        TArbre *newNode = arbreCons('\0', 1, NULL, NULL);
        newNode->FD = *tree;
        *tree = newNode;
        return;
    }
    if(arbreEstVide(*tree)){
        TArbre *newNode = arbreCons(mot[pos], 0, NULL, NULL);
        *tree = newNode;
        dicoInsererMot(mot, pos+1, &((*tree)->FG));
        return;
    }
    if(mot[pos] == (*tree)->lettre){
        dicoInsererMot(mot, pos+1, &((*tree)->FG));
        return;
    }else if(mot[pos] > (*tree)->lettre){
        dicoInsererMot(mot, pos, &((*tree)->FD));
        return;
    }else{
        TArbre *newNode = arbreCons(mot[pos], 0, NULL, NULL);
        newNode->FD = *tree;
        *tree = newNode;
        dicoInsererMot(mot, pos+1, &(newNode->FG));
        return;
    }
};


int dicoNbOcc(char mot[], TArbre *a){
    return 0;
};


int dicoNbMotsDifferents(TArbre *a){
    return 0;
}; 


int dicoNbMotsTotal(TArbre *a){
    return 0;
};


int piocherMot(char *motPioche){
    FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule

    // On vérifie si on a réussi à ouvrir le dictionnaire
    if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a échoué
        // À la lecture du return, la fonction s'arrête immédiatement.
    }

    // On compte le nombre de mots dans le fichier (il suffit de compter les
    // entrées \n
    do{
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard

    // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
    rewind(dico);
    while (numMotChoisi > 0){
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    /* Le curseur du fichier est positionné au bon endroit.
    On n'a plus qu'à faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);

    // On vire le \n à la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1; // Tout s'est bien passé, on retourne 1
}

int nombreAleatoire(int nombreMax){
    srand(time(NULL));
    return (rand() % nombreMax);
}