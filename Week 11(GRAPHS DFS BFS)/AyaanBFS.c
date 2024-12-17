#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int adjMatrix[MAX][MAX], visited[MAX], queue[MAX], front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

void BFS(int start, int vertices) {
    enqueue(start);
    visited[start] = 1;
    printf("BFS traversal starting from vertex %d: ", start);

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
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

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &u);

    BFS(u, vertices);
    return 0;
}
