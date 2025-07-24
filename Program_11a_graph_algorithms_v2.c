#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int G[MAX][MAX], n, visited[10];
void Creation_Graph() {
    printf("Enter the Number of Cities: ");
    scanf("%d", &n);
    printf("Enter the edges for the Cities:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Edges of the Cities are:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", G[i][j]);
        printf("\n");
    }
    printf("Adjacency matrix for the Cities is created successfully.\n");
}
void dfs(int source) {
    visited[source] = 1;
    for (int v = 0; v < n; v++)
        if (G[source][v] == 1 && !visited[v])
            dfs(v);
}
void reachabilitycheck(int source) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    dfs(source);
    for (int i = 0; i < n; i++)
        printf("Vertex %d is %sreachable\n", i, visited[i] ? "" : "not ");
}
void main() {
    int choice, source;
    while (1) {
        printf("\n1. Create a graph.\n2. Test for connectivity.\n3. Exit.\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Creation_Graph();break;
            case 2:
                printf("Enter the source between 0 to %d: ", n - 1);
                scanf("%d", &source);
                printf("Source is %d\n", source);
                reachabilitycheck(source);break;
            case 3:
                exit(0);
            default:
                printf("\nEnter proper Choice.");
        }
    }
}