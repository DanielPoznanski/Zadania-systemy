#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct zadanie3{
  long typ; //zawsze typ to long
  int wiadomosc; // int bo wysylamy pid
};


int main () {
    struct zadanie3 obiekt;
 int que=msgget(545,IPC_CREAT | 0666); //tworzenie kolejki (identyfikator , flaga tworzenia kolejki | prawa dostepu ) 
 int a = fork();
 if(a == 0 ) {
     obiekt.typ = 1;
     obiekt.wiadomosc = getpid();
    msgsnd(que,&obiekt,sizeof(int),0); // wyslanie komunikatu (nazwa kolejki , adres obiektu ktory wysylamy , wielkosc wiadmosci , 0 )
     
     
 }
 
 else{
     a=fork();   
      if(a==0){
          obiekt.typ = 2;
          obiekt.wiadomosc = getpid();
          msgsnd(que,&obiekt , sizeof(int),0);
          
      }
      else{
          msgrcv(que,&obiekt,sizeof(int),0,0);
          printf("%i\n",obiekt.wiadomosc);
          msgrcv(que,&obiekt,sizeof(int),0,0);
          printf("%i\n",obiekt.wiadomosc);
      }
      
     
     
 }
    return 0;
    
}
