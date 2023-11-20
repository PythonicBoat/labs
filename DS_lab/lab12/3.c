// 12.3 Write a program to sort array of elements in ascending and descending order by selection sort using function.
// Sample Input/Output
// Enter no.of elements: 5
// Enter elements: 11  55  22  66  33
// Ascending order: 11   55   22  33  66
// Descending order: 66  55  33  22  11

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
    // Selection sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                // Swap
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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