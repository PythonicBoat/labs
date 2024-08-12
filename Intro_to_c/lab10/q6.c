// wap to find the number using linear search 

#include <stdio.h>

int main()
{
    int arr[10], i, search, found = 0;
    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &search);
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == search)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        printf("The number is found at position %d", i + 1);
    }
    else
    {
        printf("The number is not found");
    }
    return 0;
}
