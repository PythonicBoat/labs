// Function to perform polynomial multiplication in c using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *head1 = NULL;

void insert(int coeff, int expo)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->next = NULL;

    if (head1 == NULL)
    {
        head1 = newnode;
    }
    else
    {
        struct node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display()
{
    struct node *temp = head1;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void poly_mul(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *temp3 = head3;

    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int expo = temp1->expo + temp2->expo;
            insert(coeff, expo);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = head2;
    }
}

int main()
{
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    int n1, n2, coeff, expo;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    printf("Enter the coefficients and exponents of the first polynomial: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d %d", &coeff, &expo);
        insert(coeff, expo);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    printf("Enter the coefficients and exponents of the second polynomial: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %d", &coeff, &expo);
        insert(coeff, expo);
    }

    printf("The first polynomial is: ");
    display();

    printf("The second polynomial is: ");
    display();

    poly_mul(head1, head2, head3);

    printf("The product of the polynomials is: ");
    display();

    return 0;
}
