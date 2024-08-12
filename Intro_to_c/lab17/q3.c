// wap to add two complex numbers by passing real and complex part

#include <stdio.h>

void add(int a, int b, int c, int d, int *e, int *f)
{
    *e = a + c;
    *f = b + d;
}

int main()
{
    int a, b, c, d, e, f;
    printf("Enter real and complex part of first number: ");
    scanf("%d %d", &a, &b);
    printf("Enter real and complex part of second number: ");
    scanf("%d %d", &c, &d);
    add(a, b, c, d, &e, &f);
    printf("Sum of two complex numbers is %d + %di", e, f);
    return 0;
}
