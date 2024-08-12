// wap to display the value in reverse order from an integer array using pointer

#include <stdio.h>

int main()
{
    int a[5], i;
    int *p;
    printf("Enter 5 numbers: ");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    p = &a[4];
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *p);
        p--;
    }
    return 0;
}
