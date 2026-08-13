class Node:
    def __init__(self, char=None):
        if char is not None:
            self.max_len = 1
            self.pref_len = 1
            self.suff_len = 1
            self.left_char = char
            self.right_char = char
        else:
            self.max_len = 0
            self.pref_len = 0
            self.suff_len = 0
            self.left_char = ''
            self.right_char = ''

class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        tree = [None] * (4 * n)
        
        def merge(left_node: Node, right_node: Node, left_size: int, right_size: int) -> Node:
            parent = Node()
            parent.left_char = left_node.left_char
            parent.right_char = right_node.right_char
            
            # Base combination from children
            parent.max_len = max(left_node.max_len, right_node.max_len)
            parent.pref_len = left_node.pref_len
            parent.suff_len = right_node.suff_len
            
            # Bridge connection if characters touch and match
            if left_node.right_char == right_node.left_char:
                combined = left_node.suff_len + right_node.pref_len
                parent.max_len = max(parent.max_len, combined)
                
                if left_node.pref_len == left_size:
                    parent.pref_len = left_node.pref_len + right_node.pref_len
                if right_node.suff_len == right_size:
                    parent.suff_len = right_node.suff_len + left_node.suff_len
                    
            return parent

        def build(node, start, end):
            if start == end:
                tree[node] = Node(s[start])
                return
            mid = (start + end) // 2
            build(2 * node, start, mid)
            build(2 * node + 1, mid + 1, end)
            tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid)

        def update(node, start, end, idx, char):
            if start == end:
                tree[node] = Node(char)
                return
            mid = (start + end) // 2
            if idx <= mid:
                update(2 * node, start, mid, idx, char)
            else:
                update(2 * node + 1, mid + 1, end, idx, char)
            tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid)

        # Initialize the tree
        build(1, 0, n - 1)
        
        # Process each query
        ans = []
        for char, idx in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, idx, char)
            ans.append(tree[1].max_len)
            
        return ans
