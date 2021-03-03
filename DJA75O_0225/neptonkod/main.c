#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nev[] = {"Szûcs Attila"};
    char szak[] = {"Mernok Informatika"};
    char neptunkod[] = {"DJA75O"};
    char szuletesi_datum[] = {"1999.03.17"};

    printf("Ki irasra kerult adatok:\n Nev:%s\n Szak:%s\n Neptunkod:%s\n Szuletesi datum:%s", nev, szak, neptunkod, szuletesi_datum);


    FILE* fp;
    fp = fopen("vezeteknev.txt", "w");

    if(fp != NULL)
    {
        fprintf(fp, "Nev\t\tSzak\t\tNeptunkod\tSzuletesi datum");

        fprintf(fp, "\n%s\t", nev);
        fprintf(fp, "%s\t", szak);
        fprintf(fp, "%s\t", neptunkod);
        fprintf(fp, "%s\t", szuletesi_datum);

        fclose(fp);
    }
    else
    {
        perror("Nem sikerult megnyitni a fajlt");
    }

    FILE* fr;
    fr = fopen("vezeteknev.txt", "r");

    char sor[100];
    int i;
    for(i=0; i<=100; i++)
    {
        fgets(sor, 100, fr);
    }

    printf("\n\n%s\n", sor);
    fclose(fr);

    return 0;
}
