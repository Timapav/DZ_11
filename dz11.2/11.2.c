#include <stdio.h>
#include <pthread.h>
#include "increment.h"

int counter = 0; 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t = 0; t < NUM_THREADS; t++) {
        printf("Создание потока %ld\n", t);
        rc = pthread_create(&threads[t], NULL, increment_loop, NULL);
        if (rc) {
            printf("Ошибка: Невозможно создать поток %ld\n", t);
            return -1;
        }
    }

    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Значение counter после выполнения всех потоков: %d\n", counter);

    return 0;
}
