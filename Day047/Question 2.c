/*Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

#include <stdlib.h>

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    int depth = 0;

    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        depth++;
    }

    return depth;
}
