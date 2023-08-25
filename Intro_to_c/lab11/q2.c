// wap to check whether a given matrix is symmetric or not

#include <stdio.h>

int main()
{
    int a[10][10], i, j, n, flag = 0;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
    {
        printf("The matrix is not symmetric");
    }
    else
    {
        printf("The matrix is symmetric");
    }
    return 0;
}