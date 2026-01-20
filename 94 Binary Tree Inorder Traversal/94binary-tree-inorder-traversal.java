class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;

        while (curr != null || !stack.isEmpty()) {
            // 1. Reach the leftmost node of the current node
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            
            // 2. Current must be null at this point, pop from stack
            curr = stack.pop();
            result.add(curr.val); // Add the node value
            
            // 3. We have visited the node and its left subtree. 
            // Now, it's the right subtree's turn.
            curr = curr.right;
        }
        
        return result;
    }
}
