#include <stdlib.h>
#include <math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    // Allocate maximum possible size (intervalsSize + 1)
    int** result = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    
    int i = 0; // Pointer for input intervals
    int j = 0; // Pointer for result array

    // Phase 1: Add intervals that end before the new interval starts
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[j] = (int*)malloc(sizeof(int) * 2);
        result[j][0] = intervals[i][0];
        result[j][1] = intervals[i][1];
        (*returnColumnSizes)[j] = 2;
        i++;
        j++;
    }

    // Phase 2: Merge overlapping intervals
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = (newInterval[0] < intervals[i][0]) ? newInterval[0] : intervals[i][0];
        newInterval[1] = (newInterval[1] > intervals[i][1]) ? newInterval[1] : intervals[i][1];
        i++;
    }
    // Add the final merged interval
    result[j] = (int*)malloc(sizeof(int) * 2);
    result[j][0] = newInterval[0];
    result[j][1] = newInterval[1];
    (*returnColumnSizes)[j] = 2;
    j++;

    // Phase 3: Add remaining intervals that start after the merged interval
    while (i < intervalsSize) {
        result[j] = (int*)malloc(sizeof(int) * 2);
        result[j][0] = intervals[i][0];
        result[j][1] = intervals[i][1];
        (*returnColumnSizes)[j] = 2;
        i++;
        j++;
    }

    *returnSize = j;
    return result;
}
