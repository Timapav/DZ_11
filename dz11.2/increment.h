#ifndef INCREMENT_H
#define INCREMENT_H

#include <pthread.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 1000000

extern int counter; 
extern pthread_mutex_t mutex; 

void *increment_loop(void *arg);

#endif /* INCREMENT_H */
