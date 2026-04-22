class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                
                // Link the current right subtree to the rightmost of left
                prev->right = curr->right;
                
                // Move the left subtree to the right and nullify the left
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node on the right
            curr = curr->right;
        }
    }
};
