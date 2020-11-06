#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

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
#define TAILLE_PIOCHE 26
#define TAILLE_CHE 7


//faire strucuture Partie avec (joueur, temps, pioche, afficher les points des joueurs)
//faire structure joueur avec (lettres, points,

/** D�finition des structures **/


typedef struct lettre
{
    char nom;
    int nbOcc;
    int valeur;
} lettre;

typedef struct joueur
{
    char nom[15];
    int score;
    char chevalet[TAILLE_CHE];
}joueur;


/** D�finition des variables globales et tableaux **/

char sens;  //Prend la valeur V ou H pour d�signer le sens du mot sur le plateau
int ligne; //num�ro de ligne entr� pour plac� le mot
int colonne; //num�ro de colonne entr� pour plac� le mot
int i, j, k; //variable de parcours
int cpt; //Permet d'indiquer au programme si on est au premier tour pour le placement du premier mot
int nbJoueur;

joueur tabJ[4];
char mot[15]; //chaine de caract�re qui contient le mot � placer
lettre pioche[26]; //contient la pioche
//lettre chevalet[TAILLE_CHE];
char grille[TAILLE_TAB][TAILLE_TAB]; //
char tab[TAILLE_TAB][TAILLE_TAB]; //tableau qui contient le plateau de jeu

/** D�finition des prototypes des fonctions **/

//dessine et affiche le plateau
void initTableau(char tab[TAILLE_TAB][TAILLE_TAB]);
void dessinerGrille(int tailleGrille, int tailleCel, char tab[TAILLE_TAB][TAILLE_TAB]);

//Place le mot et l'�crit dans le tableau
void placeMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], int ligne, int colonne, int taille_tab, char sens);
void ecritMot(char mot[TAILLE_MOT] ,char tab[TAILLE_TAB][TAILLE_TAB], char sens);

//v�rifie si le mot peut �tre �crit � l'horizontale ou � la verticale
int horizontal(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab);
int vertical(char mot[TAILLE_MOT] ,int ligne, int colonne, int taille_tab);

// D�finit une nouvelle partie
void nvllePartie();

//Affiche les r�gles du jeu
void aide();

//Fait une sauvegarde du plateau dans un fichier texte avant de quitter le programme
void sauvegarde(char tab[TAILLE_TAB][TAILLE_TAB]);
void lireSauvegarde(char tab[TAILLE_TAB][TAILLE_TAB]);
void partieSauvegarder(char tab[TAILLE_TAB][TAILLE_TAB]);


void affichePioche(lettre pioche[TAILLE_PIOCHE]);
void creerPioche();
void piocher(char chevalet[TAILLE_CHE]);
void creerChevalet(char tab[TAILLE_CHE], int j);
void suppCase(char chevalet[TAILLE_CHE],int j);

int scoreLettre(char c);
int scoreMot(char tab[TAILLE_TAB][TAILLE_TAB], char mot[TAILLE_MOT]);
void initJoueur();
void chrono();
int verifPioche();
int verifMot(char mot[15], char chevalet[TAILLE_CHE]);
int validJoueur();
