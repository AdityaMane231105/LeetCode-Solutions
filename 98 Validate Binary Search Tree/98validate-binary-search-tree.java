class Solution {
    private Integer prev = null;

    public boolean isValidBST(TreeNode root) {
        return inOrder(root);
    }

    private boolean inOrder(TreeNode node) {
        if (node == null) return true;
        
        if (!inOrder(node.left)) return false;
        
        if (prev != null && node.val <= prev) return false;
        prev = node.val;
        
        return inOrder(node.right);
    }
}
