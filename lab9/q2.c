// wap to find the sum of numbers store in an array of integers.

#include <stdio.h>

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    int sum = 0;
    for(i=0;i<10;i++)
    {
        sum += arr[i];
    }
    printf("Sum of numbers in array      is %d",sum);
    return 0;
}
