#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define TAILLE_MAX 1000
#define TAILLE_GRILLE 15
#define TAILLE_CEL 2
#define TAILLE_TAB 15
#define TAILLE_MOT 15
#define TAILLE_PIOCHE 26
#define TAILLE_CHE 7
/**
sources
Cours et TP ing 3​
OpenClassRoom​
https://www.daniweb.com/ pour le plateau ​
(https://www.daniweb.com/programming/software-development/threads/195830/scrabble-in-c) ​
http://www.gtoal.com/ certains algorithmes​
https://www.mathworks.com/matlabcentral/answers/276744-how-do-you-write-to-a-fopen-text-file-without-deleting-previous-text​
https://melem.developpez.com/tutoriels/langage-c/fichiers/?page=cours#LIII-A​
https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16421-lire-et-ecrire-dans-des-fichiers pour les structures ​
**/


/** Définition des structures **/
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


/** Définition des variables globales et tableaux **/

char sens;  //Prend la valeur V ou H pour désigner le sens du mot sur le plateau
int ligne; //numéro de ligne entré pour placé le mot
int colonne; //numéro de colonne entré pour placé le mot
int i, j, k; //variable de parcours
int cpt; //Permet d'indiquer au programme si on est au premier tour pour le placement du premier mot
int nbJoueur;

joueur tabJ[4];
char mot[15]; //chaine de caractère qui contient le mot à placer
lettre pioche[26]; //contient la pioche
//lettre chevalet[TAILLE_CHE];
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

//Sauvegarde de la partie
void partieSauvegarder();

// creation de la pioche et du chevalet, avec mise à jour en fonction des lettres déposés sur le plateau de jeu
void affichePioche(lettre pioche[TAILLE_PIOCHE]);
void creerPioche();
void piocher(char chevalet[TAILLE_CHE],int k, int j);
void creerChevalet(char tab[TAILLE_CHE], int j);
void suppCase(char chevalet[TAILLE_CHE],int j);
void majChevalet(char chevalet[TAILLE_CHE], char mot[TAILLE_MOT], int idjoueur);

//attribution d'un score aux lettres avec bonus
int scoreLettre(char c);
int bonus(char tab[TAILLE_TAB][TAILLE_TAB], char mot[TAILLE_MOT], int ligne, int colonne);
void initJoueur();

//chrono pour que le joueur ne s'eternise pas
void chrono();
// verification que le mot est composé des lettres de la pioche
int verifPioche();
int verifMot(char mot[15], char chevalet[TAILLE_CHE]);

//validation par le joueur
int validJoueur();

//score avec les bonus
int bonusMot(int ligne, int colonne);
int bonusLettre( int ligne, int colonne);
int calculScore(char tab[TAILLE_TAB][TAILLE_TAB], char mot[TAILLE_MOT], int ligne, int colonne, char sens);

//donction couleur donnée sur campus
void Color(int couleurDuTexte,int couleurDeFond);
//menu
void menu();

//Fait une sauvegarde du plateau dans un fichier texte avant de quitter le programme
void sauvegarde(char tab[TAILLE_TAB][TAILLE_TAB]);
void lireSauvegarde(char tab[TAILLE_TAB][TAILLE_TAB]);
void sauvegardePioche(lettre pioche[TAILLE_PIOCHE]);
void sauvegardeJoueur(joueur tabJ[4]);
void lireSauvegardePioche(lettre pioche[TAILLE_PIOCHE]);
void lireSauvegardeJoueur(joueur tabJ[4]);
void historique();

//affichage du meilleur score parmis les joueurs
void meilleurScore(joueur tabJ[4], int nbJoueur);

//verification que le mot écrit existe dans le dictionnaire
void miniDico(char mot[TAILLE_MOT]);



