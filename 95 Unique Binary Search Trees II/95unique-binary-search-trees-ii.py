# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def generateTrees(self, n):
        if n == 0:
            return []
        
        def build(start, end):
            # Base case: if range is invalid, return [None] to represent an empty child
            if start > end:
                return [None]
            
            all_trees = []
            # Try every number in the current range as the root
            for i in range(start, end + 1):
                # Recursively generate all possible left and right subtrees
                left_subtrees = build(start, i - 1)
                right_subtrees = build(i + 1, end)
                
                # Combine every left subtree with every right subtree for the root 'i'
                for left in left_subtrees:
                    for right in right_subtrees:
                        root = TreeNode(i)
                        root.left = left
                        root.right = right
                        all_trees.append(root)
            
            return all_trees
        
        return build(1, n)
