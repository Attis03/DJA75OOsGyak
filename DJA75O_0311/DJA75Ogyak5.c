#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void exit(int status);
void abort(void);

int main()
{
    pid_t pid = fork();
    int status;

    //status
    if ((pid = fork()) < 0)
    {
        perror("fork hiba!");
    }
    else if(pid == 0)
    {
        exit(7);
    }

    if(wait(&status) != pid)
    {
        perror("varakozasi hiba!");
    }

    if(WIFEXITED(status))
    {
        printf("Normalisan befejezodot\nvisszaadott ertek: %d\n", WEXITSTATUS(status));
    }

    //abort
    if((pid = fork() < 0))
    {
        perror("fork hiba!");
    }
    else if (pid == 0)
    {
        abort();
    }

    if(wait(&status) != pid)
    {
        perror("varakozasi hiba!");
    }

    if (WIFSIGNALED(status))
    {
        printf("Abnormalis befejezodes\nA sziganal sorszama: %d\n", WTERMSIG(status));
    }

    //nullával való osztás
    if ((pid = fork()) < 0)
    {
        perror("fork hiba!");
    }
    else if(pid == 0)
    {

    }

    if(wait(&status) != pid)
    {
        perror("varakozasi hiba!");
    }

    if (WIFSIGNALED(status))
    {
        printf("Abnormalis befejezodes\nA sziganal sorszama: %d\n", WTERMSIG(status));
    }
    


    return 0;
}