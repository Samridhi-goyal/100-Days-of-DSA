//Given the root of a binary tree, return the inorder traversal of its nodes' values.

#include <stdlib.h>

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int*)malloc(10000 * sizeof(int));
    struct TreeNode* stack[10000];
    int top = -1, idx = 0;
    
    while (root != NULL || top != -1) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        res[idx++] = root->val;
        root = root->right;
    }
    
    *returnSize = idx;
    return res;
}
