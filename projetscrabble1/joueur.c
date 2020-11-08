#include "header.h"



/** Initialisation du tableau de Joueur à NULL **/
void initJoueur()
{

    int i, j;
    //lettre tmp[TAILLE_CHE];

    do
    {
        printf("Nombre de joueur: ");
        scanf("%d", &nbJoueur);
        printf("\n");
    }while( nbJoueur < 2 || nbJoueur > 4);  // blindage pour que le nombre de joueur soit compris entre 2 et 4


    for( i =0 ; i< nbJoueur; i++)           // attribution d'un chevallet à chaque joueur
    {
        printf("Nom du joueur%d:", i+1);
        scanf("%s", tabJ[i].nom);
        tabJ[i].score = 0;
        //tmp[TAILLE_CHE] =
        creerChevalet(tabJ[i].chevalet, i);

        printf(" Joueur %d: \n\tnom: %s\n\tscore: %d\n\tchevalet:", i+1, tabJ[i].nom, tabJ[i].score);
        for( j =0 ; j< 7; j++)
        {
            printf(" %c\t",tabJ[i].chevalet[j]);
        }
        printf("\n");
    }
}

/*
void meilleurScore(joueur tabJ[4], int nbJoueur)
{
    int indice;
    int tmp =0;
    for(i = 0; i< nbJoueur ; i++)
    {
        if(tmp< tabJ[i].score)
        {
            tmp = tabJ[]
        }
    }
    printf("%s a le meilleur score, %d points", tabJ[indice].nom, tabJ[indice].score);
}
*/
