//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    queue[rear++] = root;
    int level = 0;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        (*returnColumnSizes)[level] = size;
        result[level] = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : (size - 1 - i);
            result[level][index] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        leftToRight = !leftToRight;
        level++;
    }

    *returnSize = level;
    return result;
}
