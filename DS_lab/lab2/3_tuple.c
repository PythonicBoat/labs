// WAP to represent a given sparse matrix in 3-tuple format using 2-D array. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, count = 0;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &m, &n);
    int **matrix = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }
    printf("Enter elements of sparse matrix: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    int **sparse = (int **) malloc((count + 1) * sizeof(int *));
    for (int i = 0; i < count + 1; i++) {
        sparse[i] = (int *) malloc(3 * sizeof(int));
    }
    sparse[0][0] = m;
    sparse[0][1] = n;
    sparse[0][2] = count;
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("\nsparse matrix in 3-tuple format\n");
    for (int i = 0; i < count + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d   ", sparse[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < count + 1; i++) {
        free(sparse[i]);
    }
    free(sparse);
    return 0;
}