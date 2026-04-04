/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.*/

void dfs(int i, int n, int** isConnected, int visited[]) {
    visited[i] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(j, n, isConnected, visited);
        }
    }
}

int findCircleNum(int** isConnected, int n, int* isConnectedColSize) {
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, isConnected, visited);
            count++;
        }
    }

    return count;
}
