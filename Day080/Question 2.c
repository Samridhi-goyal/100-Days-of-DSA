/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and 
weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and
whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.*/

#include <limits.h>
#include <stdlib.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
{
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX / 2;
        }
    }

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int city = -1;
    int minCount = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] <= distanceThreshold)
                count++;
        }

        if (count <= minCount)
        {
            minCount = count;
            city = i;
        }
    }

    return city;
}
 
