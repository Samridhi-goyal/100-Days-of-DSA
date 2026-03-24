/*Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return (left > right ? left : right) + 1;
}
