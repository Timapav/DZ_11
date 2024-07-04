#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "shop.h"

int main() {
    srand(time(NULL));
    initialize_shops(); 
    output_initial_stock();

    pthread_t customers[NUM_CUSTOMERS]; 
    pthread_t loader_thread; 

    int customer_ids[NUM_CUSTOMERS];
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        customer_ids[i] = i + 1;
        pthread_create(&customers[i], NULL, customer, &customer_ids[i]); 
    }

    pthread_create(&loader_thread, NULL, loader, NULL); 

    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        pthread_join(customers[i], NULL); 
    }

    pthread_cancel(loader_thread); 
    output_program_end(); 

    return 0;
}
