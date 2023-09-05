// Write a program to create a structure to represent complex number. Perform the addition of two complex number using function (call by value). (Note: Structure as an argument to function)

// Sample Input/Output:
// Enter complex number 1: 3  4
// Enter complex number 2: 4  5
// Sum=7+9i

#include <stdio.h>

struct complex {
    int real;
    int img;
};

struct complex add(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}

int main() {
    struct complex a, b, c;
    printf("Enter complex number 1: ");
    scanf("%d %d", &a.real, &a.img);
    printf("Enter complex number 2: ");
    scanf("%d %d", &b.real, &b.img);
    c = add(a, b);
    printf("Sum=%d+%di", c.real, c.img);
    return 0;
}