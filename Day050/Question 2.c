/*You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.*/

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) return root;
        else if (val < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}
