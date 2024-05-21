#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void quickSort(struct node **headRef);
struct node *partition(struct node *head, struct node *end, struct node **newHead, struct node **newEnd);

void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
    printf("Linked List before sorting \n");
    printList(a);
    quickSort(&a);
    printf("\nLinked List after sorting \n");
    printList(a);
    return 0;
}
