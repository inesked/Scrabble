#include "header.h"



/** Création d'une nouvelle partie de jeu **/

void nvllePartie(int cpt)
{
    /** Initailisation de la grille de départ **/
    initTableau(tab);
    dessinerGrille(TAILLE_GRILLE, TAILLE_CEL, tab);


    while(cpt < 3)
    {
        if(cpt > 0)
        {
            /** Saisie par l'utilisateur des coordonnées du mot **/

            do{
                printf("\n");
                printf("Numero de ligne (entre 1 et 15): ");
                scanf("%d", &ligne);

                printf("Numero de colonne (entre 1 et 15): ");
                scanf("%d", &colonne);
                printf("\n");
            }while(ligne>15 || ligne<1 || colonne<1 || colonne>15);
        }

    /** Saisie du sens du mot par l'utilisateur **/

        do{
            printf("Dans quel sens souhaitez-vous ecrire votre mot ? (H ou V): ");
            fflush(stdin);
            scanf("%c", &sens);
            printf("\n");
        }while(sens != 'H' && sens != 'V');

        printf("Mot (pas plus de 15 lettres):");
        fflush(stdin);
        scanf("%s", mot);
        printf("\n");

        placeMot(mot, tab, ligne, colonne, TAILLE_TAB, sens);
        dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);

        cpt++;
    }


    /* TEST DE VERIF
    printf("mot a ecrire : %s", mot);

    vertical(mot, ligne, colonne, TAILLE_TAB);

    horizontal(mot, ligne, colonne, TAILLE_TAB);

    printf("Fonction placeMot \n");
    placeMot(mot, tab, ligne, colonne, TAILLE_TAB, sens);
    */
    //dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
}


void placeMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], int ligne, int colonne, int taille_tab, char sens )
{
    int h, v;
    v = vertical(mot, ligne, colonne, TAILLE_TAB );

    h = horizontal(mot, ligne, colonne, TAILLE_TAB );

    printf("v = %d\n", v);
    printf("h = %d\n", h);
    printf("sens = %c\n", sens);

    if (sens == 'H')
    {
        if( h == 1)
        {
            ecritMot(mot, tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit horizontalement");

    }
    else if(sens == 'V')
    {
        if( v == 1)
        {
            ecritMot(mot, tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit horizontalement");

    }
}


int horizontal(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab)
{
    int longueur = strlen(mot);
    //int i;

    if( longueur > TAILLE_TAB || TAILLE_TAB-colonne < longueur )
    {
        printf("Erreur, le mot est trop long\n");
        return 0;
    }
    else
    {
        return 1;
    }

}

int vertical(char mot[TAILLE_MOT] ,int ligne, int colonne, int taille_tab)
{
    int longueur = strlen(mot);
    //int j;

    if( longueur > TAILLE_TAB || TAILLE_TAB-ligne < longueur )
    {
        printf("Erreur, le mot est trop long\n");
        return 0;
    }
    else
    {
        printf("ok\n");
        return 1;
    }


}


void ecritMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], char sens)
{
    int i;

    if(cpt == 0)
    {
        colonne = 8;
        ligne = 8;
        for(i = 0; i < strlen(mot); i++)
        {
            tab[ligne-1][colonne-1] = mot[i];

            if (sens == 'H')
            {
                //on écrit de gauche à droite
                colonne++;
            }
            if (sens == 'V')
            {
                //on écrit de haut en bas
                ligne++;
            }
        }
        cpt++;
    }
    else
    {
        for(i = 0; i < strlen(mot); i++)
        {
            tab[ligne-1][colonne-1] = mot[i];

            if (sens == 'H')
            {
                //on écrit de gauche à droite
                colonne++;
            }
            if (sens == 'V')
            {
                //on écrit de haut en bas
                ligne++;
            }
        }
        cpt++;
    }

}
