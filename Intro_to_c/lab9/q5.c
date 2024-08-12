// wap to find the avergae of all the numbers stored in an array

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
    printf("Average of numbers in array is %f",(float)sum/10);
    return 0;
}
