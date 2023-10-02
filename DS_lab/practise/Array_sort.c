#include <stdio.h>
#include <stdlib.h>

int** create_2d_array(int rows, int cols) {
  int** array = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    array[i] = (int*)malloc(cols * sizeof(int));
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] = i * cols + j;
    }
  }

  return array;
}

void sort_2d_array(int** array, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = i + 1; k < rows; k++) {
        for (int l = 0; l < cols; l++) {
          if (array[i][j] > array[k][l]) {
            int temp = array[i][j];
            array[i][j] = array[k][l];
            array[k][l] = temp;
          }
        }
      }
    }
  }
}

void print_2d_array(int** array, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows = 3;
  int cols = 4;

  int** array = create_2d_array(rows, cols);

  printf("Original array:\n");
  print_2d_array(array, rows, cols);

  sort_2d_array(array, rows, cols);

  printf("Sorted array:\n");
  print_2d_array(array, rows, cols);

  for (int i = 0; i < rows; i++) {
    free(array[i]);
  }
  free(array);

  return 0;
}
