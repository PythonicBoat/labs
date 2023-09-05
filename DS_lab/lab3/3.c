// WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.

#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
};

void add(struct poly *p1, struct poly *p2, struct poly *p3)
{
    int i = 0, j = 0, k = 0;
    while (i <= p1[0].exp && j <= p2[0].exp)
    {
        if (p1[i].exp > p2[j].exp)
        {
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff;
            i++;
            k++;
        }
        else if (p1[i].exp < p2[j].exp)
        {
            p3[k].exp = p2[j].exp;
            p3[k].coeff = p2[j].coeff;
            j++;
            k++;
        }
        else
        {
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            k++;
        }
    }
    while (i <= p1[0].exp)
    {
        p3[k].exp = p1[i].exp;
        p3[k].coeff = p1[i].coeff;
        i++;
        k++;
    }
    while (j <= p2[0].exp)
    {
        p3[k].exp = p2[j].exp;
        p3[k].coeff = p2[j].coeff;
        j++;
        k++;
    }
    p3[0].exp = k - 1;
}

void display(struct poly *p)
{
    int i;
    printf("\nCoefficient\tExponent\n");
    for (i = 1; i <= p[0].exp; i++)
    {
        printf("%d\t\t%d\n", p[i].coeff, p[i].exp);
    }
}

int main()
{
    int i, j, k = 1;
    struct poly p1[20], p2[20], p3[20];
    printf("Enter the highest exponent of the first polynomial: ");
    scanf("%d", &p1[0].exp);
    printf("Enter the coefficients of the first polynomial: ");
    for (i = 0; i <= p1[0].exp; i++)
    {
        scanf("%d", &p1[i].coeff);
        p1[i].exp = i;
    }
    printf("Enter the highest exponent of the second polynomial: ");
    scanf("%d", &p2[0].exp);
    printf("Enter the coefficients of the second polynomial: ");
    for (i = 0; i <= p2[0].exp; i++)
    {
        scanf("%d", &p2[i].coeff);
        p2[i].exp = i;
    }
    if (p1[0].exp > p2[0].exp)
    {
        p3[0].exp = p1[0].exp;
    }
    else
    {
        p3[0].exp = p2[0].exp;
    }
    add(p1, p2, p3);
    display(p3);
    return 0;
}
