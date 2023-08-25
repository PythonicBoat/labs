// wap to print a number and reverse it using pointer

#include <stdio.h>

int main()
{
    int n, rev = 0;
    int *p;
    printf("Enter a number: ");
    scanf("%d", &n);
    p = &n;
    while (*p != 0)
    {
        rev = rev * 10 + *p % 10;
        *p = *p / 10;
    }
    printf("Reverse of %d is %d", n, rev);
    return 0;
}
