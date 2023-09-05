// Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations
// Sample Input/Output
// Polynomial-1:
// Enter the Maximum power of x: 2
// Enter the coefficient of degree 2: 4
// Enter the coefficient of degree 1: 3

// Enter the coefficient of degree 0:2
// Polynomial-2:
// Enter the Maximum power of x: 3
// Enter the coefficient of degree 3: 5
// Enter the coefficient of degree 2: 4
// Enter the coefficient of degree 1:6
// Enter the coefficient of degree 0:10

// Sum: 5x^3+8x^2+9x^1+12x^0.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int coefficient;
  int power;
  struct node *next;
};

struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

void createList(struct node *head, int maxPower) {
  int i, coefficient;

  for (i = maxPower; i >= 0; i--) {
    printf("Enter the coefficient of degree %d: ", i);
    scanf("%d", &coefficient);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coefficient = coefficient;
    newNode->power = i;
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

void addPolynomials() {
  struct node *temp1 = head1, *temp2 = head2, *temp3 = NULL;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->power == temp2->power) {
      struct node *newNode = (struct node *)malloc(sizeof(struct node));
      newNode->coefficient = temp1->coefficient + temp2->coefficient;
      newNode->power = temp1->power;
      newNode->next = NULL;

      if (head3 == NULL) {
        head3 = newNode;
      } else {
        temp3->next = newNode;
      }
      temp3 = newNode;

      temp1 = temp1->next;
      temp2 = temp2->next;
    } else if (temp1->power > temp2->power) {
      struct node *newNode = (struct node *)malloc(sizeof(struct node));
      newNode->coefficient = temp1->coefficient;
      newNode->power = temp1->power;
      newNode->next = NULL;

      if (head3 == NULL) {
        head3 = newNode;
      } else {
        temp3->next = newNode;
      }
      temp3 = newNode;

      temp1 = temp1->next;
    } else {
      struct node *newNode = (struct node *)malloc(sizeof(struct node));
      newNode->coefficient = temp2->coefficient;
      newNode->power = temp2->power;
      newNode->next = NULL;

      if (head3 == NULL) {
        head3 = newNode;
      } else {
        temp3->next = newNode;
      }
      temp3 = newNode;

      temp2 = temp2->next;
    }
  }

  while (temp1 != NULL) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coefficient = temp1->coefficient;
    newNode->power = temp1->power;
    newNode->next = NULL;

    if (head3 == NULL) {
      head3 = newNode;
    } else {
      temp3->next = newNode;
    }
    temp3 = newNode;
    temp1 = temp1->next;
  }

  while (temp2 != NULL) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coefficient = temp2->coefficient;
    newNode->power = temp2->power;
    newNode->next = NULL;

    if (head3 == NULL) {
      head3 = newNode;
    } else {
      temp3->next = newNode;
    }
    temp3 = newNode;
    temp2 = temp2->next;
  }
}

void printPolynomial(struct node *head) {
  struct node *temp = head;

  if (temp == NULL) {
    printf("Polynomial is empty.\n");
    return;
