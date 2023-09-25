// Write a program to create a circular linked list and display the elements of the list. 

// Sample Input/Output

// Enter no.of nodes: 5
// Enter info of node1: 30
// Enter info of node1: 50
// Enter info of node1: 40
// Enter info of node1: 20
// Enter info of node1: 70

// Clinkedlist: 30  50  40  20  70

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void display() {
    struct node *temp = head;
    printf("Clinkedlist: ");
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n, i, data;
    printf("Enter no.of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter info of node%d: ", i);
        scanf("%d", &data);
        insert(data);
    }
    display();
    return 0;
}