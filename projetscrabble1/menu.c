#include "header.h"

void menu()
{
        int choix;

    while( choix != 5)
    {

        Color(5,7);
        printf("\n******************SCRABBLE******************\n\n");
        printf("------Veuillez selectioner une action------ \n1. Pour lancer une nouvelle partie \n2. Pour reprendre une partie sauvegard�e\n");
        printf("3. Pour afficher l'aide \n4. Pour afficher les scores des joueurs \n5. Pour quitter le jeu\n");
        scanf("%d", &choix);

        Color(15,0);

        switch (choix)
        {
        case 1:
            //nouvelle partie
            creerPioche();
            initJoueur();
            nvllePartie();
            break;

        case 2:

            partieSauvegarder();
            //reprendre partie
            break;

        case 3:
            /** Affiche le fichier aide qui contient les r�gles du jeu et les explications du d�roulement du jeu**/
           aide();
            break;

        case 4:
            initJoueur();
            break;

        case 5:
            sauvegarde(tab);
            printf("a bientot ! :)");
            return 0;
            break;

        }
    }

}
