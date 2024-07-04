#include <stdio.h>
#include <pthread.h>
#include "threads.h"

#define NUM_THREADS 5

int main() {
    pthread_t threads[NUM_THREADS]; 
    int rc; 
    long t; 

    for(t = 0; t < NUM_THREADS; t++) {
        printf("Создание потока %ld\n", t);
        
        rc = pthread_create(&threads[t], NULL, print_index, (void *)t);
        if (rc) {
            
            printf("Ошибка: Невозможно создать поток %ld\n", t);
            return -1;
        }
    }

    
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL); 
}
