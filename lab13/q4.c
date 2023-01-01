// wap to sort the elements using recursion

#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int a[10], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, n);
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
