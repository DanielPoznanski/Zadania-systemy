#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


int x = 51 ; 

void *funkcja_watek(void *nazwa){
for(int i = 0 ; i<50;i++){
    if(x%2==0)  x+=3;

}return NULL;
}

void *funkcja2_watek(void *nazwa){
    for(int i = 0 ; i<50 ; i++){
    x++;}
return NULL;
    
}
int main(){

pthread_t watki[12];
for(int i = 0 ; i <6 ; i ++){
    pthread_create(&watki[i],NULL,funkcja_watek,NULL);
}
for(int i = 6;i<12;i++){
    
 pthread_create(&watki[i],NULL,funkcja2_watek,NULL);   
}
sleep(1);
    printf("%i\n",x);


}






    
    
    
