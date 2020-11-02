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
int cpt; //Permet d'indiquer au programme si on est au premier tour pour le placement du premier mot
char mot[15]; //chaine de caractère qui contient le mot à placer

char grille[TAILLE_TAB][TAILLE_TAB]; //
char tab[TAILLE_TAB][TAILLE_TAB]; //tableau qui contient le plateau de jeu

/** Définition des prototypes des fonctions **/

//dessine et affiche le plateau
void initTableau(char tab[TAILLE_TAB][TAILLE_TAB]);
void dessinerGrille(int tailleGrille, int tailleCel, char tab[TAILLE_TAB][TAILLE_TAB]);

//Place le mot et l'écrit dans le tableau
void placeMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], int ligne, int colonne, int taille_tab, char sens);
void ecritMot(char mot[TAILLE_MOT] ,char tab[TAILLE_TAB][TAILLE_TAB], char sens);

//vérifie si le mot peut être écrit à l'horizontale ou à la verticale
int horizontal(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab);
int vertical(char mot[TAILLE_MOT] ,int ligne, int colonne, int taille_tab);

// Définit une nouvelle partie
void nvllePartie();

//Affiche les règles du jeu
void aide();

//Fait une sauvegarde du plateau dans un fichier texte avant de quitter le programme
void sauvegarde(char tab[TAILLE_TAB][TAILLE_TAB]);
void lireSauvegarde(char tab[TAILLE_TAB][TAILLE_TAB]);
void partieSauvegarder(char tab[TAILLE_TAB][TAILLE_TAB]);
