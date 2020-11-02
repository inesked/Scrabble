#include "header.h"



int main()
{
    int choix;

    printf("\n******************SCRABBLE******************\n\n");
    printf("------Veuillez selectioner une action------ \n1. Pour lancer une nouvelle partie \n2. Pour reprendre une partie sauvegardée\n");
    printf("3. Pour afficher l'aide \n4. Pour afficher les scores des joueurs \n5. Pour quitter le jeu\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        //nouvelle partie
        nvllePartie();
        break;

    case 2:
        //reprendre partie
        break;

    case 3:

        aide();
        break;

    case 4:
        break;

    case 5:
        printf("a bientot ! :)");
        return 0;
        break;

    case 6:
        //test affichage
        //ecriremot();
        break;

        return 0;
    }
}

int aide()
{
    FILE * fichier;//=NULL;
    char mot[TAILLE_MAX] = "";
    int i;
    fichier = fopen("aide.txt", "r"); // r pour read
     if (fichier != NULL)
    {
        while (fgets(mot, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", mot); // On affiche la chaîne qu'on vient de lire
        }

        fclose(fichier);
    }

    return 0;
}
