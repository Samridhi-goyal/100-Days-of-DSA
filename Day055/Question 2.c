//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    int* result = (int*)malloc(2000 * sizeof(int));
    int level = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;

            if (i == size - 1)
                result[level++] = node->val;
        }
    }

    *returnSize = level;
    return result;
}
