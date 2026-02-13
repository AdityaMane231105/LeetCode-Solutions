#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, 
               int*** res, int* path, bool* used, int depth) {
    if (depth == numsSize) {
        // Add current path to results
        *res = realloc(*res, sizeof(int*) * (*returnSize + 1));
        (*res)[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy((*res)[*returnSize], path, sizeof(int) * numsSize);
        
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        (*returnColumnSizes)[*returnSize] = numsSize;
        
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        // Skip used elements or duplicates
        // !used[i-1] ensures we only process the duplicate if the previous one is already active
        if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
            continue;
        }

        used[i] = true;
        path[depth] = nums[i];
        backtrack(nums, numsSize, returnSize, returnColumnSizes, res, path, used, depth + 1);
        used[i] = false; // Undo move
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sort to handle duplicates easily
    qsort(nums, numsSize, sizeof(int), compare);
    
    int** res = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    int* path = malloc(sizeof(int) * numsSize);
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    
    backtrack(nums, numsSize, returnSize, returnColumnSizes, &res, path, used, 0);
    
    free(path);
    free(used);
    return res;
}
