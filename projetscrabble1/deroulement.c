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

// Boucle qui determine tout les tours de jeu
    while(fin == 0 && m == 0)
    {
        fin = verifPioche();
        //printf("%d\n", fin);

    //Permet de faire jouer tous les joueurs
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

            chrono();
            /** Saisie du mot par l'utilisateur pour vérification des lettres dans le chevalet **/
            do
            {
                printf("Mot (pas plus de 15 lettres):");
                fflush(stdin);
                scanf("%s", mot);
                v = verifMot(mot, tabJ[i].chevalet);

            }
            while(v == 0);
            //miniDico(mot);


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
            else
            {
                tabJ[i].score += 10;
            }

            printf("\n");

        }
        //Demande à l'utilisateur si il souhaite continuer à jouer ou sauvegarder et retourner au menu
        do
        {
            printf("Souhaitez vous continuez ou retourner au menu et sauvegarder le mot? (1 ou 2): \n");
            scanf("%d", &choix);
        }
        while(choix != 1 && choix != 2);

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

//Compare le mot écrit avec tous les mots présents dans le dictionnaire
void miniDico(char mot[TAILLE_MOT])
{
    int b=0;
    //printf("Saisir mot\n");
    //scanf("%s", mot);
    char temp[TAILLE_MAX];
    FILE *fichier;
    fichier=fopen("minidico.txt","r");

    //Compare le mot avec tout les mots du dico grace à une boucle
    for(i=0; i<671; i++)
    {
        fscanf(fichier, "%s\n", temp);
        if(fichier==NULL)
        {
            printf("Pb ouverture du fichier lettre.txt\n");
        }
        if(strcmp(mot, temp)==0)
        {
            printf("Le mot saisi existe dans le dictionnaire\n");
            //i=3;
            b = 1;
        }
        else if(strcmp(mot, temp)!=0 && b==0)
        {
            b = 0;
        }
    }
    if(b==0)
    {
        printf("Le mot saisi n'existe pas dans le dictionnaire\n");
    }
    fclose(fichier);

}



/** Vérifie que le mot entré est bien composé des lettres du chevalet **/
int verifMot(char mot[15], char chevalet[TAILLE_CHE])
{
    int tmpChevalet[26], tmpMot[26];
    int i, v;
    char c;
    int lg = strlen(mot);

    for (i =0; i < 26 ; i++)
    {
        tmpChevalet[i] = 0;
        tmpMot[i]= 0;
    }


    //stock les occurences du chevalet dans un tableau d'entier temporaire
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

    //Stock les occurences des lettres du mot dans un fichier temporaire
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

    //Compare les occurences des deux tableaux et
    for( i=0; i<26 ; i++)
    {
        if( tmpChevalet[i]< tmpMot[i])
        {
            printf("Veuillez ecrire avec les lettres du chevalet\n");
            return v= 0;
        }
    }

    return v=1;

}

/** Demande au joueur suivant s'il valide le mot entré par le joueur actuel**/
int validJoueur()
{
    char c;
    printf("Validez vous le mot ? (O/N)\n");
    scanf("%s", &c);

    int v;
    //si oui
    if (c == 'O' || c == 'o')
    {
        v= 1;
    }
    //si non
    else if( c == 'N' || c == 'n')
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
//si on écrit horizontalement
    if (sens == 'H' || sens == 'h')
    {
        //verife horizontale est vlidé h =1
        if( h == 1)
        {
            ecritMot(mot, tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit horizontalement");

    }
// si on écrit verticalement
    else if(sens == 'V' || sens == 'v')
    {
    //verif horizontale est validé v =1

        if( v == 1)
        {
            ecritMot(mot, tab, sens);
            dessinerGrille(TAILLE_TAB, TAILLE_CEL, tab);
        }
        else
            printf("Le mot ne peut pas etre ecrit verticalement");

    }
}

//Vérification horizontale, renvoie un booléen
int horizontal(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab)
{
    int longueur = strlen(mot);
    //int i;
//vérifie que le mot n'est pas trop long pour le tableau et qui'il ne dépasse pas
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

//Vérification horizontale, renvoie un booléen
int vertical(char mot[TAILLE_MOT],int ligne, int colonne, int taille_tab)
{
    int longueur = strlen(mot);
    //int j;
//vérifie que le mot n'est pas trop long pour le tableau et qui'il ne dépasse pas
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

//Parcourt le tableau pour écrire le mot
void ecritMot(char mot[TAILLE_MOT], char tab[TAILLE_TAB][TAILLE_TAB], char sens)
{
    int i;
    //printf("%d", cpt);

    //Condtion pour le premier mot du tableau
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
    // si on est au tour suivant alors prend les coordonnes entrées en paramètres par l'utilisateur pour
    // pour faire le parcours
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
    int s = 5;
    getchar();
    t = clock();

    do
    {
        if((clock()-t) / (double) CLOCKS_PER_SEC > secactu+1)
        {
            secactu++;
            printf("\nDeja %d secondes, il vous reste %d secondes\n", secactu, (s-secactu));
        }
    }
    while(secactu != s);
    printf("Temps ecoule !!!\n");
}
