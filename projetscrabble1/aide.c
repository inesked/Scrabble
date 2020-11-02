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
