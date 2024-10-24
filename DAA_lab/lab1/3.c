#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int n, i, j, count = 0, maxCount = 0, mostRepeating; 
    int *arr;
    int *countArr;

    file = fopen("txta.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter total count of numbers to input : ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    countArr = (int *)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        countArr[i] = 0;
    }

    fclose(file);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                countArr[i]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (countArr[i] > 1) {
            count++;
        }
        if (countArr[i] > maxCount) {
            maxCount = countArr[i];
            mostRepeating = arr[i];
        }
    }

    printf("Array : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTotal no. of duplicate values : %d\n", count);
    printf("Most repeating element in the array = %d\n", mostRepeating);

    free(arr);
    free(countArr);

    return 0;
}