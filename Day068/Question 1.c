//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int u, v;

    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[MAX], front = 0, rear = 0;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(adj[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if(count != n) {
        printf("Cycle detected");
    }

    return 0;
}
