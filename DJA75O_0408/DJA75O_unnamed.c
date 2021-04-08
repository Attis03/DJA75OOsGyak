#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    int szam;
    char buf;

    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(EXIT_SUCCESS);
    }

    if(fork() == 0)
    {
        write(fd[0], "Szucs Attila DJA75O", 17);

        close(fd[0]);

        exit(EXIT_SUCCESS);
    }

    while(read(fd[1], &buf, 1) > 0 )
    {
        printf("%c", buf);
    }

    close(fd[1]);

    printf("\n");

    exit(EXIT_SUCCESS);
}