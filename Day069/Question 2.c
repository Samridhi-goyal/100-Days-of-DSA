/*You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 105

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

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int adj[MAX][MAX];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = -1;

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u][v] = w;
    }

    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    size = 0;
    dist[k] = 0;
    push(k, 0);

    while (size) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;

        if (d > dist[u]) continue;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != -1) {
                int newDist = dist[u] + adj[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(v, newDist);
                }
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
} 
