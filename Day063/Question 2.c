/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.*/

int original;

void dfs(int** image, int m, int n, int r, int c, int color) {
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (image[r][c] != original)
        return;

    image[r][c] = color;

    dfs(image, m, n, r + 1, c, color);
    dfs(image, m, n, r - 1, c, color);
    dfs(image, m, n, r, c + 1, color);
    dfs(image, m, n, r, c - 1, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];

    original = image[sr][sc];

    if (original != color)
        dfs(image, m, n, sr, sc, color);

    *returnSize = m;
    *returnColumnSizes = imageColSize;

    return image;
}
