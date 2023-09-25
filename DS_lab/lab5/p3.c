// Write a program to represent the given sparse matrix using header single linked list and 
// display it.

// Sample Input/Output

// Enter size of the sparse matrix: 4 5
// Enter elements of sparse matrix: 0  0  33  0  0  0  17  0  0  0  0  0  0  46  0  0  0  0  0  51

// sparse matrix in 3-tuple format
// 4   5   4
// 0   2   33
// 1   1   17
// 2   3   46
// 3   4   51

#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int val;
    struct node *next;
};

struct node *head = NULL;

void insert(int row, int col, int val) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->val = val;
    new_node->next = head;
    head = new_node;
}

void display() {
    struct node *temp = head;
    printf("sparse matrix in 3-tuple format\n");
    printf("%d   %d   %d\n", temp->row, temp->col, temp->val);
    temp = temp->next;
    while (temp != NULL) {
        printf("%d   %d   %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
}

int main() {
    int m, n, i, j, val;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter elements of sparse matrix: ");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &val);
            if (val != 0) {
                insert(i, j, val);
            }
        }
    }
    display();
    return 0;
}