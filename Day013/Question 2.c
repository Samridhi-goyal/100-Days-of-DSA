//Given an m x n matrix, return all elements of the matrix in spiral order.

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;
    
    int total = matrixSize * matrixColSize[0];
    int* result = (int*)malloc(sizeof(int) * total);
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            result[k++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[k++] = matrix[bottom][j];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;
    return result;
}
