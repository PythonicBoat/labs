// Write a program to create a single linked list of n nodes and perform the following menu based operations on it using function:
// i. Insert a node at specific position 
// ii. Deletion of an element from the list
// iii. Count nodes
// iv. Traverse the linked list

// Sample Input/Output 
// Enter number of nodes: 5
// Enter the elements: 17  23  47 11  78  92  51
// MENU:
// 1. Insert the node at a position
// 2. Delete a node from specific position
// 3. Traversal
// 4. Count
// 5. Exit
// Enter choice: 1
// Enter element: 66 
// Enter position: 2
// Node inserted
// Enter choice: 3
// The list is: 17-> 66->23-> 47-> 11-> 78-> 92-> 51
// Enter the choice: 4
// The total number of nodes: 8

<<<<<<< HEAD

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
=======
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
>>>>>>> 51df39fd13dfd61a97785be07a1b0befbb1a0123
};

struct node *head = NULL;

<<<<<<< HEAD
void insert(int data, int pos)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete(int pos)
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(pos == 1)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        struct node *temp = head;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        struct node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void traverse()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        while(temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void count()
{
    int count = 0;
    struct node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The total number of nodes: %d\n", count);
}

int main()
{
    int n, data, pos, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &data);
        insert(data, i+1);
    }
    while(1)
    {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert(data, pos);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete(pos);
                printf("Node deleted\n");
                break;
            case 3:
                printf("The list is: ");
                traverse();
                break;
            case 4:
                count();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
=======
void createList(int n) {
  int i, data;
  struct node *newNode;

  for (i = 0; i < n; i++) {
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node %d: ", i + 1);
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      struct node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
}

void insertNode(int data, int position) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  if (position == 1) {
    newNode->next = head;
    head = newNode;
  } else {
    struct node *temp = head;
    int i = 1;
    while (i < position - 1 && temp != NULL) {
      temp = temp->next;
      i++;
    }
    if (temp != NULL) {
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }
}

void deleteNode(int position) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (position == 1) {
    head = head->next;
  } else {
    struct node *temp = head;
    int i = 1;
    while (i < position - 1 && temp != NULL) {
      temp = temp->next;
      i++;
    }
    if (temp != NULL && temp->next != NULL) {
      temp->next = temp->next->next;
    }
  }
}

void traverseList() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct node *temp = head;
  printf("The list is:\n");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int countNodes() {
  int count = 0;
  struct node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

int main() {
  int n, data, position, choice;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  createList(n);

  do {
    printf("\nMENU: \n");
    printf("1. Insert the node at a position\n");
    printf("2. Delete a node from specific position\n");
    printf("3. Traversal\n");
    printf("4. Count\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &data);
        printf("Enter the position: ");
        scanf("%d", &position);
        insertNode(data, position);
        break;
      case 2:
        printf("Enter the position of the node to be deleted: ");
        scanf("%d", &position);
        deleteNode(position);
        break;
      case 3:
        traverseList();
        break;
      case 4:
        printf("The total number of nodes: %d\n", countNodes());
       
>>>>>>> 51df39fd13dfd61a97785be07a1b0befbb1a0123
