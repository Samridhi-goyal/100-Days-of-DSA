/*In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls
into the baskets such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int position[], int n, int m, int dist) {
    int count = 1;
    int lastPos = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - lastPos >= dist) {
            count++;
            lastPos = position[i];

            if (count == m)
                return 1;
        }
    }

    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;
            low = mid + 1;   // try bigger distance
        } else {
            high = mid - 1;  // reduce distance
        }
    }

    return ans;
}
