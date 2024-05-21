#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int numbers[] = {1, 2, 3, 4, 5}; 
int sum = 0; 
int product = 1; 

void *calculate_sum(void *arg) {
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        sum += numbers[i];
    }
    pthread_exit(NULL);
}

void *calculate_product(void *arg) {
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        product *= numbers[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; 
    int rc;
    rc = pthread_create(&threads[0], NULL, calculate_sum, NULL);
    if (rc) {
        fprintf(stderr, "Error creating thread for sum\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&threads[1], NULL, calculate_product, NULL);
    if (rc) {
        fprintf(stderr, "Error creating thread for product\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}
