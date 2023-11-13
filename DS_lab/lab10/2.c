// In addition to the Q7.1, perform the following menu driven operations on BST.
// i. insert an element to the BST
// ii. display the largest element
// iii. display the smallest element
// iv. height of a node
// v. count number of leaf nodes

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int findMax(struct Node* root) {
    struct Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Display largest\n3. Display smallest\n4. Display height\n5. Count leaves\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Largest element: %d\n", findMax(root));
                break;
            case 3:
                printf("Smallest element: %d\n", findMin(root));
                break;
            case 4:
                printf("Height of tree: %d\n", height(root));
                break;
            case 5:
                printf("Number of leaves: %d\n", countLeaves(root));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}