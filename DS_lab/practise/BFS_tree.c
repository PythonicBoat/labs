#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a queue node
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a tree node into the queue
void enqueue(struct Queue* queue, struct TreeNode* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a tree node from the queue
struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    struct TreeNode* data = queue->front->data;
    struct QueueNode* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Function to perform Breadth-First Tree Traversal
void breadthFirstTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Create a queue for BFS
    struct Queue* queue = createQueue();

    // Enqueue the root node
    enqueue(queue, root);

    printf("Breadth-First Tree Traversal: ");

    while (queue->front != NULL) {
        // Dequeue a node and print its data
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        // Enqueue the left and right children if they exist
        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    printf("\n");

    // Free allocated memory
    free(queue);
}

// Main function for testing
int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform Breadth-First Tree Traversal
    breadthFirstTraversal(root);

    // Free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
