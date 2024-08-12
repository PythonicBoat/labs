// wap to find the sum of the first and the last digit

#include <stdio.h>

int main()
{
    int num, sum, first, last;
    printf("Enter a number: ");
    scanf("%d", &num);
    last = num % 10;
    while (num >= 10)
    {
        num = num / 10;
    }
    first = num;
    sum = first + last;
    printf("The sum of the first and the last digit is %d", sum);
    return 0;
}
