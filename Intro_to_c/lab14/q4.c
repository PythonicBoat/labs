// wap to multiply 2 values using call by reference

#include <stdio.h>

void multiply(int *a, int *b, int *c);

int main()
{
    int a, b, c;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    multiply(&a, &b, &c);
    printf("Product of %d and %d is %d", a, b, c);
    return 0;
}

void multiply(int *a, int *b, int *c)
{
    *c = *a * *b;
}
