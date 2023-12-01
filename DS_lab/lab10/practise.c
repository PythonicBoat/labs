#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Stack {
    struct Node* data;
    struct Stack* next;
};

struct Stack* createStack(struct Node* data) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = data;
    stack->next = NULL;
    return stack;
}

// void push(struct Stack** top, struct Node* data) {
//     struct Stack* stack = createStack(data);
//     stack->next = *top;
//     *top = stack;
// }

struct Node* push(struct Stack** top) {
    struct Stack* stack = createStack((*top)->data);
    stack->next = *top;
    *top = stack;
}

struct Node* pop(struct Stack** top) {
    struct Stack* temp = *top;
    *top = (*top)->next;
    struct Node* popped = temp->data;
    free(temp);
    return popped;
}

void preOrderNonRecursive(struct Node* root) {
    struct Stack* stack = NULL;
    push(&stack, root);
    while (stack != NULL) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);
        if (node->right) {
            push(&stack, node->right);
        }
        if (node->left) {
            push(&stack, node->left);
        }
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    preOrderNonRecursive(root);
    return 0;
}