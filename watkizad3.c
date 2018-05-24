#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funkcja_watek(void *nazwa){
 for(int i = 60 ; i>0 ; i--){
     printf("%i\n",i);
     sleep(1);
     fflush(stdout);
 }
 return NULL;
}
int main(){
    puts("Uruchamianie , Czekaj ! ");
    pthread_t watek;
    pthread_create(&watek, NULL , funkcja_watek , NULL);
    pthread_join(watek,NULL);
    
    
    
}
