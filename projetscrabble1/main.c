#include "header.h"


int main()
{
    int choix;

    while( choix != 5)
    {

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
            partieSauvegarder(tab);
            //reprendre partie
            break;

        case 3:
            /** Affiche le fichier aide qui contient les règles du jeu et les explications du déroulement du jeu**/
//            aide();
            break;

        case 4:
            creerPioche();
            creerChevalet();
            break;

        case 5:
            sauvegarde(tab);
            printf("a bientot ! :)");
            return 0;
            break;

        case 6:
            chrono();
            //test affichage
            //ecriremot();
            break;

            return 0;
        }
    }
}
