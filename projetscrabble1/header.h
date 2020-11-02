#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
#include "plateau.c"
#include "deplacement.c"
#include "ecriremot.c"
*/
#define TAILLE_MAX 1000
#define TAILLE_GRILLE 15
#define TAILLE_CEL 2
#define TAILLE_TAB 15
#define TAILLE_MOT 15

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

char sens;  //Prend la valeur V ou H pour désigner le sens du mot sur le plateau
int ligne; //numéro de ligne entré pour placé le mot
int colonne; //numéro de colonne entré pour placé le mot
int i, j, k; //variable de parcours
char mot[15]; //chaine de caractère qui contient le mot à placer

char grille[TAILLE_TAB][TAILLE_TAB];
char tab[TAILLE_TAB][TAILLE_TAB];

/** Définition des prototypes des fonctions **/
void initTableau(char tab[TAILLE_TAB][TAILLE_TAB]);
void dessinerGrille(int tailleGrille, int tailleCel, char tab[TAILLE_TAB][TAILLE_TAB]);

void placeMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], int ligne, int colonne, int taille_tab, char sens);
int horizontal(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab);
int vertical(char mot[TAILLE_MOT] ,int ligne, int colonne, int taille_tab);
void ecritMot(char mot[TAILLE_MOT] ,char tab[TAILLE_TAB][TAILLE_TAB], char sens);


void nvllePartie();




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
