//Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;
    
    int sum = 0;
    
    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    }
    
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    
    return sum;
}
