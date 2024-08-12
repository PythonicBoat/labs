// wap to find the transpose of a matrix

#include <stdio.h>

void main() {
    int a[10][10], b[10][10], i, j, n, m;
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of the matrix: ");
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            b[j][i] = a[i][j];

    printf("The transpose of the matrix is: ");

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("%d ", b[i][j]);
}
