// wap to find the largest number stored in an array of integers and display it

#include <stdio.h>

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    int max = arr[0];
    for(i=0;i<10;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Largest number in array is %d",max);
    return 0;
}