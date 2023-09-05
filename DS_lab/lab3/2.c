// WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>
#include <stdlib.h>

struct sparse
{
    int row;
    int col;
    int val;
};

void add(struct sparse *s1, struct sparse *s2, struct sparse *s3)
{
    int i, j, k = 1;
    if (s1[0].row == s2[0].row && s1[0].col == s2[0].col)
    {
        s3[0].row = s1[0].row;
        s3[0].col = s1[0].col;
        for (i = 0; i < s1[0].row; i++)
        {
            for (j = 0; j < s1[0].col; j++)
            {
                if (s1[k].val != 0)
                {
                    s3[k].row = i;
                    s3[k].col = j;
                    s3[k].val = s1[k].val + s2[k].val;
                    k++;
                }
            }
        }
        s3[0].val = k - 1;
    }
    else
    {
        printf("Addition not possible");
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
    struct sparse s1[20], s2[20], s3[20];
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &s1[0].row, &s1[0].col);
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < s1[0].row; i++)
    {
        for (j = 0; j < s1[0].col; j++)
        {
            scanf("%d", &s1[k].val);
            if (s1[k].val != 0)
            {
                s1[k].row = i;
                s1[k].col = j;
                k++;
            }
        }
    }
    s1[0].val = k - 1;
    k = 1;
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < s1[0].row; i++)
    {
        for (j = 0; j < s1[0].col; j++)
        {
            scanf("%d", &s2[k].val);
            if (s2[k].val != 0)
            {
                s2[k].row = i;
                s2[k].col = j;
                k++;
            }
        }
    }
    s2[0].val = k - 1;
    add(s1, s2, s3);
    printf("\nMatrix 1:\n");
    display(s1);
    printf("\nMatrix 2:\n");
    display(s2);
    printf("\nMatrix 3:\n");
    display(s3);
    return 0;
}
