#include <stdio.h>
#include <limits.h>

int main() {
    int n = 5;
    int arr[100] = {1, 2, 3, 4, 5};
    int smallest, ss, largest, sl;

    smallest = INT_MAX;
    ss = INT_MAX;
    largest = INT_MIN;
    sl = INT_MIN;

    // Find the smallest and largest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Find the second smallest and second largest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > smallest && arr[i] < ss) {
            ss = arr[i];
        }
        if (arr[i] < largest && arr[i] > sl) {
            sl = arr[i];
        }
    }

    printf("Second smallest: %d\n", ss);
    printf("Second largest: %d\n", sl);

    return 0;
}