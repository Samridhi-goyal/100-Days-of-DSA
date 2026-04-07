/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO   c code without comments*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void addEdge(int u, int v, int adj[][100], int *size) {
    adj[u][size[u]++] = v;
    adj[v][size[v]++] = u;
}

bool dfs(int node, int parent, bool visited[], int adj[][100], int size[]) {
    visited[node] = true;
    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, size))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100];
    int size[100] = {0};
    bool visited[100] = {false};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v, adj, size);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
