/*There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network 
where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.*/

#include <stdlib.h>

int timer;

void dfs(int u, int parent, int* disc, int* low, int** graph, int* graphColSize, int** res, int* returnSize) {
    disc[u] = low[u] = ++timer;

    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, graph, graphColSize, res, returnSize);
            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                res[*returnSize][0] = u;
                res[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        graphColSize[connections[i][0]]++;
        graphColSize[connections[i][1]]++;
    }

    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(graphColSize[i] * sizeof(int));
        graphColSize[i] = 0;
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0], v = connections[i][1];
        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) disc[i] = -1;

    int** res = (int**)malloc(connectionsSize * sizeof(int*));
    *returnSize = 0;

    for (int i = 0; i < connectionsSize; i++) {
        res[i] = (int*)malloc(2 * sizeof(int));
    }

    timer = 0;
    dfs(0, -1, disc, low, graph, graphColSize, res, returnSize);

    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return res;
}

