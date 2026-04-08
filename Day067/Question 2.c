There are a total of numCourses courses /*you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array. leetcode version*/

#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++)
        adj[i] = (int*)malloc(numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            indegree[v]--;
            if (indegree[v] == 0)
                queue[rear++] = v;
        }
    }

    if (count != numCourses) {
        *returnSize = 0;
        return result;
    }

    *returnSize = count;
    return result;
}
