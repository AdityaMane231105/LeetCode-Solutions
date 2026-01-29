class Solution {
    public int maxDepth(TreeNode root) {
        // Base case: if the node is null, the depth is 0
        if (root == null) {
            return 0;
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftHeight = maxDepth(root.left);
        int rightHeight = maxDepth(root.right);
        
        // The current node's depth is 1 + the max of its children
        return Math.max(leftHeight, rightHeight) + 1;
    }
}


