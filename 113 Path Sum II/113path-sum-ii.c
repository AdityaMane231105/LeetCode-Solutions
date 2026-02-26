#include <stdlib.h>
#include <string.h>

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

void dfs(struct TreeNode* node, int targetSum, int currentSum, int* path, int pathLen, 
         int*** res, int* resSize, int** columnSizes, int* capacity) {
    if (!node) return;

    // Add current node to path
    path[pathLen++] = node->val;
    currentSum += node->val;

    // Check if it's a leaf and the sum matches
    if (!node->left && !node->right) {
        if (currentSum == targetSum) {
            // Resize result array if needed
            if (*resSize == *capacity) {
                *capacity *= 2;
                *res = (int**)realloc(*res, sizeof(int*) * (*capacity));
                *columnSizes = (int*)realloc(*columnSizes, sizeof(int) * (*capacity));
            }
            // Copy the current path into results
            (*res)[*resSize] = (int*)malloc(sizeof(int) * pathLen);
            memcpy((*res)[*resSize], path, sizeof(int) * pathLen);
            (*columnSizes)[*resSize] = pathLen;
            (*resSize)++;
        }
    } else {
        // Continue DFS to children
        dfs(node->left, targetSum, currentSum, path, pathLen, res, resSize, columnSizes, capacity);
        dfs(node->right, targetSum, currentSum, path, pathLen, res, resSize, columnSizes, capacity);
    }
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int capacity = 10;
    int** res = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * 5001); // Max nodes is 5000
    
    dfs(root, targetSum, 0, path, 0, &res, returnSize, returnColumnSizes, &capacity);
    
    free(path);
    return res;
}
