#ifndef SHOP_H
#define SHOP_H

#include <pthread.h>

#define NUM_SHOPS 5
#define NUM_CUSTOMERS 3
#define MAX_NEED 100000
#define MIN_PRODUCTS 9000
#define MAX_PRODUCTS 10000
#define MAX_STOCK 5000

typedef struct {
    int id; 
    int stock; 
} Shop;

void output_customer_info(int id, int need, int shop_id, int purchase, int remaining_need);
void output_loader_info(int shop_id, int current_stock, int products_added);
int random_number(int min, int max);
void initialize_shops();
void output_initial_stock();
void output_program_end();
void* customer(void* arg);
void* loader(void* arg);

#endif
