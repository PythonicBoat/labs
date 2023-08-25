// wap to find the largest element stored in an array of n elements by using dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

void main() {
    int i, n, max;
    printf("Enter value of n : ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n*sizeof(int));
    printf("Enter %d elements : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    max = *ptr;
    for (i = 0; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }
    printf("Largest element is %d", max);
    free(ptr);
}
