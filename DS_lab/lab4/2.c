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

int searchNode(int data) {
  struct node *temp = head;
  int i = 1;
  while (temp != NULL) {
    if (temp->data == data) {
      return i;
    }
    temp = temp->next;
    i++;
  }
  return -1;
}

void sortList() {
  struct node *current, *next;
  int temp;

  current = head;
  while (current != NULL) {
    next = current->next;
    while (next != NULL) {
      if (current->data > next->data) {
        temp = current->data;
        current->data = next->data;
        next->data = temp;
      }
      next = next->next;
    }
    current = current->next;
  }
}

void reverseList() {
  struct node *prev, *curr, *next;

  prev = NULL;
  curr = head;
  next = curr->next;

  while (curr != NULL) {
    curr->next = prev;
    prev = curr;
    curr = next;
    if (next != NULL) {
