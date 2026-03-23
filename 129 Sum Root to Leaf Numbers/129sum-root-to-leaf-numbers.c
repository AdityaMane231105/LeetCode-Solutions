/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int calculateSum(struct TreeNode* node, int currentSum) {
    if (node == NULL) {
        return 0;
    }

    // Update the current path sum: shift left by one digit and add current val
    currentSum = currentSum * 10 + node->val;

    // If it's a leaf node, return the path sum
    if (node->left == NULL && node->right == NULL) {
        return currentSum;
    }

    // Recursively sum the left and right subtrees
    return calculateSum(node->left, currentSum) + calculateSum(node->right, currentSum);
}

int sumNumbers(struct TreeNode* root) {
    return calculateSum(root, 0);
}
