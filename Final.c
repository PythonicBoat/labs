#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the expression tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function prototypes
bool isOperator(char ch);
bool isOperand(char ch);
struct TreeNode* createNode(char data);
struct TreeNode* buildExpressionTree(char prefix[], int* index);
void prefixToPostfix(struct TreeNode* root, char postfix[], int* index);

int main() {
    char prefix[100];
    char postfix[100];
    struct TreeNode* root = NULL;

    // Input the prefix expression
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);

    int index = 0;

    // Build expression tree from prefix expression
    root = buildExpressionTree(prefix, &index);

    // Convert expression tree to postfix expression
    index = 0;
    prefixToPostfix(root, postfix, &index);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to check if a character is an operand
bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to create a new expression tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build an expression tree from prefix expression
struct TreeNode* buildExpressionTree(char prefix[], int* index) {
    if (prefix[*index] == '\0') {
        return NULL;
    }

    struct TreeNode* node = createNode(prefix[(*index)++]);

    if (isOperator(node->data)) {
        // Recursively build left and right subtrees
        node->left = buildExpressionTree(prefix, index);
        node->right = buildExpressionTree(prefix, index);
    }

    return node;
}

// Function to convert expression tree to postfix expression
void prefixToPostfix(struct TreeNode* root, char postfix[], int* index) {
    if (root != NULL) {
        // Visit the root (append the data to postfix expression)
        postfix[(*index)++] = root->data;

        // Traverse the left subtree
        prefixToPostfix(root->left, postfix, index);

        // Traverse the right subtree
        prefixToPostfix(root->right, postfix, index);
    }
}
