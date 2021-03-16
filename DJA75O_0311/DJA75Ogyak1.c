#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char parancs[20];

    printf("Adjon meg egy Unix parancsot\n");
    scanf("%s", parancs);

    int system(const char *parancs);

    if(system(parancs))
    {
        printf("A paracs nem létezik!");
    }
    else
    {
        printf("A paracs létezik!");
    }

    return 0;
}
