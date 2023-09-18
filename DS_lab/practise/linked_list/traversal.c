#include <stdio.h>
#include <stdlib.h>

struct node // element of linked list
{
    int data;
    struct node *next;
};

struct node *start = NULL; // starting location of linked list

void insert(int data, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else if (pos == 1)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        struct node *temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void traverse()
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = start;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert(data, i + 1);
    }

    int choice;
    do
    {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Traversal\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int data, pos;
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert(data, pos);
            printf("Node inserted\n");
            break;
        }
        case 2:
        {
            printf("The list is: ");
            traverse();
            break;
        }
        default:
        {
            printf("Invalid choice\n");
            break;
        }
        }
    } while (choice != 3);
}