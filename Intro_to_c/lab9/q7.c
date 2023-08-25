// wap to input n elements to an integer arrray then count how many even and odd elements are prresent

#include <stdio.h>

int main()
{
    int arr[10];
    int i, n, even=0, odd=0;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]%2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("Even elements in array are: %d");
    return 0;
}
