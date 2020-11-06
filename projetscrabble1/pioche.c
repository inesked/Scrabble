#include "header.h"
#define TAILLE_TAB 15



void creerPioche()
{
    int i;
    FILE *file;
    file = fopen("lettre.txt", "r");

    if(file==NULL){
        printf("Pb ouverture du fichier lettre.txt\n");
	}



	for(i=0; i<TAILLE_PIOCHE; i++)
    {
        fscanf(file, "%c %d %d\n", &pioche[i].nom, &pioche[i].nbOcc, &pioche[i].valeur);
    }

    affichePioche(pioche);

}

void affichePioche(lettre pioche[TAILLE_PIOCHE])
{
    int i;
    printf("\n");
    for(i=0; i<TAILLE_PIOCHE; i++)
    {
        printf("%c %d %d\n", pioche[i].nom, pioche[i].nbOcc, pioche[i].valeur);
    }
    printf("\n");
}

int verifPioche()
{
    int cpt =0;
    for(i=0; i<TAILLE_PIOCHE; i++)
    {
        if(pioche[i].nbOcc <=0)
        {
            cpt++;
        }
    }
    if( cpt == 27) return 1;
    else return 0;
}

void creerChevalet(char chevalet[TAILLE_CHE], int j)
{
    srand(time (NULL));

    int i, k;
    for (k = 0; k<7 ; k++)
    {
        i = rand()%27+1;
        if((pioche[i].nbOcc) = 0)
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
    affichePioche(pioche);
}

void piocher(char chevalet[TAILLE_CHE])
{
    srand(time (NULL));

    int i;

    do{
        i = rand()%27+1;
        tabJ[j].chevalet[7] = pioche[i].nom;
        //chevalet[k].valeur = pioche[i].valeur;
        pioche[i].nbOcc--;
    }while(pioche[i].nbOcc < 1);

}



void suppCase(char chevalet[TAILLE_CHE], int j)
{
    int i;

    for(i= j-1; i<7; i++)
    {
        chevalet[i] = chevalet[i+1];
    }
}

int scoreLettre(char c)
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

int scoreMot(char tab[TAILLE_TAB][TAILLE_TAB], char mot[TAILLE_MOT])
{
    int taillemot = strlen(mot);
    int i=0;
    int scoreM;
    int scoreL;
 //   int resultat;

    for (i=0; i<taillemot; i++)
    {

//- Case § = mot compte triple
        if (tab[0][0]||tab[0][7]||tab[0][14]||tab[7][0]||tab[14][0]||tab[14][7]||tab[14][14]||tab[7][14])
            scoreM=scoreM*3;

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

