#include "header.h"

void initJoueur()
{
    int nbJoueur;
    int i, j;
    //lettre tmp[TAILLE_CHE];

    do
    {
        printf("Nombre de joueur: ");
        scanf("%d", &nbJoueur);
        printf("\n");
    }while( nbJoueur < 2 || nbJoueur > 4);


    for( i =0 ; i< nbJoueur; i++)
    {
        printf("Nom du joueur%d:", i+1);
        scanf("%s", tabJ[i].nom);
        tabJ[i].score = 0;
        //tmp[TAILLE_CHE] =
        tabJ[i].chevalet[TAILLE_CHE] = creerChevalet();

        printf(" Joueur %d: \n\tnom: %s\n\tscore: %d\n\tchevalet:", i+1, tabJ[i].nom, tabJ[i].score);
        for( j =0 ; j< 7; j++)
        {
            printf(" %d%c\t", tabJ[i].chevalet[j].nbOcc ,tabJ[i].chevalet[j].nom);
        }
        printf("\n");
    }
}
