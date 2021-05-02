#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 

int main() 
{ 
    int child; 
    
    mkfifo("named", S_IRUSR | S_IWUSR ); 
    
    child = fork(); 
    
    if(child > 0) 
    { 
        char s[19]; 
        int fd; 
        fd = open("named", O_RDONLY); 
        read(fd, s, sizeof(s)); 
        printf("%s", s); 
        close(fd); 
        unlink("named"); 
    } else if(child == 0) { 
        int fd;
        fd = open("named", O_WRONLY); 
        write(fd, "Szűcs_Attila_DJA75O\n", 19); 
        close(fd); 
    } 
    
    return 0; 
}