#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

void merge(int arr[], int left, int mid, int right, int *comp) {
    int n1 = mid - left + 1, n2 = right - mid;
    int leftArr[n1], rightArr[n2], i = 0, j = 0, k = left;

    for (int l = 0; l < n1; l++) leftArr[l] = arr[left + l];
    for (int r = 0; r < n2; r++) rightArr[r] = arr[mid + 1 + r];

    while (i < n1 && j < n2) {
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
        (*comp)++;
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right, int *comp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comp);
        mergeSort(arr, mid + 1, right, comp);
        merge(arr, left, mid, right, comp);
    }
}

void handleFile(char *inputFile, char *outputFile) {
    int arr[MAX], n = 0, comp = 0;
    clock_t start, end;
    FILE *fp = fopen(inputFile, "r");
    if (!fp) { printf("Error opening file\n"); return; }

    while (n < MAX && fscanf(fp, "%d", &arr[n]) == 1) n++;
    fclose(fp);

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    start = clock();
    mergeSort(arr, 0, n - 1, &comp);
    end = clock();

    printf("After Sorting: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("Number of Comparisons: %d\n", comp);
    printf("Execution Time: %.2f nanoseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1000000000);

    fp = fopen(outputFile, "w");
    if (!fp) { printf("Error opening file\n"); return; }
    for (int i = 0; i < n; i++) fprintf(fp, "%d ", arr[i]);
    fclose(fp);
}

int main() {
    int choice;
    printf("MAIN MENU (MERGE SORT)\n1. Ascending txta\n2. Descending txta\n3. Random txta\n4. ERROR (EXIT)\nEnter option: ");
    scanf("%d", &choice);

    if (choice == 1) handleFile("inAsce.txt", "outMergeAsce.txt");
    else if (choice == 2) handleFile("inDesc.txt", "outMergeDesc.txt");
    else if (choice == 3) handleFile("inRand.txt", "outMergeRand.txt");
    else printf("Invalid choice\n");

    return 0;
}
