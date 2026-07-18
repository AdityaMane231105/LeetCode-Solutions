class Solution {
    // Global variable to keep track of the maximum path sum found so far
    private int globalMaxSum;

    public int maxPathSum(TreeNode root) {
        globalMaxSum = Integer.MIN_VALUE;
        calculateGain(root);
        return globalMaxSum;
    }

    private int calculateGain(TreeNode node) {
        if (node == null) {
            return 0;
        }

        // 1. Recursively get the maximum gain from left and right subtrees
        // If the path sum from a subtree is negative, we ignore it by taking Math.max(..., 0)
        int leftGain = Math.max(calculateGain(node.left), 0);
        int rightGain = Math.max(calculateGain(node.right), 0);

        // 2. Compute the price of the new path peaking at the current node
        int currentPathSum = node.val + leftGain + rightGain;

        // 3. Update the global maximum path sum tracker if the current path is larger
        globalMaxSum = Math.max(globalMaxSum, currentPathSum);

        // 4. Return the maximum gain the current node can provide to its parent node
        // A valid path can only extend into one of the child branches, not both
        return node.val + Math.max(leftGain, rightGain);
    }
}
