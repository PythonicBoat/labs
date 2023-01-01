// wap to multiply two matrices and display it

#include <stdio.h>

void main()
{
    int a[10][10], b[10][10], c[10][10], i, j, k, n, m, p, o;
    printf("Enter the order of the first matrix: ");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of the first matrix: ");
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    
    printf("Enter the order of the second matrix: ");
    scanf("%d %d", &o, &p);
    printf("Enter the elements of the second matrix: ");
    
    for (i = 0; i < o; i++)
        for (j = 0; j < p; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < m; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    printf("The product of the two matrices is: ");
    
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            printf("%d ", c[i][j]);
}
