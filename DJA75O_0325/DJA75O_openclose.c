#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fileHandle = open("DJA75O.txt", O_RDWR);
    char szoveg[38];

    if(fileHandle == -1)
    {
        perror("A fajl megnyitasa sikertelen volt!");
        return 1;
    }
    else
    {
        printf("A fajl megnyitasa sikeres volt!");
    }

    int o = read(fileHandle, szoveg, sizeof(szoveg));
    szoveg[o] = '\0';

    printf("A beolvasott file tartalma: %s\n", szoveg);
    printf("A file-ban levo szoveg merete: %i byte\n", o);

    lseek(fileHandle, 0, SEEK_SET);

    char szoveg2[] = "proba";
    int i = write(fileHandle, szoveg2, sizeof(szoveg2));

    close(fileHandle);

    return 0;
}