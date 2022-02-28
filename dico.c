#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico.h"


void dicoAfficher(TArbre *a){
    printf("\n******************** Dictionnaire *********************\n\n");
    puts(" +------------------------------+--------------------+");
    puts(" |             \033[1mMots\033[0m             | \033[1mNombre d'occurance\033[0m |");
    puts(" +------------------------------+--------------------+");
    dicoAfficherRecursive(a, "");
    printf(" | \033[1m%-28s\033[0m | \033[1m%-18d\033[0m |\n", "Mots Total", dicoNbMotsTotal(a));
    puts(" +------------------------------+--------------------+");
    printf(" | \033[1m%-28s\033[0m | \033[1m%-18d\033[0m |\n", "Mots Differents", dicoNbMotsDifferents(a));
    puts(" +------------------------------+--------------------+");

}


void dicoAfficherRecursive(TArbre *a, char *mot){
    if(arbreEstVide(a))
        return;
    if(a->lettre == '\0'){
        printf(" | %-28s | %-18d |\n", mot, a->nbOcc);
        puts(" +------------------------------+--------------------+");
        dicoAfficherRecursive(a->FD, mot);
        return;
    }
    int len = strlen(mot);
    char *tmp = (char *) malloc(sizeof(char) * (len+2));
    strcpy(tmp, mot);
    tmp[len] = a->lettre;
    tmp[len+1] = '\0';
    dicoAfficherRecursive(a->FG, tmp);
    dicoAfficherRecursive(a->FD, mot);
};


void dicoInsererMot(char *mot, int pos, TArbre **tree){
    if(pos == strlen(mot) || ((pos == strlen(mot)-1) && mot[pos] == '\0') ){  // Check wether we are at the end of the word
        if(!arbreEstVide(*tree) && (*tree)->lettre == '\0'){  // if word already exist than increment nbOcc
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
    if(mot[pos] == (*tree)->lettre)
        dicoInsererMot(mot, pos+1, &((*tree)->FG));
    else if(mot[pos] > (*tree)->lettre)
        dicoInsererMot(mot, pos, &((*tree)->FD));
    else{
        TArbre *newNode = arbreCons(mot[pos], 0, NULL, NULL);
        newNode->FD = *tree;
        *tree = newNode;
        dicoInsererMot(mot, pos+1, &(newNode->FG));
    }
};


int dicoNbOcc(char mot[], int pos, TArbre *a){
    if(arbreEstVide(a))
        return 0;
    if(pos == strlen(mot)){
        if(a->lettre == '\0')
            return a->nbOcc;
        else
            return 0; // Word does not exist in the dictionary
    }
    if(mot[pos] > a->lettre)
        return dicoNbOcc(mot, pos, a->FD);
    else if(mot[pos] == a->lettre)
        return dicoNbOcc(mot, pos+1, a->FG);
    return 0;
};


int dicoNbMotsDifferents(TArbre *a){
    if(!arbreEstVide(a))
        return (a->lettre == '\0') + dicoNbMotsDifferents(a->FD) 
                + dicoNbMotsDifferents(a->FG);
    return 0;
}; 


int dicoNbMotsTotal(TArbre *a){
    if(arbreEstVide(a))
        return 0;
    // Visit each node of the tree and return number of occurance of \0 nodes; 
    return (a->lettre == '\0' ? a->nbOcc : 0) + dicoNbMotsTotal(a->FD) 
                + dicoNbMotsTotal(a->FG);
};


int piocherMot(char **motPioche){
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
    fgets(*motPioche, 100, dico);
    // On vire le \n à la fin
    (*motPioche)[strlen(*motPioche) - 1] = '\0';
    fclose(dico);

    return 1; // Tout s'est bien passé, on retourne 1
}

int nombreAleatoire(int nombreMax){
    return (rand() % nombreMax);
}