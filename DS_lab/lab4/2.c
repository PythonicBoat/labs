// In addition to 4.1, perform following operations using function on the single linked list:
//  i. search an element in the list
// ii. sort the list in ascending order
// iii. reverse the list
// Sample Input/Output 
// Enter number of nodes: 5
// Enter the elements: 17  23  47 11  78  92  51
// MENU:
// 1. Insert the node at a position
// 2. Delete a node from specific position
// 3. Traversal
// 4. Count
// 5. Search
// 6. Sort
// 7. Reverse
// 8. Exit
// Enter choice: 1
// Enter element: 66 
// Enter position: 2
// Node inserted
// Enter choice: 3
// The list is: 17-> 66->23-> 47-> 11-> 78-> 92-> 51
// Enter the choice: 5
// Enter element to be searched: 23
// Element found at node-3
// Enter the choice: 7
// Reverse list: 51->92->78->11->47->23->66->17

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

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

void delete (int pos)
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
    else
    {
        struct node *temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void search(int data)
{
    struct node *temp = start;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element found at node-%d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

void sort()
{
    struct node *temp = start;
    while (temp != NULL)
    {
        struct node *temp1 = temp->next;
        while (temp1 != NULL)
        {
            if (temp->data > temp1->data)
            {
                int t = temp->data;
                temp->data = temp1->data;
                temp1->data = t;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}

void reverse()
{
    struct node *prev = NULL;
    struct node *curr = start;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    start = prev;
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

int main()
{
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
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Count\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
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
            int pos;
            printf("Enter position: ");
            scanf("%d", &pos);
            delete (pos);
            printf("Node deleted\n");
            break;
        }
        case 3:
        {
            printf("The list is: ");
            traverse();
            break;
        }
        case 4:
        {
            int count = 0;
            struct node *temp = start;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            printf("Number of nodes: %d\n", count);
            break;
        }
        case 5:
        {
            int data;
            printf("Enter element to be searched: ");
            scanf("%d", &data);
            search(data);
            break;
        }
        case 6:
        {
            sort();
            printf("List sorted\n");
            break;
        }
        case 7:
        {
            reverse();
            printf("Reverse list: ");
            traverse();
            break;
        }
        case 8:
        {
            printf("Exiting...\n");
            break;
        }
        default:
        {
            printf("Invalid choice\n");
            break;
        }
        }
    } while (choice != 8);
}

