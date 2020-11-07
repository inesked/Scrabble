#include "header.h"


int main()
{
    int choix;

    while( choix != 5)
    {

        Color(5,7);
        printf("\n******************SCRABBLE******************\n\n");
        printf("------Veuillez selectioner une action------ \n1. Pour lancer une nouvelle partie \n2. Pour reprendre une partie sauvegardée\n");
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
            partieSauvegarder(tab);
            //reprendre partie
            break;

        case 3:
            /** Affiche le fichier aide qui contient les règles du jeu et les explications du déroulement du jeu**/
//            aide();
            break;

        case 4:
            initJoueur();
            break;

        case 5:
            sauvegarde(tab);
            printf("a bientot ! :)");
            return 0;
            break;

        case 6:

            printf("Saisir un mot :\n");
            scanf("%s", mot);


            FILE *fichier;
            fichier=fopen("dictionnaire.txt","r");
            for(i=0; i<22740; i++)
            {
                fscanf(fichier, "%c\n", &mot[i]);
            }
            printf("test1");

            if(fichier==NULL)
            {
                printf("Pb ouverture du fichier lettre.txt\n");
            }

            printf("test4");

            fscanf(fichier, "%s\n", &mot[i]);
            if(strcmp(mot, fichier)==0)
            {
                printf("test5");
                printf("Le mot saisi existe dans le dictionnaire\n");
            }
            else if(strcmp(mot, fichier)==1)
            {
                printf("Le mot saisi n'existe pas dans le dictionnaire\n");
                printf("Veuillez en saisir un autre\n");
            }
            //test affichage
            //ecriremot();
            break;

            return 0;
        }
    }
}
