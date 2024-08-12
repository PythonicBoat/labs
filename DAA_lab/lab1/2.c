// Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

#include <stdio.h>

void prefixSum(int arr[], int prefixSum[], int N) {
    prefixSum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[N];

    prefixSum(arr, prefixSum, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", prefixSum[i]);
    }

    return 0;
}
