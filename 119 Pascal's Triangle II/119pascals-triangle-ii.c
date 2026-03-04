/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));
    
    // Initialize first element to 1
    row[0] = 1;
    
    for (int i = 1; i <= rowIndex; i++) {
        // The last element of every row is always 1
        row[i] = 1; 
        
        // Update the middle elements from right to left
        // row[j] = row[j] + row[j-1] (simulating the sum of two numbers above)
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }
    
    return row;
}
