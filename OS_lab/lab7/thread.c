#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int numbers[] = {1, 2, 3, 4, 5}; 
int sum = 0; 
int product = 1; 

void *thread_1(void *arg) {
    int partial_sum = 0;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        partial_sum += numbers[i];
    }
    sum = partial_sum; 
    pthread_exit(NULL);
}

// Function for thread 2 to calculate the product
void *thread_2(void *arg) {
    int partial_product = 1;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        partial_product *= numbers[i];
    }
    product = partial_product; // Assigning partial product to global product
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; 
    int rc;
    rc = pthread_create(&threads[0], NULL, thread_1, NULL);
    if (rc) {
        fprintf(stderr, "Error creating thread 1 for sum calculation\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&threads[1], NULL, thread_2, NULL);
    if (rc) {
        fprintf(stderr, "Error creating thread 2 for product calculation\n");
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
