#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main () {
 //potoki pipe   
 int tablica [2];
 pipe(tablica);
 int a = fork();
 
 if(a == 0 ) {
     close (tablica[0]);
  write(tablica[1],"Prepare to Die " , 20);   
     close (tablica[1]);
 }
 
 
 else{
     char buf[20];
     close (tablica[1]);
     read(tablica[0],buf,20);
     close (tablica[0]);
     puts(buf);
     
 }
 
    
    
    
    
    
}
