/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    int *size = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        adj[i] = (int *)malloc(size[i] * sizeof(int));
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    int *visited = (int *)calloc(n, sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < size[node]; i++) {
            int v = adj[node][i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}
