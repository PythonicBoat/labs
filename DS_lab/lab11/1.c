// WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of each vertex. 

#include <stdio.h>

int N, M;

// Function to create Adjacency Matrix
void createAdjMatrix(int Adj[][N + 1],
					int arr[][2])
{
	for (int i = 0; i < N + 1; i++) {

		for (int j = 0; j < N + 1; j++) {
			Adj[i][j] = 0;
		}
	}

	// Traverse the array of Edges
	for (int i = 0; i < M; i++) {

		// Find X and Y of Edges
		int x = arr[i][0];
		int y = arr[i][1];

		// Update value to 1
		Adj[x][y] = 1;
		Adj[y][x] = 1;
	}
}

void printAdjMatrix(int Adj[][N + 1])
{	// Traverse the Adj[][]
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {

			// Print the value at Adj[i][j]
			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	N = 5;
	// Given Edges
	int arr[][2]
		= { { 1, 2 }, { 2, 3 }, 
			{ 4, 5 }, { 1, 5 } };

	// Number of Edges
	M = sizeof(arr) / sizeof(arr[0]);

	// For Adjacency Matrix
	int Adj[N + 1][N + 1];
	createAdjMatrix(Adj, arr);

	// Print Adjacency Matrix
	printAdjMatrix(Adj); 

	return 0;
}
