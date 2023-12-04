// Write a program to read two numbers and compare the numbers using function call by address.
// Sample Input/Output:
// Enter two numbers: 50  80
// 50 is smaller than 80
// Enter two numbers: 40  10
// 40 is greater than 10
// Enter two numbers: 50  50
// Both numbers are same

#include <stdio.h>

struct {
    int a;
    int b;
} numbers;

void compare(int *a,int  *b) {
    if (*a > *b) {
        printf("%d is greater than %d", *a, *b);
    } else if (*a < *b) {
        printf("%d is smaller than %d", *a, *b);
    } else {
        printf("Both numbers are same");
    }
}

void main() {
    printf("Enter two numbers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    compare(&a, &b);
}












void compare(int *a, int *b) {
    if (*a > *b) {
        printf("%d is greater than %d", *a, *b);
    } else if (*a < *b) {
        printf("%d is smaller than %d", *a, *b);
    } else {
        printf("Both numbers are same");
    }
}

void main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    compare(&a, &b);
}
