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

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

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
       
