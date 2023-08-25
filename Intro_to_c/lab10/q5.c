// wap to search for a value in a list of 10 numbers using binary search

#include <stdio.h>

int main()
{
    int i, j, temp, a[10], key, low, high, mid;
    printf("Enter the elements of the array: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    low = 0;
    high = 9;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (a[mid] < key)
        {
            low = mid + 1;
        }
        else if (a[mid] == key)
        {
            printf("Element found at position %d", mid + 1);
            break;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (low > high)
    {
        printf("Element not found");
    }
    return 0;
}