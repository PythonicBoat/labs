#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

void quickSort(int arr[], int low, int high, int *comp, int *isBest) {
    if (low < high) {
        int pivot = arr[high], i = low - 1, j;
        for (j = low; j < high; j++) {
            (*comp)++;
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        int leftSize = pi - low;
        int rightSize = high - pi;

        if ((leftSize == 0 || rightSize == 0) && *isBest != -1)
            *isBest = -1;  // Worst-case scenario
        else if (abs(leftSize - rightSize) <= 1 && *isBest != -1)
            *isBest = 1;  // Best-case scenario

        quickSort(arr, low, pi - 1, comp, isBest);
        quickSort(arr, pi + 1, high, comp, isBest);
    }
}

void handleFile(char *inputFile, char *outputFile) {
    int arr[MAX], n = 0, comp = 0, isBest = 0;
    clock_t start, end;
    FILE *fp = fopen(inputFile, "r");
    if (!fp) { printf("Error opening file\n"); return; }

    while (n < MAX && fscanf(fp, "%d", &arr[n]) == 1) n++;
    fclose(fp);

    start = clock();
    quickSort(arr, 0, n - 1, &comp, &isBest);
    end = clock();

    printf("Sorted Content: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nNumber of Comparisons: %d\n", comp);
    printf("Execution Time: %.2f nanoseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1000000000);
    printf("Scenario: %s\n", isBest == -1 ? "Worst-case" : "Best-case");

    fp = fopen(outputFile, "w");
    if (!fp) { printf("Error opening file\n"); return; }
    for (int i = 0; i < n; i++) fprintf(fp, "%d ", arr[i]);
    fclose(fp);
}

int main() {
    int choice;
    printf("MAIN MENU (QUICK SORT)\n1. Ascending txta\n2. Descending txta\n3. Random txta\n4. ERROR (EXIT)\nEnter option: ");
    scanf("%d", &choice);

    if (choice == 1) handleFile("inAsce1.txt", "outQuickAsce.txt");
    else if (choice == 2) handleFile("inDesc1.txt", "outQuickDesc.txt");
    else if (choice == 3) handleFile("inRand1.txt", "outQuickRand.txt");
    else printf("Invalid choice\n");

    return 0;
}
