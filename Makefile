CFLAGS := -Wall -g
main: dico.h dico.c arbre.h arbre.c projet.c
	gcc $(CFLAGS) projet.c  arbre.c dico.c -o main