#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  mkfifo("KOLEJKA_FIFO",0666);
    int a=fork();
    if(a==0) {
        char buf[10];
        sprintf(buf,"%i",getpid());
        int id=open("KOLEJKA_FIFO",O_WRONLY);
        write(id,buf,sizeof(buf));
        close(id);
    }
    else{
    a=fork();
        if(a==0){
            char buf[10];
            sprintf(buf,"%i",getpid());
            int id= open("KOLEJKA_FIFO",O_WRONLY);
            write(id,buf,sizeof(buf));
            close(id);
        }
        else{
            char buf[10];
            int id = open("KOLEJKA_FIFO",O_RDONLY);
            read(id,buf,sizeof(buf));
          
            puts(buf);
            read(id,buf,sizeof(buf));
            puts(buf);
          close(id);  
        }
        
    }
    
    
}
