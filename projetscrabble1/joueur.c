#include "header.h"



/** Définition de la structure Joueur qui contient nom, score et le chevalet d'un joueur **/

/** Définition de la structure ListeJoueur qui contient la liste de tous les joueurs **/


/** Initialisation de laliste de Joueur à NULL **/
void initJoueur()
{

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
void meilleurScore(joueur tabJ[4])
{
    int max;
    max = tabJ
    for(i = 0; i< 4 ; i++)
    {
        if()
    }
}
*/
