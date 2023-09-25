// 5.1 Write a program to create a double linked list and perform the following menu based operations on it:
// i. search an element in the list
// ii. insert an element at specific position 
// iii. delete an element from the list
// iv. display the list in reverse order
// vi. display the linked list in forward order

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}

void display() {
    struct node *temp = head;
    printf("List in forward order: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_reverse() {
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("List in reverse order: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void search(int data) {
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("%d found at position %d\n", data, pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("%d not found in the list\n", data);
}

void delete(int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("%d deleted from the list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the list\n", data);
}

void insert_at_position(int data, int pos) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (pos == 1) {
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        printf("%d inserted at position %d\n", data, pos);
        return;
    }
    struct node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    printf("%d inserted at position %d\n", data, pos);
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("\n\n");
        printf("1. Insert\n");
        printf("2. Display in forward order\n");
        printf("3. Display in reverse order\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Insert at specific position\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                display();
                break;
            case 3:
                display_reverse();
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 5:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insert_at_position(data, pos);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}