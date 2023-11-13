// In addition to Q7.1, perform deletion of an element in the BST using function.

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform deletion of a node in the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root; // Base case: If the tree is empty
    }

    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
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
    // Example usage
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
