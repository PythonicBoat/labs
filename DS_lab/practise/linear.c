#include <stdio.h>

void linear(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found\n");
}

void main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    linear(arr, n, 3);
    linear(arr, n, 6);
}
