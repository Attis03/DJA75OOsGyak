#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid=fork();
    int i;

    if(pid == 0)
    {
        for (i = 0; i < 5; i++)
        {
            int status = system("./child");
            printf("\n");
        }
        
        exit(127);
    }
    else
    {
        waitpid(pid,0,0);
    }

    return 0;
}