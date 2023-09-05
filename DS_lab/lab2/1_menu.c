// WAP to create a 1-D array of n elements and perform the following menu based operations using function.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. binary search to search an element 

#include <stdio.h>
#include <stdlib.h>

void create_array(int **arr, int n) {
  int i;
  *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array
  if (*arr == NULL) {
    printf("Memory allocation failed\n");
    exit(1); // Exit the program if memory allocation fails
  }
  for (i = 0; i < n; i++) {
    printf("Enter element at index %d: ", i);
    scanf("%d", &(*arr)[i]);
  }
}

void insert_element(int **arr, int *n, int element, int position) {
  int i;
  if (position < 0 || position > *n) {
    printf("Invalid position\n");
    return;
  }
  (*n)++;
  *arr = (int *)realloc(*arr, (*n) * sizeof(int)); // Resize the array
  if (*arr == NULL) {
    printf("Memory allocation failed\n");
    exit(1); // Exit the program if memory allocation fails
  }
  for (i = *n - 1; i > position; i--) {
    (*arr)[i] = (*arr)[i - 1];
  }
  (*arr)[position] = element;
}

void delete_element(int **arr, int *n, int position) {
  int i;
  if (position < 0 || position >= *n) {
    printf("Invalid position\n");
    return;
  }
  for (i = position; i < *n - 1; i++) {
    (*arr)[i] = (*arr)[i + 1];
  }
  (*n)--;
  *arr = (int *)realloc(*arr, (*n) * sizeof(int)); // Resize the array
  if (*arr == NULL) {
    printf("Memory allocation failed\n");
    exit(1); // Exit the program if memory allocation fails
  }
}

int linear_search(int *arr, int n, int element) {
  int i;

  for (i = 0; i < n; i++) {
    if (arr[i] == element) {
      return i;
    }
  }

  return -1;
}

int binary_search(int *arr, int n, int element) {
  int low = 0, high = n - 1, mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == element) {
      return mid;
    } else if (arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int n, element, position;
  int *arr = NULL;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  create_array(&arr, n);

  do {
    int choice;
    printf("\n\n1. Insert element\n2. Delete element\n3. Linear search\n4. Binary search\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        printf("Enter the position of the element: ");
        scanf("%d", &position);
        insert_element(&arr, &n, element, position);
        break;
      case 2:
        printf("Enter the position of the element to be deleted: ");
        scanf("%d", &position);
        delete_element(&arr, &n, position);
        break;
      case 3:
        printf("Enter the element to be searched: ");
        scanf("%d", &element);
        position = linear_search(arr, n, element);
        if (position == -1) {
          printf("Element not found\n");
        } else {
          printf("Element found at position %d\n", position);
        }
        break;
      case 4:
        printf("Enter the element to be searched: ");
        scanf("%d", &element);
        position = binary_search(arr, n, element);
        if (position == -1) {
          printf("Element not found\n");
        } else {
          printf("Element found at position %d\n", position);
        }
        break;
      case 5:
        free(arr); // Free the dynamically allocated memory
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (1);

  return 0;
}
