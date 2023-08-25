// wap to find the median if a list of 20 numbers

#include <stdio.h>

int main()
{
    int arr[20], i, j, temp;
    printf("Enter 20 numbers: ");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The median is %d", arr[9]);
    return 0;
} 