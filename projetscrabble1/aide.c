#include "header.h"

void aide()
{
    FILE *fichier =NULL;
    char mot[TAILLE_MAX] = "";
    //int i;
    fichier = fopen("aide.txt", "r"); // r pour read
    if (fichier != NULL)
    {
        while (fgets(mot, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", mot); // On affiche la chaîne qu'on vient de lire
        }

        fclose(fichier);
    }

}

  /*
    0 : Noir
    1 : Bleu fonc�
    2 : Vert fonc�
    3 : Turquoise
    4 : Rouge fonc�
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris fonc�
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
    */

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/*
    Color(12,3);
    printf("Le texte va avoir la couleur 12 et le Fond la couleur 3\n");
*/
