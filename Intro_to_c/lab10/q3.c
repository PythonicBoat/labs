// wap to swap values in an array and find teh second largest element in the array

#include <stdio.h>

int main()
{
    int arr[10], i, j, temp;
    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The second largest number is %d", arr[1]);
    return 0;
}