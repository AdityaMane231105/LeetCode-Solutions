/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to compare two nodes and their subtrees
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // If both nodes are NULL, they are symmetric
    if (t1 == NULL && t2 == NULL) return true;
    
    // If only one is NULL, or values don't match, they aren't symmetric
    if (t1 == NULL || t2 == NULL) return false;
    if (t1->val != t2->val) return false;
    
    // Check if external children and internal children are mirrors
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}
