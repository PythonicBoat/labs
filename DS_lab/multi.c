#include <stdio.h>
typedef struct Sparse_Matrix {
  int row;int col;int value;
} Sparse_Matrix;
void multiplySparseMatrices(Sparse_Matrix *matrix1, Sparse_Matrix *matrix2, Sparse_Matrix *result, int m, int n, int p) {
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < p; j++) {
      result[i * p + j].row = i;
      result[i * p + j].col = j;
      result[i * p + j].value = 0;
    }
  }
  for (i = 0; i < m; i++) { 
    for (j = 0; j < n; j++) {
      for (k = 0; k < p; k++) {
        if (matrix1[i * n + j].col == matrix2[j * p + k].row) {
          result[i * p + k].value += matrix1[i * n + j].value * matrix2[j * p + k].value;
        }
      }
    }
  }
}
int main() {
  int m, n, p;
  Sparse_Matrix matrix1[m * n], matrix2[n * p], result[m * p];
  scanf("%d %d %d", &m, &n, &p);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d %d %d", &matrix1[i * n + j].row, &matrix1[i * n + j].col, &matrix1[i * n + j].value);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      scanf("%d %d %d", &matrix2[i * p + j].row, &matrix2[i * p + j].col, &matrix2[i * p + j].value);
    }
  }
  multiplySparseMatrices(matrix1, matrix2, result, m, n, p);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("%d %d %d\n", result[i * p + j].row, result[i * p + j].col, result[i * p + j].value);
    }
  }
}
