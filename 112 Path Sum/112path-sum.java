class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;

        // If this is a leaf node
        if (root.left == null && root.right == null) {
            return targetSum == root.val;
        }

        // Recur for left and right subtrees
        int remainingSum = targetSum - root.val;

        return hasPathSum(root.left, remainingSum) ||
               hasPathSum(root.right, remainingSum);
    }
}