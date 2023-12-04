// WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of each vertex.

#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int numVertices;
    int **adjMatrix;
    int *visited;
};

struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = malloc(vertices * sizeof(int *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = malloc(vertices * sizeof(int));
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    // Add edge from src to dest
    graph->adjMatrix[src][dest] = 1;

    // Add edge from dest to src
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(struct Graph *graph) {
    int v, w;
    for (v = 0; v < graph->numVertices; v++) {
        printf("\nAdjacency list of vertex %d\n", v);
        for (w = 0; w < graph->numVertices; w++) {
            if (graph->adjMatrix[v][w]) {
                printf("%d -> ", w);
            }
        }
        printf("NULL\n");
    }
}

int degree(struct Graph *graph, int vertex) {
    int degree = 0;
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        if (graph->adjMatrix[vertex][v]) {
            degree++;
        }
    }
    return degree;
}

int main() {
    int vertices = 5;
    struct Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    int v;
    for (v = 0; v < vertices; v++) {
        printf("Degree of vertex %d: %d\n", v, degree(graph, v));
    }

    return 0;
}