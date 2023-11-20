// 12.2 Write a program to sort array of elements in ascending and descending order by insertion sort using function.
// Sample Input/Output
// Enter no.of elements: 5
// Enter elements: 22  55  33  88  44
// Ascending order: 22   33   44  55  88
// Descending order: 88  55  44  33  22

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
    // Insertion sort
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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