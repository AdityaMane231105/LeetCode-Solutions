#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0) return false;

    int m = matrixSize;          // Number of rows
    int n = matrixColSize[0];    // Number of columns
    int low = 0;
    int high = m * n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Map 1D index back to 2D coordinates
        int row = mid / n;
        int col = mid % n;
        int val = matrix[row][col];

        if (val == target) {
            return true;
        } else if (val < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}
