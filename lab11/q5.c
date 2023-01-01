// // wap to find the um of the elements of a matrix in a row wise and column wise manner

// #include <stdio.h>

// int main()
// {
//     int a[10][10], i, j, n, m, sum = 0;
//     printf("Enter the order of the matrix: ");
//     scanf("%d %d", &n, &m);
//     printf("Enter the elements of the matrix: ");
    
//     for (i = 0; i < n; i++)
//         for (j = 0; j < m; j++)
//             scanf("%d", &a[i][j]);
    
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < m; j++)
//         {
//             sum = sum + a[i][j];
//         }
//         printf("The sum of row %d is %d\n", i + 1, sum);
//     }
// }


#include <stdio.h>

void main() {
    int arr[10], i, n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for (i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
}
