/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getDepth(struct TreeNode* root) {
    if (!root) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int depth = getDepth(root);
    *returnSize = depth;
    int** res = (int**)malloc(sizeof(int*) * depth);
    *returnColumnSizes = (int*)malloc(sizeof(int) * depth);

    // Standard BFS using a queue
    struct TreeNode* queue[2001]; // Constraint: max 2000 nodes
    int head = 0, tail = 0;
    queue[tail++] = root;

    int levelIndex = 0;
    while (head < tail) {
        int levelSize = tail - head;
        (*returnColumnSizes)[levelIndex] = levelSize;
        res[levelIndex] = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[head++];
            res[levelIndex][i] = curr->val;
            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
        levelIndex++;
    }

    // Reverse the results to get bottom-up
    for (int i = 0; i < depth / 2; i++) {
        // Swap level arrays
        int* tempRes = res[i];
        res[i] = res[depth - 1 - i];
        res[depth - 1 - i] = tempRes;

        // Swap column sizes
        int tempSize = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[depth - 1 - i];
        (*returnColumnSizes)[depth - 1 - i] = tempSize;
    }

    return res;
}
