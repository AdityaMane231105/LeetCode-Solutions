#include <stdlib.h>
#include <string.h>

void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, 
               int** result, int* returnSize, int* returnColumnSizes) {
    
    // Add the current path to the result
    result[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    memcpy(result[*returnSize], path, pathSize * sizeof(int));
    returnColumnSizes[*returnSize] = pathSize;
    (*returnSize)++;

    // Explore candidates
    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i]; // Choose
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, result, returnSize, returnColumnSizes); // Explore
        // Implicitly "un-choose" by the next iteration of the loop overwriting path[pathSize]
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Total subsets for unique elements is 2^n
    int totalSubsets = 1 << numsSize; 
    
    int** result = (int**)malloc(totalSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));
    
    backtrack(nums, numsSize, 0, path, 0, result, returnSize, *returnColumnSizes);
    
    free(path);
    return result;
}
