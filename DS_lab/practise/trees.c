#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct {
    int top;
    
} stack;

struct node* createNode(int d) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

void preorderTraversal(struct node* root) {
    if (root!=NULL) {
        printf("&d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inorderTraversal(struct node* root) {
    if (root!=NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct node* root) {
    if (root!=NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inordernonre(struct node* root) {
    if (root==NULL)
        return;
    
    if (root!=NULL) {
        if (root->data != NULL) {
            printf();
        }
    }
}

void main() {
    struct Node* root = NULL;
    int n, data;
    printf("No. of nodes in BST : ");
    for (int i=0; i<n; i++) {
        printf("Enter element[%d]", i+1);

    }
    int choice;
    do {
        switch(choice) {
            case 1:
                printf("Recursive Traversals");
                break;

            if (choice == 1) {
                case 3:
                    printf("preorder traversal : \n");
                    preorderTraversal(root);
                    break;
                case 4:
                    printf("Inorder traversal : \n");
                    inorderTraversal(root);
                    break;
                case 5:
                    printf("postorder traversal : \n");
                    postorderTraversal(root);
                    break;
            }

            case 2:
                printf("Non-recursive Traversal");
                break;
            default:
                printf("Invalid choice!");
        }
    }
    while(1);
}