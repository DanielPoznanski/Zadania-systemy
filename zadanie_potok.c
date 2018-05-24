#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
int tab[2];
pipe(tab);
int a = fork () ;
if(a == 0 ) {
    char buf[12];
    close(tab[1]);
    read(tab[0],buf,12);
    puts(buf);
    close(tab[0]);
    
}

else {
    close (tab[0]);
    write (tab[1],"WITAJ CHUJU",12);
    close ( tab[1]);
    
    
}




    
}
