// wap to calculate the sum of 10 numbers taking user input but if the user enters 0, the program terminates

#include <stdio.h>

int main()
{
    int i, sum = 0, num;
    for (i = 1; i <= 10; i++)
    {
        printf("enter the number : ");
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
        sum = sum + num;
    }
    printf("sum of the numbers is %d\n", sum);
    return 0;
}
