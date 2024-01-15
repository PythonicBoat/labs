// In addition to Q10.1, perform deletion of an element in the BST using function.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};



struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}




struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root; 
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);

    printf("BST before deletion: ");
    inorderTraversal(root);
    printf("\n");

    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);

    printf("BST after deletion of %d: ", keyToDelete);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
