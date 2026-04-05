/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int queue[10000][2];
    int front = 0, rear = 0;
    int fresh = 0, time = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            if(grid[i][j] == 1) fresh++;
        }
    }

    int d[5] = {0,1,0,-1,0};

    while(front < rear && fresh > 0) {
        int size = rear - front;
        time++;
        while(size--) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for(int i = 0; i < 4; i++) {
                int nx = x + d[i];
                int ny = y + d[i+1];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
    }

    return fresh == 0 ? time : -1;
}
