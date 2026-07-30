/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>

class BSTIterator {
private:
    std::stack<TreeNode*> nodeStack;

    // Helper function to push all left children of a node onto the stack
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    // O(h) time to find the smallest element, O(h) space
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    // Amortised O(1) time complexity
    int next() {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();
        
        // If the popped node has a right child, process its left branch
        if (currentNode->right != nullptr) {
            pushAllLeft(currentNode->right);
        }
        
        return currentNode->val;
    }
    
    // O(1) time complexity
    bool hasNext() {
        return !nodeStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
