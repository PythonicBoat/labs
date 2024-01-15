#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    int top;
    unsigned capacity;
    struct Node** arr;
};

struct Node* createNode(char data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Stack* createStack(unsigned capacity) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = capacity;
    s->arr = (struct Node**)malloc(s->capacity * sizeof(struct Node*));
    return s;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, struct Node* item) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = item;
}

struct Node* pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[s->top--];
}

struct Node* buildExprTree(char prefix[]) {
    struct Stack* s = createStack(strlen(prefix));
    
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char sym = prefix[i];

        if (isalnum(sym)) {
            struct Node* n = createNode(sym);
            push(s, n);
        } else {
            struct Node* op1 = pop(s);
            struct Node* op2 = pop(s);

            struct Node* n = createNode(sym);
            n->left = op1;
            n->right = op2;
            push(s, n);
        }
    }
    return pop(s);
}

void postfixTraversal(struct Node* root) {
    if (root != NULL) {
        postfixTraversal(root->left);
        postfixTraversal(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char prefix[50];
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);

    struct Node* root = buildExprTree(prefix);

    printf("\nPostfix Expression: ");
    postfixTraversal(root);

    return 0;
}
