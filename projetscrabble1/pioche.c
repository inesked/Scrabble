#include "header.h"
#define TAILLE_TAB 15



void creerPioche()          //creation de la pioche
{
    int i;
    FILE *file;
    file = fopen("lettre.txt", "r");        //ouverture du ficheier en lecture

    if(file==NULL){
        printf("Pb ouverture du fichier lettre.txt\n");
	}



	for(i=0; i<TAILLE_PIOCHE; i++)  //lecutre dans le fichier du nom de la lettre, de son nombre d'occurence et de son nombre de point
    {
        fscanf(file, "%c %d %d\n", &pioche[i].nom, &pioche[i].nbOcc, &pioche[i].valeur);
    }

    //affichePioche(pioche);

}

void affichePioche(lettre pioche[TAILLE_PIOCHE]) //affichage de la pioche
{
    int i;
    printf("\n");
    for(i=0; i<TAILLE_PIOCHE; i++)
    {
        printf("%c %d %d\n", pioche[i].nom, pioche[i].nbOcc, pioche[i].valeur);
    }
    printf("\n");
}

int verifPioche() // verification qu'il y a toujours des lettres dans la pioche
{
    int cpt =0;
    for(i=0; i<TAILLE_PIOCHE; i++)
    {
        if(pioche[i].nbOcc <=0)
        {
            cpt++;
        }
    }
    if( cpt == 26) return 1;
    else return 0;
}

void creerChevalet(char chevalet[TAILLE_CHE], int j) //cr�ation du chevalet de 7 lettres avec des lettres pioch�es au hasard parmis les 26+le jocker
{
    srand(time (NULL));

    int i, k;
    for (k = 0; k<7 ; k++)
    {
        i = rand()%27+1;
        if((pioche[i].nbOcc) == 0)
        {
            while(pioche[i].nbOcc < 1)
            {
                i = rand()%27+1;
                tabJ[j].chevalet[k] = pioche[i].nom;
                //chevalet[k].valeur = pioche[i].valeur;
                pioche[i].nbOcc--;
            }
        }else{
            tabJ[j].chevalet[k] = pioche[i].nom;
            //chevalet[k].valeur = pioche[i].valeur;
            pioche[i].nbOcc--;
        }

    }
    //recherche des lettres identiques dans le chevalets

    /*
    for(k = 0; k<7; k++)
    {
        //chevalet[k].nbOcc =0;
        for(j = 0; j<7;j++)
        {
            if(chevalet[k].nom == chevalet[j].nom)
            {
                chevalet[k].nbOcc = chevalet[k].nbOcc+1;
                //suppCase(chevalet, j);
            }
        }
        printf("%c ",  chevalet[k]);
    }*/
    //affichePioche(pioche);
}

//
void piocher(char chevalet[TAILLE_CHE],int k, int j) //action de piocher une lettre au hasard parmis les 26+le jocker et verification que la lettre existe toujours
{
    srand(time (NULL));

    int i;

    do{
        i = rand()%27+1;
        tabJ[j].chevalet[k] = pioche[i].nom;
        //chevalet[k].valeur = pioche[i].valeur;
        pioche[i].nbOcc--;
    }while(pioche[i].nbOcc < 1);

}


void suppCase(char chevalet[TAILLE_CHE], int j) // supressin de la case et remplacement par un espace en cas d'utlisiation de la lettre
{
   chevalet[j] = ' ';
}

void majChevalet(char chevalet[TAILLE_CHE], char mot[TAILLE_MOT], int idjoueur)
{ //mise � jour du chevalet
    int i, j;
   // int tmp;
    int lg= strlen(mot);

    //Suppression des lettes utilis�es dans le chevalet
    for( i = 0; i < lg; i++)
    {
        for(j=0; j< TAILLE_CHE ; j++)
        {
            if(mot[i] == chevalet[j])
            {
                chevalet[j] = ' ';
                //suppCase(chevalet, j);
                //tmp++;
            }
        }
    }

    for( i = 0; i<TAILLE_CHE;i++)
    {
        if(chevalet[i] == ' '){
            piocher(chevalet,i,idjoueur );
        }
    }

}

int scoreLettre(char c) // score des lettres si pioche[i].valeur ne fonctionne pas
{
    int valeur;

    if( c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i'|| c == 'L' || c == 'l' || c == 'N'|| c == 'n'
       || c == 'O' || c == 'o' || c == 'R' || c == 'r' || c == 'S' || c == 's' || c == 'T' || c == 't' || c == 'U' || c == 'u')
    {
        valeur = 1;

    }else if( c == 'D' || c == 'd' || c == 'G' || c == 'g' || c == 'M'|| c == 'm')
    {
        valeur = 2;

    }else if( c == 'B' || c == 'b' || c == 'C' || c == 'c' || c == 'P' || c == 'p')
    {
        valeur = 3;

    }else if( c == 'F' || c == 'f' || c == 'H' || c == 'h' || c == 'V' || c == 'v')
    {
        valeur = 4;

    }else if( c == 'J' || c == 'j'|| c == 'Q' || c == 'q')
    {
        valeur = 8;

    }else if( c == 'K' || c == 'k' || c == 'W' || c == 'w' || c == 'X' || c == 'x'
             || c == 'Y' || c == 'y' || c == 'Z'|| c == 'z')
    {
        valeur = 10;

    }else if (c == '?')
    {
        valeur = 0;
    }

    return valeur;
}

int bonusMot( int ligne, int colonne) //bonus avec mot compte double et triple
{
   // int bonusMot;


//- Case � = mot compte triple
        if ((ligne == 0 && colonne == 0)||(ligne == 0 && colonne == 7)||(ligne == 0 && colonne == 14)||(ligne == 7 && colonne == 0)||(ligne == 14 && colonne == 0)||(ligne == 14 && colonne == 7)||(ligne == 14 && colonne == 14)||(ligne == 7 && colonne == 14))
            return 3;

//- Case @ = mot compte double
        if ((ligne == 1 && colonne == 1)||(ligne == 2 && colonne == 2)||(ligne == 4 && colonne == 4)||(ligne == 3 && colonne == 3)||(ligne == 4 && colonne == 10)||(ligne == 1 && colonne == 13)||(ligne == 2 && colonne == 12)||(ligne == 3 && colonne == 11)||(ligne == 10 && colonne == 4)||(ligne == 12 && colonne == 2)||(ligne == 13 && colonne == 1)||(ligne == 10 && colonne == 10)||(ligne == 11 && colonne == 3)||(ligne == 11 && colonne == 11)||(ligne == 12 && colonne == 12)||(ligne == 13 && colonne == 13))
            return 2;
        else
            return 0;

    //return bonusMot;
}

int bonusLettre( int ligne, int colonne) //bonus lettres
{
    //int bonusLettre;

//- Case & = lettre compte double
        if ((ligne == 3 && colonne == 0)||(ligne == 6 && colonne == 2)||(ligne == 0 && colonne == 3)||(ligne == 2 && colonne == 6)||(ligne == 6 && colonne == 6)||(ligne == 2 && colonne == 8)||(ligne == 3 && colonne == 7)||(ligne == 6 && colonne == 8)||
            (ligne == 0 && colonne == 11)||(ligne == 6 && colonne == 12)||(ligne == 3 && colonne == 14)||(ligne == 8 && colonne == 2)||(ligne == 7 && colonne == 3)||(ligne == 11 && colonne == 0)||(ligne == 8 && colonne == 6)||(ligne == 12 && colonne == 6)||
            (ligne == 14 && colonne == 3)||(ligne == 8 && colonne == 8)||(ligne == 11 && colonne == 7)||(ligne == 12 && colonne == 8)||(ligne == 7 && colonne == 11)||(ligne == 8 && colonne == 12)||(ligne == 14 && colonne == 11)||(ligne == 11 && colonne == 14))
        {
            return 2;
        }

//- Case % = lettre compte triple
        if ((ligne == 5 && colonne == 1)||(ligne == 5 && colonne == 5)||(ligne == 1 && colonne == 5)||(ligne == 1 && colonne == 9)||(ligne == 5 && colonne == 9)||(ligne == 5 && colonne == 13)||(ligne == 9 && colonne == 13)||(ligne == 13 && colonne == 9)||(ligne == 13 && colonne == 5)||(ligne == 9 && colonne == 5)||(ligne == 9 && colonne == 1)||(ligne == 9 && colonne == 9))
           {
               return 3;
           }

        else
        {
            return 0;
        }
    //return bonusLettre;
}

int calculScore(char tab[TAILLE_TAB][TAILLE_TAB], char mot[TAILLE_MOT], int ligne, int colonne, char sens)
{ //calcul du score
    int lg = strlen(mot);
    int k, p;
    int bLettre[lg];
    int bMot[lg];
    int c = colonne;
    int l = ligne;
    int score = 0;


//R�cup�ration des bonus en fonctions de l'emplacement des lettres
    if( sens == 'h' || sens == 'H')
    {
        for(k=0; k<lg ; k++)
        {
            //printf("BL %d BM %d", bonusLettre(l,c), bonusMot(l, c));
            bLettre[k] = bonusLettre(l, c);
            bMot[k] = bonusMot(l, c);
            c++;
            //printf(" lettre h: %d ", bLettre[k]);
            //printf(" mot h: %d ", bMot[k]);
        }
         printf("\n");
    }

    else if( sens == 'v' || sens == 'V')
    {
        for(k=0; k<lg ; k++)
        {
            bLettre[k] = bonusLettre( l, c);
            bMot[k] = bonusMot( l, c);
            l++;
            //printf("lettre v %d ", bLettre[k]);
            //printf("mot v%d ", bMot[k]);
        }

    }

    //Calcul le score du mot en ajoutant lesbonus lettres au fur et � mesure du parcours du mot
    for(k = 0; k< lg ; k++)
    {
        for(p =0; p<TAILLE_PIOCHE; p++)
        {
            if( mot[k] == pioche[p].nom && bLettre[k] != 0)
            {
                score = score + (pioche[p].valeur)*bLettre[k];
            }
            else if(mot[k] == pioche[p].nom)
            {
                score = score + pioche[p].valeur;
            }
        }
    }

    for(k = 0; k< lg ; k++)
    {
        if(bMot[k] != 0)
            score = score* bMot[k];
    }

    return score;
}
/*
int bonus(char tab[TAILLE_TAB][TAILLE_TAB], char mot[TAILLE_MOT], int ligne, int colonne, char sens)
{
    int taillemot = strlen(mot);
    int i=0;
    int scoreM;
    int scoreL;
    int bonusMot;
    int bonusLettre;
 //   int resultat;

    for (i=0; i<taillemot; i++)
    {

//- Case � = mot compte triple
        if (tab[0][0]||tab[0][7]||tab[0][14]||tab[7][0]||tab[14][0]||tab[14][7]||tab[14][14]||tab[7][14])
            bonusMot=3;

//- Case @ = mot compte double
        if (tab[1][1]||tab[2][2]||tab[4][4]||tab[3][3]||tab[4][10]||tab[1][13]||tab[2][12]||tab[3][11]||tab[10][4]||tab[12][2]||tab[13][1]||tab[10][10]||tab[11][3]||tab[11][11]||tab[12][12]||tab[13][13])
            scoreM=scoreM*2;

//- Case & = lettre compte double
        if (tab[3][0]||tab[6][2]||tab[0][3]||tab[2][6]||tab[6][6]||tab[2][8]||tab[3][7]||tab[6][8]||
            tab[0][11]||tab[6][12]||tab[3][14]||tab[8][2]||tab[7][3]||tab[11][0]||tab[8][6]||tab[12][6]||
            tab[14][3]||tab[8][8]||tab[11][7]||tab[12][8]||tab[7][11]||tab[8][12]||tab[14][11]||tab[11][14])
            scoreL=scoreL*2;

//- Case % = lettre compte triple
        if (tab[5][1]||tab[5][5]||tab[1][5]||tab[1][9]||tab[5][9]||tab[5][13]||tab[9][13]||tab[13][9]||tab[13][5]||tab[9][5]||tab[9][1]||tab[9][9])
            scoreL=scoreL*3;
    }
    return 0;
}
*/
