#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main () {
    int a = shmget(123123,20*sizeof(int),IPC_CREAT | 0666); //shmget(liczby , rozmiar sizeof*ilosc,IPC_CREAT | 0666)
    int b = fork();
    if (b == 0 ) {
     int *tab = shmat(a,NULL,0); // wskaznik na tablice szmat   
     tab[0]=45;
     tab[1]=546;
     
     shmdt(tab);   
    }
    
    else {
       int *tab=shmat(a,NULL,0);
       sleep(1);
       printf("%i , %i" , tab[0],tab[1]);
        shmdt(tab);
        shmctl(a,IPC_RMID , NULL ); //id , IPC_RMID , NULL
    }
    
    
    
    
}
