#include <stdlib.h>
#include <string.h>

/**
 * Comparator for qsort to sort the input array.
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Backtracking function to generate subsets.
 */
void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, 
               int*** result, int* returnSize, int** returnColumnSizes, int* capacity) {
    
    // 1. Add the current path to the result
    if (*returnSize >= *capacity) {
        *capacity *= 2;
        *result = realloc(*result, sizeof(int*) * (*capacity));
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*capacity));
    }
    
    (*result)[*returnSize] = malloc(sizeof(int) * pathSize);
    memcpy((*result)[*returnSize], path, sizeof(int) * pathSize);
    (*returnColumnSizes)[*returnSize] = pathSize;
    (*returnSize)++;

    // 2. Explore further elements
    for (int i = start; i < numsSize; i++) {
        // Skip duplicates: if the current element is the same as the previous 
        // and it's not the start of this recursion level.
        if (i > start && nums[i] == nums[i - 1]) continue;

        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, 
                  result, returnSize, returnColumnSizes, capacity);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the array to group duplicates together
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 100; // Initial capacity for the result array
    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int* path = malloc(sizeof(int) * numsSize);
    
    backtrack(nums, numsSize, 0, path, 0, &result, returnSize, returnColumnSizes, &capacity);
    
    free(path);
    return result;
}
