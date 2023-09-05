// WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
#include <stdlib.h>

struct sparse
{
    int row;
    int col;
    int val;
};

void transpose(struct sparse *s, struct sparse *t)
{
    int i, j, k = 1;
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;
    for (i = 0; i < s[0].col; i++)
    {
        for (j = 1; j <= s[0].val; j++)
        {
            if (s[j].col == i)
            {
                t[k].row = s[j].col;
                t[k].col = s[j].row;
                t[k].val = s[j].val;
                k++;
            }
        }
    }
}

void display(struct sparse *s)
{
    int i;
    printf("\nRow\tColumn\tValue\n");
    for (i = 0; i <= s[0].val; i++)
    {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
    }
}

int main()
{
    int i, j, k = 1;
    struct sparse s[20], t[20];
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &s[0].row, &s[0].col);
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < s[0].row; i++)
    {
        for (j = 0; j < s[0].col; j++)
        {
            scanf("%d", &s[k].val);
            if (s[k].val != 0)
            {
                s[k].row = i;
                s[k].col = j;
                k++;
            }
        }
    }
    s[0].val = k - 1;
    printf("\nOriginal Matrix: ");
    display(s);
    transpose(s, t);
    printf("\nTranspose Matrix: ");
    display(t);
    return 0;
}
