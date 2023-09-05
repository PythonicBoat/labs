// Write a program to perform the following operations on a given square matrix using functions: 
// i.   Find the no.of nonzero elements
// ii.  Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal

#include <stdio.h>

void findNonZero(int matrix[][10], int *count, int n) {
    int i, j;
    *count = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (matrix[i][j] != 0):
            (*count)++;
        }
    }
}

void upperTriangular(int matrix[][10], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i > j) {
        matrix[i][j] = 0;
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void diagonalElements(int [][10], int n) {
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i==j) {
                printf("%d", matrix[i][j]);
            } else if (i<j) {
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n, A[10][10], count;
    printf("Enter the size of the matrix : ");
    scanf("%d", &n);
    printf("Enter elements in the matrix : ");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &matrix[i][j])
        }
    }
    findNonZero(matrix, n, &count);

    printf("non zero elements : %d\n", count);
    upperTriangular(matrix, n);

    diagonalElements(matrix, n);
    return 0;
}
