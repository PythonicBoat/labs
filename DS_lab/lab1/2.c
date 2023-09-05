// Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using call by address and de-allocate the memory of the array after its use.
// Sample Input/Output:
// Enter size of the array: 5
// Enter array elements: 3  9  7  4  8
// Sum =10

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void sumOfPrimes(int *arr, int size, int *sum) {
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            *sum += arr[i];
        }
    }
}

int main() {
    int size, *arr, sum = 0;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    arr = (int *) malloc(size * sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    sumOfPrimes(arr, size, &sum);
    printf("Sum = %d\n", sum);
    free(arr);
    return 0;
}