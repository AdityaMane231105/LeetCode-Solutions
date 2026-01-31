class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // 1. Base case: If both nodes are null, the trees are identical at this point
        if (p == null && q == null) {
            return true;
        }
        
        // 2. Mismatch: If only one node is null, or values differ, they are not the same
        if (p == null || q == null || p.val != q.val) {
            return false;
        }
        
        // 3. Recursive step: Check if both left and right subtrees are identical
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
