class Solution {
    private TreeNode first = null;
    private TreeNode second = null;
    private TreeNode prev = null; // Initialize to null

    public void recoverTree(TreeNode root) {
        traverse(root);
        // ... (rest of the swap logic remains the same)
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    private void traverse(TreeNode root) {
        if (root == null) return;

        traverse(root.left);

        if (prev != null && prev.val >= root.val) {
            // First violation
            if (first == null) {
                first = prev;
            }
            // Second violation
            second = root;
        }
        prev = root;

        traverse(root.right);
    }
}
