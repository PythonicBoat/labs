// In addition to Q8.1, display BFS traversal sequence of the undirected graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = vertex;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int vertex = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return vertex;
}

// Function to perform BFS traversal
void BFS(int adj[MAX_VERTICES][MAX_VERTICES], int V, int startVertex) {
    // Mark all vertices as not visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Enqueue the start vertex and mark it as visited
    enqueue(startVertex);
    visited[startVertex] = 1;

    // Print the BFS traversal
    printf("BFS Traversal: ");

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int V;  // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int adj[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(adj, V, startVertex);

    return 0;
}
