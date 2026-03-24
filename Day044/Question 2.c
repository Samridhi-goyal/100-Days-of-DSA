//Given the root of a binary tree, return the preorder traversal of its nodes' values.

#include <stdlib.h>

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int*)malloc(10000 * sizeof(int));
    struct TreeNode* stack[10000];
    int top = -1, idx = 0;
    
    if (root != NULL) stack[++top] = root;
    
    while (top != -1) {
        struct TreeNode* node = stack[top--];
        res[idx++] = node->val;
        
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
    
    *returnSize = idx;
    return res;
}

