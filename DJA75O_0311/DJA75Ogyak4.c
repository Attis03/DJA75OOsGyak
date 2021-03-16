#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(argc, argv, envp)
int argc;
char **argv, **envp;
{
    int eredmeny;

    if(fork() == 0)
    {
        execle("/bin/ls","ls","-l",(char *)0,envp);
    }
    else
    {
        wait(&eredmeny);
    }

    return 0;
}