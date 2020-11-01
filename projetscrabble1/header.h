#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "plateau.c"

#define TAILLE_MAX 1000
#define TAILLE_GRILLE 15
#define TAILLE_CEL 2
#define TAILLE_TAB 15

//faire strucuture Partie avec (joueur, temps, pioche, afficher les points des joueurs)
//faire structure joueur avec (lettres, points,

/** Définition des structures **/

typedef struct
{
    char nom;
    int nbOcc;
    int valeur;
}Lettre;


/** Définition des variables globales et tableaux **/
char grille[TAILLE_TAB][TAILLE_TAB];
char tab[TAILLE_TAB][TAILLE_TAB];

/** Définition des prototypes des fonctions **/
void initTableau(char tab[TAILLE_TAB][TAILLE_TAB]);
void dessinerGrille(int tailleGrille, int tailleCel, char tab[TAILLE_TAB][TAILLE_TAB]);


int aide()
{
    FILE * fichier;//=NULL;
    char mot[TAILLE_MAX] = "";
    int i;
    fichier = fopen("aide.txt", "r"); // r pour read
     if (fichier != NULL)
    {
        while (fgets(mot, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", mot); // On affiche la chaîne qu'on vient de lire
        }

        fclose(fichier);
    }

    return 0;
}

#endif // HEADER_H_INCLUDED
/*
int main()
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("test.txt", "r");

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }

        fclose(fichier);
    }

    return 0;
}*/
