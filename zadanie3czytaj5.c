#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
    int pajp[2];
    pipe(pajp);
    char buf[20];
 int a = fork();
 
 if ( a ==0 ) {
     int olpen = open("plik.txt",O_RDONLY);
     read(olpen,buf,20);
     close (olpen);
     close(pajp[0]);
     write (pajp[1],buf,20);
     close (pajp[1]);
     
 }
 else {
     a = fork();
     if (a == 0 ){
     creat("plik2.txt",0666);
     close(pajp[1]);
     read (pajp[0],buf,20);
     close (pajp[0]);
     int olpen = open("plik2.txt",O_WRONLY);
     write(olpen,buf,20);
     close (olpen);
         
     }
    
    
}
}
