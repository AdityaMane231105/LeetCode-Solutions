class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = 0, rightHeight = 0;
        TreeNode *l = root, *r = root;

        // Calculate height of the leftmost path
        while (l) {
            leftHeight++;
            l = l->left;
        }

        // Calculate height of the rightmost path
        while (r) {
            rightHeight++;
            r = r->right;
        }

        // If heights are the same, it's a perfect binary tree
        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }

        // Otherwise, recurse for left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
