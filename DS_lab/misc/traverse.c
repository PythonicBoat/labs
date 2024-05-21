// Iterative non-recursive traversal of PostOrder 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void nonRecursivePostOrder(struct node *root) {
    struct node *stack[100];
    int top = -1;
    struct node *prev = NULL;
    struct node *curr = root;
    stack[++top] = root;
    while (top != -1) {
        curr = stack[top];
        if (prev == NULL || prev->left == curr || prev->right == curr) {
            if (curr->left != NULL) {
                stack[++top] = curr->left;
            } else if (curr->right != NULL) {
                stack[++top] = curr->right;
            } else {
                printf("%d ", curr->data);
                top--;
            }
        } else if (curr->left == prev) {
            if (curr->right != NULL) {
                stack[++top] = curr->right;
            } else {
                printf("%d ", curr->data);
                top--;
            }
        } else if (curr->right == prev) {
            printf("%d ", curr->data);
            top--;
        }
        prev = curr;
    }
}

