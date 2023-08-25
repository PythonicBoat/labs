// wap to find the sum of digits of a number, using a function

#include <stdio.h>

int sum_of_digits(int n);

int main()
{
    int n, sum;
    printf("Enter a number: ");
    scanf("%d", &n);
    sum = sum_of_digits(n);
    printf("Sum of digits of %d is %d", n, sum);
    return 0;
}

int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

