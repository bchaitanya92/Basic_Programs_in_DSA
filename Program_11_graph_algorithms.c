#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20

// Global variables
int G[MAX][MAX], n, visited[10];

// Function to create a graph
void Creation_Graph() {
    int i, j;

    // Input number of cities
    printf("Enter the Number of Cities: ");
    scanf("%d", &n);

    // Input edges for the cities
    printf("Enter the edges for the Cities:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // Display the adjacency matrix
    printf("Edges of the Cities are:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }
    printf("Adjacency matrix for the Cities is created successfully.\n");
}

// Depth First Search (DFS) for connectivity check
void dfs(int source) {
    int v;
    visited[source] = 1;
    
    // Traverse adjacent vertices
    for (v = 0; v < n; v++) {
        if (G[source][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
    return;
}

// Function to check reachability of vertices from a source vertex
void reachabilitycheck(int source) {
    int i;

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS starting from the source vertex
    dfs(source);

    // Display reachability information for each vertex
    for (i = 0; i < n; i++) {
        if (visited[i] == 1) {
            printf("Vertex %d is reachable\n", i);
        } else {
            printf("Vertex %d is not reachable\n", i);
        }
    }
}

void main() {
    int choice, source;

    // Menu-driven loop
    while (1) {
        printf("\n1. Create a graph.\n2. Test for connectivity.\n3. Exit.\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Creation_Graph();
                break;
            case 2:
                printf("Enter the source between 0 to %d: ", n - 1);
                scanf("%d", &source);
                printf("Source is %d\n", source);
                reachabilitycheck(source);
                break;
            case 3:
                exit(0);
            default:
                printf("\nEnter proper Choice.");
        }
    }
}
