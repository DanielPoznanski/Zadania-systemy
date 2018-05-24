#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc,char *argv[]){
    int tab[2];
    pipe(tab);
    int a = fork();
    char buf[100];
    
    if(a== 0 )
    {
        close (tab[0]);
        write(tab[1],argv[1],strlen(argv[1])+1);
        close (tab[1]);
    }
    else{
        close(tab[1]);
        read(tab[0],buf,100);
        close(tab[0]);
        puts(buf);
        
    }
    
    
    
}
