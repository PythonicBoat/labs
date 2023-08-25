 // wap to store n elements in an array usig dynamic memory allocation and print the element using pointer

#include <stdio.h>
#include <stdlib.h>

void main() {
    int i, n;  
    printf("Enter value of n : ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    printf("Elements are : ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    free(ptr);
}
