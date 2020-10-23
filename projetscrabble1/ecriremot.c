#include <stdio.h>
#include <stdlib.h>

int ecriremot()
{
    printf("\n entrez les 7 lettres piochees\n");
    FILE * fp;

    int i=0;
    char lettrepiochee;

    fp = fopen("chevalet.txt", "w");

    for(i=0; i<14; i++)
    {
        scanf("%c", &lettrepiochee);
        fprintf(fp, "%c", lettrepiochee);
    }
    fclose(fp);
    return 0;
}
