#include "header.h"

#define CARAC_MAX 20
#define ESPACE " "

void sauvegarde(char tab[TAILLE_TAB][TAILLE_TAB])
{
    int i,j;
    FILE *file = NULL;
    file = fopen("sauvegarde.txt", "w+");

    if( file != NULL)
    {
        for(i=0; i< TAILLE_TAB ; i++)
        {
            for( j=0 ; j<TAILLE_TAB ; j++)
            {
                fprintf(file, "%c", tab[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
}

void lireSauvegarde(char tab[TAILLE_TAB][TAILLE_TAB])
{
    int i, j;
    FILE *file = NULL;
    file = fopen("sauvegarde.txt", "r");

    if(file != NULL)
    {
        for( i=0 ; i< TAILLE_TAB ; i++)
        {
            for( j= 0 ; j< TAILLE_TAB ; j++)
            {
                fscanf(file, "%c", &tab[i][j]);

            }
            fscanf(file, "\n");
        }
        fclose(file);
    }
}


void partieSauvegarder(char tab[TAILLE_TAB][TAILLE_TAB], int cpt)
{
    cpt =1;
    lireSauvegarde(tab);
    dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);

    while(1)
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

