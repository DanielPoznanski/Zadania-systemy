#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int zmienna=0;

void *funkcja_watek(void *nazwa){
    for(int i = 0 ; i<10 ; i++){
        zmienna++;
    }
}


int main(){
    pthread_t watki[20];
    for(int i = 0 ; i<20 ; i++){
        pthread_create(&watki[i],NULL,funkcja_watek,NULL);
    }
    for(int i = 0 ; i<20 ; i++){
      //  pthread_join(watki[i],NULL);
        
    }
    
        printf("%i\n",zmienna);
        return 0 ; 
    
    
    
}
