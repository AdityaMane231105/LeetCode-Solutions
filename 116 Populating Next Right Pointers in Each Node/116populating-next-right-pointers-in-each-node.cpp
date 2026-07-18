class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* leftMost = root;
        
        // Loop down the levels of the tree
        while (leftMost->left) {
            Node* curr = leftMost;
            
            // Traverse the current level horizontally using established 'next' pointers
            while (curr) {
                // Connection 1: Link children belonging to the same parent
                curr->left->next = curr->right;
                
                // Connection 2: Link children belonging to adjacent parent nodes
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                
                // Move horizontally across the current level
                curr = curr->next;
            }
            
            // Move to the start of the next deeper level
            leftMost = leftMost->left;
        }
        
        return root;
    }
};
