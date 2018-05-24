#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct zadanie{
 long typ;
 int wiadomosc;
};



int main () {
  struct zadanie obiekt;  
  int a  = fork();
  if (a == 0 ) {
       int que = msgget(123123,0666); 
      for(int i = 0 ; i <= 500 ; i+=4){
      obiekt.wiadomosc = i;
      obiekt.typ = 2 ;
      msgsnd(que,&obiekt,sizeof(int),0);    
    }
   a=fork();
    if (a==0 ) {
        int que = msgget(123123,0666); 
        for(int i =0 ; i<=1000 ; i+=5){
         obiekt.wiadomosc = i ; 
         obiekt.typ=1;
         msgsnd(que,&obiekt,sizeof(int),0);
            
            
        }
        
    }

  }
  
  else {
       int que = msgget(123123,IPC_CREAT | 0666); 
       for(int i = 0 ; i<=1000;i+=5){
       msgrcv(que,&obiekt,sizeof(int),1,0);
       printf ( "%i\n" , obiekt.wiadomosc);
       fflush(stdout);
       }
       
      
      
  }
    
    return 0;
    
    
}
