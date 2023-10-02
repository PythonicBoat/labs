#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int rows;
  int cols;
  int** array;
} Matrix;

Matrix* create_matrix(int rows, int cols) {
  Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->array = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix->array[i] = (int*)malloc(cols * sizeof(int));
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix->array[i][j] = rand() % 2;
    }
  }

  return matrix;
}

void replace_0_with_1_if_surrounding_elements_are_1(Matrix* matrix) {
  for (int i = 1; i < matrix->rows - 1; i++) {
    for (int j = 1; j < matrix->cols - 1; j++) {
      if (matrix->array[i][j] == 0) {
        if (matrix->array[i - 1][j] && matrix->array[i + 1][j] && matrix->array[i][j - 1] && matrix->array[i][j + 1]) {
          matrix->array[i][j] = 1;
        }
      }
    }
  }
}

void rotate_row_of_matrix(Matrix* matrix, int n) {
  for (int i = 0; i < matrix->rows; i++) {
    int temp = matrix->array[i][0];
    for (int j = 0; j < matrix->cols - 1; j++) {
      matrix->array[i][j] = matrix->array[i][j + 1];
    }
    matrix->array[i][matrix->cols - 1] = temp;
  }
}

void print_matrix(Matrix* matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->array[i][j]);
    }
    printf("\n");
  }
}

int main() {
  Matrix* matrix = create_matrix(3, 3);

  printf("Original matrix:\n");
  print_matrix(matrix);

  replace_0_with_1_if_surrounding_elements_are_1(matrix);

  printf("Matrix with 0 elements replaced with 1 if all its surrounding elements are 1:\n");
  print_matrix(matrix);

  rotate_row_of_matrix(matrix, 3);

  printf("Matrix with each row rotated by 3 positions:\n");
  print_matrix(matrix);

  return 0;
}
