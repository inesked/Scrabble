#include "header.h"
#define TAILLE_GRILLE 15
#define TAILLE_CEL 2
#define TAILLE_TAB 15


/**
    Initialistion du plateau de jeu avec
    - la grille
    - le tableau de tableau
**/
void dessinerGrille(int tailleTab, int tailleCel, char tab[TAILLE_TAB][TAILLE_TAB])
{
    int i, j;
    int total = (tailleTab * tailleCel)+1;
    char c;

    printf("\n");
    printf("  A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\n");
    for(i=0 ; i<(total) ; i++)
    {
       // printf("%d", i);
        for(j=0 ; j<(total); j++)
        {
            if(i% tailleCel == 0 || j% tailleCel == 0)
            {
                c ='.';
            }
            else
            {

                c = tab[(i/2)][(j/2)];

            }

               // printf(" ");
                //printf("%c", grille[i][j]);

            printf("%c ", c);
        }
        printf("\n");
    }
}

/**
    Initialisation du tableau avec les caractères spéciaux
**/

void initTableau(char tab[TAILLE_TAB][TAILLE_TAB])
{
    int i, j;
    for(i= 0; i< TAILLE_TAB; i++)
    {
        for(j =0; j< TAILLE_TAB; j++){
            tab[i][j] = ' ';
        }
    }

    //A                   B                   C                   D                   E                   F                   G
    tab[0][0] ='§';     tab[1][1] = '@';    tab[2][2] = '@';    tab[3][0] = '&';    tab[4][4] = '@';    tab[5][1] = '%';    tab[6][2] = '&';
    tab[0][3] = '&';    tab[1][5] = '%';    tab[2][6] = '&';    tab[3][3] = '@';    tab[4][10] = '@';   tab[5][5] = '%';    tab[6][6] = '&';
    tab[0][7] = '§';    tab[1][9] = '%';    tab[2][8] = '&';    tab[3][7] = '&';                        tab[5][9] = '%';    tab[6][8] = '&';
    tab[0][11] = '&';   tab[1][13] = '@';   tab[2][12] = '@';   tab[3][11] = '@';                       tab[5][13] = '%';   tab[6][12] = '&';
    tab[0][14] = '§';                                           tab[3][14] = '&';


    //H                 I                   J                   K                   L                   M                   N                   O
    tab[7][0] = '§';     tab[8][2] = '&';    tab[9][1] = '%';    tab[10][4] = '@';   tab[11][0] = '&';   tab[12][2] = '@';   tab[13][1] = '@';    tab[14][0] ='§';
    tab[7][3] = '&';    tab[8][6] = '&';    tab[9][5] = '%';    tab[10][10] = '@';  tab[11][3] = '@';   tab[12][6] = '&';   tab[13][5] = '%';    tab[14][3] = '&';
    tab[7][7] = '#';    tab[8][8] = '&';    tab[9][9] = '%';                        tab[11][7] = '&';   tab[12][8] = '&';   tab[13][9] = '%';    tab[14][7] = '§';
    tab[7][11] = '&';   tab[8][12] = '&';   tab[9][13] = '%';                       tab[11][11] = '@';  tab[12][12] = '@';  tab[13][13] = '@';   tab[14][11] = '&';
    tab[7][14] = '§';                                                               tab[11][14] = '&';                                           tab[14][14] = '§';

}
