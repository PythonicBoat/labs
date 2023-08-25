// wap to input n elements to and integer array then display only even elements

#include <stdio.h>

int main()
{
    int arr[10];
    int i;
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Even elements in array are: ");
    for(i=0;i<n;i++)
    {
        if(arr[i]%2 == 0)
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}
