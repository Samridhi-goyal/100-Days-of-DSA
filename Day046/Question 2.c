//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

#include <stdlib.h>

#define MAX 20000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** res = (int**)malloc(MAX * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX * sizeof(int));

    struct TreeNode* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int size = rear - front;
        res[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            res[level][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        level++;
    }

    *returnSize = level;
    return res;
}
