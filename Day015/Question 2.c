/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.*/

 void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int firstRow = 0, firstCol = 0;

    for(int j = 0; j < cols; j++)
        if(matrix[0][j] == 0) firstRow = 1;

    for(int i = 0; i < rows; i++)
        if(matrix[i][0] == 0) firstCol = 1;

    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRow) {
        for(int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    if(firstCol) {
        for(int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
}
