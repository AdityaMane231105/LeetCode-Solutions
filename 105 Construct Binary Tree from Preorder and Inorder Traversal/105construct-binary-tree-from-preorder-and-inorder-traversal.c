struct TreeNode* helper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    // Base case: if there are no elements to construct the tree
    if (preStart > preEnd || inStart > inEnd) return NULL;

    // 1. Create the root node with the first element of the current preorder segment
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    
    // 2. Find the index of the root in the inorder array
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    // 3. Calculate the number of nodes in the left subtree
    int leftTreeSize = inIndex - inStart;

    // 4. Recursively build left and right subtrees
    // Left preorder range: skip current root, take 'leftTreeSize' elements
    root->left = helper(preorder, preStart + 1, preStart + leftTreeSize, 
                        inorder, inStart, inIndex - 1);
    
    // Right preorder range: everything after the left subtree elements
    root->right = helper(preorder, preStart + leftTreeSize + 1, preEnd, 
                         inorder, inIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return helper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
