#include "header.h"

#define TAILLE_GRILLE 15
#define TAILLE_CEL 2
#define TAILLE_TAB 15
#define TAILLE_MOT 15

/** Initialisation d'une nouvelle partie de jeu **/

void nvllePartie()
{
    initTableau(tab);
    dessinerGrille(TAILLE_GRILLE, TAILLE_CEL, tab);

    /** Saisie par l'utilisateur des coordonnées du mot **/

    do{
        printf("\n");
        printf("Numero de ligne (entre 1 et 15): ");
        scanf("%d", &ligne);

        printf("Numero de colonne (entre 1 et 15): ");
        scanf("%d", &colonne);
        printf("\n");
    }while(ligne>15 || ligne<1 || colonne<1 || colonne>15);

    /** Saisie du sens du mot par l'utilisateur **/

    do{
        printf("Dans quel sens souhaitez-vous ecrire votre mot ? (H ou V): ");
        scanf("%c", &sens);
        printf("\n");
    }while(sens != 'H' || sens != 'V');



}


void placeMot(char tab)
{
    int h = horizontal();
    int v = vertical();

    if (sens == 'H')
    {
        if( h == 1)
        {
            ecritMot(tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit horizontalement");

    }
    else if(sens == 'V')
    {
        if( v == 1)
        {
            ecritMot(tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit horizontalement");

    }
}


int horizontal(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB] ,int ligne, int colonne, int taille_tab)
{
    int longueur = strlen(mot);
    int i;


}

int vertical(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB] ,int ligne, int colonne, int taille_tab)
{
    int longueur = strlen(mot);
    int j;

}


void ecritMot(char tab[TAILLE_TAB][TAILLE_TAB], char sens)
{
    int i;
    for(int i = 0; i < strlen(mot); i++)
    {
        tab[ligne][colonne] = mot[i];

        if (sens == 'H')
        {
            //on écrit de gauche à droite
            i++;
        }
        if (sens == 'V')
        {
            //on écrit de haut en bas
            j++;
        }
    }

}
/*
void setWord(char identifier, char grid[][num_row]) {


//set respective word
  for (int k = 0; k < strlen(word); k++)
  {
      grid[j][i] = word[k];

     if (identifier == 'H'){
     j++;
    }
    else i++;
  }

}
*/
