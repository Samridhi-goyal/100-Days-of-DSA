/*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.*/

int cameras;

int dfs(struct TreeNode* root) {
    if (!root) return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 2 || right == 2) {
        cameras++;
        return 0;
    }

    if (left == 0 || right == 0)
        return 1;

    return 2;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 2)
        cameras++;
    return cameras;
}
