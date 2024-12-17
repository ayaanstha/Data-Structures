#include <stdio.h>

#define MAX 20

int adjMatrix[MAX][MAX], visited[MAX];

void DFS(int v, int vertices) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[v][i] && !visited[i])
            DFS(i, vertices);
    }
}

int main() {
    int vertices, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    DFS(0, vertices);
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            printf("Graph is not connected.\n");
            return 0;
        }
    }
    printf("Graph is connected.\n");
    return 0;
}
