#include "header.h"

#define CARAC_MAX 20
#define ESPACE " "
//initialisation du sp de sauvegarde avec en parametre le tableau
void sauvegarde(char tab[TAILLE_TAB][TAILLE_TAB])
{
    int i,j;
    FILE *file = NULL;                      //ouverture du txt sauvegarde en écriture
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
        fclose(file);                       // fermeture du txt sauvegarde
    }
}

void sauvegardeJoueur(joueur tabJ[4])       // initialisation de la sauvegarde joeur avec en  parametre le tab joueur
{
    int i,j;
    FILE *file = NULL;
    file = fopen("joueur.txt", "w+");       //ouverture du txt joueur en écriture

    if( file != NULL)
    {
        fprintf(file, "%d", nbJoueur);      //ecriture dans le fichier du nombre de joueur
        fprintf(file, "\n");
        for(i=0; i< 4 ; i++)
        {
            if (tabJ[i].nom != NULL)
            {
                fprintf(file, "%s", tabJ[i].nom);       //écriture dans le fichier du nom du joueur
                fprintf(file, "\n");
                fprintf(file, "%d", tabJ[i].score);     //écriture dans le fichier du score du joueur
                fprintf(file, "\n");

                for(j=0; j< TAILLE_CHE; j++)
                {
                    fprintf(file, "%c", tabJ[i].chevalet[j]); //écriture dans le fichier des caracteres restants du chevalet
                }
                fprintf(file, "\n"); //retour à la ligne
            }
        }
        fclose(file); //fermeture du fichier sauvegarde
    }
}

void sauvegardePioche(lettre pioche[26])        //initialisation de la sauvegarde de la pioche avec en parametre les 26 lettres de l'alphabet + le bonus
{
    int i;
    FILE *file = NULL;
    file = fopen("pioche.txt", "w+"); // ouverture du ficher pioche.txt

    if( file != NULL)
    {
        for(i=0; i< 26 ; i++)
        {
            fprintf(file, "%c", pioche[i].nom);     //  ecriture dans le fichier du nom de la lettre
            fprintf(file, "%d", pioche[i].nbOcc);   //  ecriture dans le fichier du nombre d'occurence
            fprintf(file, "%d", pioche[i].valeur);  //  écriure dans le fichier du nombre de point porté par la letrre

            fprintf(file, "\n");
        }
        fclose(file);                               // fermeture du fichier
    }

}

void historique(joueur tabJ[4])                 //initialisation de l'historique de tout les joueurs et de tout les scores
{
    int i;
    FILE *file = NULL;
    file = fopen("historique.txt", "a");

    if( file != NULL)
    {
        //while(k)
        fprintf(file, "Score d'une partie:\n");     //écriture dans le fichier
        for(i=0; i< 4 ; i++)
        {

            if (tabJ[i].nom != NULL)            //si le nom n'est pas nul
            {
                fprintf(file, "%s %d", tabJ[i].nom, tabJ[i].score); //2criture du nom et du score du joueur
                fprintf(file, "\n");
            }
        }
        fprintf(file, "\n");
        fclose(file);
    }
}



void lireSauvegarde(char tab[TAILLE_TAB][TAILLE_TAB])       //initialisation de la lecture de sauvegarde
{
    int i, j;
    FILE *file = NULL;
    file = fopen("sauvegarde.txt", "r"); //ouverture du fichier en mode lecutre

    if(file != NULL)
    {
        for( i=0 ; i< TAILLE_TAB ; i++)
        {
            for( j= 0 ; j< TAILLE_TAB ; j++)
            {
                fscanf(file, "%c", &tab[i][j]);     //lecture du tableau
            }
            fscanf(file, "\n");
        }
        fclose(file);
    }
}

void lireSauvegardeJoueur(joueur tabJ[4])       //initialisation de la sauvegarde joueur avec son nom, son score et son chevalet en LECTURE
{
    int i, j;
    FILE *file = NULL;
    file = fopen("joueur.txt", "r");

    if(file != NULL)
    {
        fscanf(file, "%d", &nbJoueur);
        fscanf(file, "\n");

        for( i=0 ; i< 4 ; i++)
        {
            fscanf(file, "%s", &tabJ[i].nom);
            fscanf(file, "\n");
            fscanf(file, "%d", &tabJ[i].score);
            fscanf(file, "\n");

            for(j=0; j< 7; j++)
            {
                fscanf(file, "%c", &tabJ[i].chevalet[j]);
            }
            fscanf(file, "\n");
        }
    }
        fclose(file);
}

void lireSauvegardePioche(lettre pioche[TAILLE_PIOCHE]) //lecture de la sauvegarde de la pioche en mode read
{
    int i;
    FILE *file = NULL;
    file = fopen("pioche.txt", "r");            // lecture du nom, nombre d'occurence et valeure portée par la lettre

    if(file != NULL)
    {
        for(i= 0 ; i<26 ; i++)
        {
            fscanf(file, "%c %d %d\n", &pioche[i].nom, &pioche[i].nbOcc, &pioche[i].valeur);
        }

        fclose(file);
    }
}


void partieSauvegarder() //appele de toute les premieres fonctions
{
    int i, j;
    int choix;
    int m = 0;
    cpt =1;
    int fin = verifPioche();
    int v, vj;

    //Initialisation des éléments grace au fichier de sauvegarde
    lireSauvegarde(tab);
    lireSauvegardeJoueur(tabJ);
    lireSauvegardePioche(pioche);
    dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
    //printf("%d", nbJoueur);

    while(fin == 0 && m ==0)
    {
        fin = verifPioche();

        for(i = 0; i < nbJoueur; i++)
        {
            printf("Joueur %d:\t nom: %s\t score: %d\n", i+1, tabJ[i].nom, tabJ[i].score);
            for( j =0 ; j< 7; j++)
            {
                printf("%c ",tabJ[i].chevalet[j]);
            }
            printf("\n");

        if(cpt > 0)
        {
            /** Saisie par l'utilisateur des coordonnées du mot **/

            do
            {
                printf("\n");
                printf("Numero de ligne (entre 1 et 15): ");
                scanf("%d", &ligne);

                printf("Numero de colonne (entre 1 et 15): ");
                scanf("%d", &colonne);
                printf("\n");
            }
            while(ligne>15 || ligne<1 || colonne<1 || colonne>15);
        }

        /** Saisie du sens du mot par l'utilisateur **/

        do
        {
            printf("Dans quel sens souhaitez-vous ecrire votre mot ? (H ou V): ");
            fflush(stdin);
            scanf("%c", &sens);
            printf("\n");
        }
        while(sens != 'H' && sens != 'V' && sens != 'h' && sens != 'v');



        /** Saisie du mot par l'utilisateur pour vérification des lettres dans le chevalet **/
       do{
            printf("Mot (pas plus de 15 lettres):");
            fflush(stdin);
            scanf("%s", mot);

            v = verifMot(mot, tabJ[i].chevalet);
        }while(v == 0);

        //chrono();

        vj = validJoueur();

        /** Place le mot et maj le chevalet avant de calculer le score du mot**/
        if(vj == 1)
        {
            //dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
            placeMot(mot, tab, ligne, colonne, TAILLE_TAB, sens);
            printf("test");
            majChevalet(tabJ[i].chevalet, mot, i);
            tabJ[i].score = tabJ[i].score + calculScore(tab,mot, ligne, colonne, sens);
            cpt++;


        }
        else{
            tabJ[i].score += 10;
        }

        printf("\n");

        }
        do{
            printf("Souhaitez vous continuez ou retourner au menu et sauvegarder le mot? (1 ou 2): \n");
            scanf("%d", &choix);
        }while(choix != 1 && choix != 2);

        if(choix == 2)
        {
            sauvegarde(tab);
            sauvegardeJoueur(tabJ);
            sauvegardePioche(pioche);
            m = 1;
        }
    }
    //meilleurScore(tabJ, nbJoueur);
    historique(tabJ);
    menu();


    /* TEST DE VERIF
    printf("mot a ecrire : %s", mot);

    vertical(mot, ligne, colonne, TAILLE_TAB);

    horizontal(mot, ligne, colonne, TAILLE_TAB);

    printf("Fonction placeMot \n");
    placeMot(mot, tab, ligne, colonne, TAILLE_TAB, sens);
    */
    //dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
}

