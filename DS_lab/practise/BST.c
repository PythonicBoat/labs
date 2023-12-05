#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100    

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height; // Height of the node (for AVL balancing)
};

// Define a structure for the binary search tree ADT
struct BST {
    struct TreeNode* root;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Function to get the height of a node (NULL nodes have height 0)
int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to update the height of a node based on its children
void updateHeight(struct TreeNode* node) {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to get the balance factor of a node
int getBalance(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to perform right rotation on a subtree rooted with y
struct TreeNode* rightRotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform left rotation on a subtree rooted with x
struct TreeNode* leftRotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to insert a node into a BST
struct TreeNode* insertNode(struct TreeNode* node, int data) {
    // Perform standard BST insert
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else // Duplicate values are not allowed
        return node;

    // Update height of the current node
    updateHeight(node);

    // Get the balance factor to check for AVL balance violations
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No balance violation, return the unchanged node
    return node;
}

// Function to find the node with the minimum value in a BST
struct TreeNode* findMinNode(struct TreeNode* node) {
    struct TreeNode* current = node;

    // Traverse to the leftmost leaf to find the minimum
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node with the given data from a BST
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL)
        return root;

    // Perform standard BST delete
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor
        struct TreeNode* temp = findMinNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    // If the tree had only one node, return
    if (root == NULL)
        return root;

    // Update height of the current node
    updateHeight(root);

    // Get the balance factor to check for AVL balance violations
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // No balance violation, return the unchanged node
    return root;
}

// Function for in-order traversal (recursive)
void inOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        inOrderRecursive(root->left);
        printf("%d ", root->data);
        inOrderRecursive(root->right);
    }
}

// Function for in-order traversal (non-recursive)
void inOrderNonRecursive(struct TreeNode* root) {
    struct TreeNode* stack[MAX_SIZE];
    int top = -1;
    struct TreeNode* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

// Function for pre-order traversal (recursive)
void preOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}

// Function for pre-order traversal (non-recursive)
void preOrderNonRecursive(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Function for post-order traversal (recursive)
void postOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Function for post-order traversal (non-recursive)
void postOrderNonRecursive(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* stack1[MAX_SIZE];
    struct TreeNode* stack2[MAX_SIZE];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct TreeNode* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Function to check if a tree is AVL
int isAVL(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right))
        return 1;

    return 0;
}

// Function to free memory used by the tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Function to free memory used by the BST
void freeBST(struct BST* tree) {
    freeTree(tree->root);
    free(tree);
}

// Main function for testing
int main() {
    // Create an empty BST
    struct BST* myBST = (struct BST*)malloc(sizeof(struct BST));
    myBST->root = NULL;

    // Insert nodes into the BST
    myBST->root = insertNode(myBST->root, 10);
    myBST->root = insertNode(myBST->root, 5);
    myBST->root = insertNode(myBST->root, 15);
    myBST->root = insertNode(myBST->root, 3);
    myBST->root = insertNode(myBST->root, 7);
    myBST->root = insertNode(myBST->root, 12);
    myBST->root = insertNode(myBST->root, 18);

    // Print in-order traversal
    printf("In-order traversal (recursive): ");
    inOrderRecursive(myBST->root);
    printf("\n");

    printf("In-order traversal (non-recursive): ");
    inOrderNonRecursive(myBST->root);
    printf("\n");

    // Print pre-order traversal
    printf("Pre-order traversal (recursive): ");
    preOrderRecursive(myBST->root);
    printf("\n");

    printf("Pre-order traversal (non-recursive): ");
    preOrderNonRecursive(myBST->root);
    printf("\n");

    // Print post-order traversal
    printf("Post-order traversal (recursive): ");
    postOrderRecursive(myBST->root);
    printf("\n");

    printf("Post-order traversal (non-recursive): ");
    postOrderNonRecursive(myBST->root);
    printf("\n");

    // Delete a node
    int keyToDelete = 15;
    printf("Deleting node with key %d\n", keyToDelete);
    myBST->root = deleteNode(myBST->root, keyToDelete);

    // Print in-order traversal after deletion
    printf("In-order traversal after deletion: ");
    inOrderRecursive(myBST->root);
    printf("\n");

    // Check if the tree is AVL
    if (isAVL(myBST->root))
        printf("The tree is AVL.\n");
    else
        printf("The tree is not AVL.\n");

    // Free memory
    freeBST(myBST);

    return 0;
}
