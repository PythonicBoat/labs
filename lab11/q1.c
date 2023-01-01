// wap to find out the sum of diagonal elements of a matrix

#include <stdio.h>

int main()
{
    int a[3][3], i, j, sum = 0;
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                sum = sum + a[i][j];
            }
        }
    }
    printf("The sum of diagonal elements is %d", sum);
    return 0;
}
