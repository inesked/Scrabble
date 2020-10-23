#include <stdio.h>
#include <stdlib.h>



int ecriremot()
{
    //chevalet
    printf("\n entrez les 7 lettres piochees\n");
    FILE * fp;

    int i=0;
    char lettrechevalet;

    fp = fopen("chevalet.txt", "w");

    for(i=0; i<14; i++)
    {
        scanf("%c", &lettrechevalet);
        fprintf(fp, "%c", lettrechevalet);
    }
   /* fclose(fp);
    return 0;*/


    //pioche
    printf("\n verification de l'accès à la pioche : \n");
//    FILE * fp;
    //lire un txt avec lettre, occurence et valeure
    int j=0;
    char lettrepiochee;

    fp = fopen("pioche.txt", "w");

    /*for(i=0; i<14; i++)
    {
        scanf("%c", &lettrepiochee);
        fprintf(fp, "%c", lettrepiochee);
    }*/
    fprintf(fp, "%c", lettrepiochee);
    fclose(fp);
    return 0;
}
