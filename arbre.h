#ifndef DEF_ARBRE
#define DEF_ARBRE

typedef struct TArbre{
    char lettre;
    int nbOcc;
    struct TArbre *FG;
    struct TArbre *FD;
}TArbre;

TArbre* arbreConsVide(); 
int arbreEstVide(TArbre* a); 
TArbre* arbreCons(char c, int n, TArbre* fg, TArbre* fd); 
char arbreRacineLettre(TArbre* a); 
int arbreRacineNbOcc(TArbre* a); 
TArbre* arbreFilsGauche(TArbre* a); 
TArbre* arbreFilsDroit(TArbre* a); 
void arbreSuppr(TArbre* a); 

#endif