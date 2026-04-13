//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX * MAX];
int size = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size++;
    while (i && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < size && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r < size && heap[r].dist < heap[smallest].dist) smallest = r;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return root;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int adj[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    int u, v, w;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size) {
        HeapNode top = pop();
        int node = top.node;
        int d = top.dist;

        if (d > dist[node]) continue;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                int newDist = dist[node] + adj[node][i];
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                    push(i, newDist);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}
