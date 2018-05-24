#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


//przyjmuje i zwraca wskaznik na voida
void* nazwa_funkcja(void* cos)
{
    
    return NULL;
}

int main()
{
    pthread_t watek; //tworzymy zmienna przechowujaca dane watka opcjonalnie tablice tych watkow tab[20]
    
    //podajemy adres watku (tej zmiennej) i nazwe funkcji ktora ma wykonac watek;
    pthread_creat(&watek,NULL,nazwa_funkcja,NULL);
    
    //podajemy zmienna przechowujaca watek, oczekiwanie na zakonczenie watka
    pthread_join(watek,NULL);
        
    
    return 666;
}
