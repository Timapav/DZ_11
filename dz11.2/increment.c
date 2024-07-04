#include "increment.h"
#include <stdio.h>

void *increment_loop(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex); 
        counter++; 
        pthread_mutex_unlock(&mutex); 
    }
    pthread_exit(NULL);
}
