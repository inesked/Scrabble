#include "header.h"



/** Création d'une nouvelle partie de jeu **/

void nvllePartie()
{
    int choix;
    int m =0;
    int cpt = 0;
    int fin = verifPioche();
    int v, vj;
    //char c;
    /** Initailisation de la grille de départ **/
    initTableau(tab);
    dessinerGrille(TAILLE_GRILLE, TAILLE_CEL, tab);


    while(fin == 0 && m == 0)
    {
        fin = verifPioche();
        //printf("%d\n", fin);

        for(i = 0; i < nbJoueur; i++)
        {
            printf("Joueur %d:\t nom: %s\t score: %d\n", i+1, tabJ[i].nom, tabJ[i].score);
            for( j =0 ; j< 7; j++)
            {
                printf(" %c\t",tabJ[i].chevalet[j]);
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



/** Vérifie que le mot entré est bien composé des lettres du chevalet **/
int verifMot(char mot[15], char chevalet[TAILLE_CHE])
{
    int tmpChevalet[26], tmpMot[26];
    int i, v;
    char c;
    int lg = strlen(mot);

    for (i =0; i < 26 ;i++)
    {
        tmpChevalet[i] = 0;
        tmpMot[i]= 0;
    }


    //stock lesoccurences du chevalet dans un tableau d'entier temporaire
    for(i=0; i< TAILLE_CHE ; i++)
    {
        c = chevalet[i];

        if( c== 'A' || c == 'a') tmpChevalet[0] += 1;
        else if( c== 'B' || c == 'b') tmpChevalet[1] += 1;
        else if( c== 'C' || c == 'c') tmpChevalet[2] += 1;
        else if( c== 'D' || c == 'd') tmpChevalet[3] += 1;
        else if( c== 'E' || c == 'e') tmpChevalet[4] += 1;
        else if( c== 'F' || c == 'f') tmpChevalet[5] += 1;
        else if( c== 'G' || c == 'g') tmpChevalet[6] += 1;
        else if( c== 'H' || c == 'h') tmpChevalet[7] += 1;
        else if( c== 'I' || c == 'i') tmpChevalet[8] += 1;
        else if( c== 'J' || c == 'j') tmpChevalet[9] += 1;
        else if( c== 'K' || c == 'k') tmpChevalet[10] += 1;
        else if( c== 'L' || c == 'l') tmpChevalet[11] += 1;
        else if( c== 'M' || c == 'm') tmpChevalet[12] += 1;
        else if( c== 'N' || c == 'n') tmpChevalet[13] += 1;
        else if( c== 'O' || c == 'o') tmpChevalet[14] += 1;
        else if( c== 'P' || c == 'p') tmpChevalet[15] += 1;
        else if( c== 'Q' || c == 'q') tmpChevalet[16] += 1;
        else if( c== 'R' || c == 'r') tmpChevalet[17] += 1;
        else if( c== 'S' || c == 's') tmpChevalet[18] += 1;
        else if( c== 'T' || c == 't') tmpChevalet[19] += 1;
        else if( c== 'U' || c == 'u') tmpChevalet[20] += 1;
        else if( c== 'V' || c == 'v') tmpChevalet[21] += 1;
        else if( c== 'W' || c == 'w') tmpChevalet[22] += 1;
        else if( c== 'X' || c == 'x') tmpChevalet[23] += 1;
        else if( c== 'Y' || c == 'y') tmpChevalet[24] += 1;
        else if( c== 'Z' || c == 'z') tmpChevalet[25] += 1;
    }

    for(i=0; i< lg ; i++)
    {
        c = mot[i];

        if( c== 'A' || c == 'a') tmpMot[0] += 1;
        else if( c== 'B' || c == 'b') tmpMot[1] += 1;
        else if( c== 'C' || c == 'c') tmpMot[2] += 1;
        else if( c== 'D' || c == 'd') tmpMot[3] += 1;
        else if( c== 'E' || c == 'e') tmpMot[4] += 1;
        else if( c== 'F' || c == 'f') tmpMot[5] += 1;
        else if( c== 'G' || c == 'g') tmpMot[6] += 1;
        else if( c== 'H' || c == 'h') tmpMot[7] += 1;
        else if( c== 'I' || c == 'i') tmpMot[8] += 1;
        else if( c== 'J' || c == 'j') tmpMot[9] += 1;
        else if( c== 'K' || c == 'k') tmpMot[10] += 1;
        else if( c== 'L' || c == 'l') tmpMot[11] += 1;
        else if( c== 'M' || c == 'm') tmpMot[12] += 1;
        else if( c== 'N' || c == 'n') tmpMot[13] += 1;
        else if( c== 'O' || c == 'o') tmpMot[14] += 1;
        else if( c== 'P' || c == 'p') tmpMot[15] += 1;
        else if( c== 'Q' || c == 'q') tmpMot[16] += 1;
        else if( c== 'R' || c == 'r') tmpMot[17] += 1;
        else if( c== 'S' || c == 's') tmpMot[18] += 1;
        else if( c== 'T' || c == 't') tmpMot[19] += 1;
        else if( c== 'U' || c == 'u') tmpMot[20] += 1;
        else if( c== 'V' || c == 'v') tmpMot[21] += 1;
        else if( c== 'W' || c == 'w') tmpMot[22] += 1;
        else if( c== 'X' || c == 'x') tmpMot[23] += 1;
        else if( c== 'Y' || c == 'y') tmpMot[24] += 1;
        else if( c== 'Z' || c == 'z') tmpMot[25] += 1;
    }

    for( i=0; i<26 ; i++)
    {
        if( tmpChevalet[i]< tmpMot[i]){
            printf("Veuillez ecrire avec les lettres du chevalet\n");
            return v= 0;
        }
    }
    return v=1;

}

/** Demande au joueur suivant si'ili valide le mot entré par le joueur actuel**/
int validJoueur()
{
    char c;
    printf("Validez vous le mot ? (O/N)\n");
    scanf("%s", &c);

    int v;
    if (c == 'O' || c == 'o')
    {
        v= 1;
    }else if( c == 'N' || c == 'n')
    {
        v = 0;
    }

    return v;
}


void placeMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], int ligne, int colonne, int taille_tab, char sens )
{
    int h, v;
    v = vertical(mot, ligne, colonne, TAILLE_TAB );

    h = horizontal(mot, ligne, colonne, TAILLE_TAB );

    //pour le test
    /*
    printf("v = %d\n", v);
    printf("h = %d\n", h);
    printf("sens = %c\n", sens);
    */

    if (sens == 'H' || sens == 'h')
    {
        if( h == 1)
        {
            ecritMot(mot, tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit horizontalement");

    }
    else if(sens == 'V' || sens == 'v')
    {
        if( v == 1)
        {
            ecritMot(mot, tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit verticalement");

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

int vertical(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab)
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
    //printf("%d", cpt);
    if(cpt == 0)
    {
        colonne = 8;
        ligne = 8;
        for(i = 0; i < strlen(mot); i++)
        {
            tab[ligne-1][colonne-1] = mot[i];

            if (sens == 'H' || sens == 'h')
            {
                //on écrit de gauche à droite
                colonne++;
            }
            if (sens == 'V' || sens == 'v')
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

            if (sens == 'H' || sens == 'h')
            {
                //on écrit de gauche à droite
                colonne++;
            }
            if (sens == 'V' || sens == 'v')
            {
                //on écrit de haut en bas
                ligne++;
            }
        }
        cpt++;
    }

}

void chrono()
{
   clock_t t;
   int secactu=0;

   getchar();
   t = clock();

   do
   {
      if((clock()-t) / (double) CLOCKS_PER_SEC > secactu+1)
      {
         secactu++;
         printf("\nDeja %d secondes, il vous reste %d secondes\n", secactu, (30-secactu));
      }
   }while(secactu != 5);
}
