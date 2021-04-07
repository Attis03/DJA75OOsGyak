#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t cpid;
    cpid = fork();

    if(cpid < 0)
    {
        printf("Sikertelen rendszer hívás!");
    }
    else if(cpid == 0)
    {
        for (alarm(20); pause() != SIGALRM;);
    }
    else
    {
        exit(1);
    }

    return 0;
}