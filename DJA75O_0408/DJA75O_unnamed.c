#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
  
int main()
{
    int fd2[2];
  
    pid_t p;
  
    if (pipe(fd2)==-1)
    {
        fprintf(stderr, "Pipe hiba" );
        return 1;
    }
  
    p = fork();
  
    if (p < 0)
    {
        fprintf(stderr, "fork hiba" );
        return 1;
    }
    else if (p > 0)
    {
        //szülő procesz
        char str[19];
  
        close(fd2[1]);

        read(fd2[0], str, 19);
        printf("%s\n", str);
        close(fd2[0]);
    }
    else
    {
        //gyerek procesz
        char str[] = "Szűcs_Attila_DJA75O";

        close(fd2[0]);
  
        write(fd2[1], str, strlen(str)+1);
        close(fd2[1]);
  
        exit(0);
    }
}