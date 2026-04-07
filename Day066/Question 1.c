/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, bool visited[], bool recStack[], int adj[][100], int size[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, adj, size))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100];
    int size[100] = {0};
    bool visited[100] = {false};
    bool recStack[100] = {false};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, size)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
