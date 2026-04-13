/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int visited[n];
    int minDist[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        visited[u] = 1;
        result += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }

    return result;
}
