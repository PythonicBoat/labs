// 12.1 Write a program to sort array of n elements in ascending and descending order by bubble sort using function.
// Sample Input/Output
// Enter no.of elements: 5
// Enter elements: 21  15  32  18  45
// Ascending order: 15   18   21  32  45
// Descending order: 45  32  21  18  15

#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, j, temp, *arr;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        } 
    }
    printf("Ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\nDescending order: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}