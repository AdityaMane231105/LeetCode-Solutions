#include <stdlib.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    
    // Allocate DP array (size = last row size)
    int *dp = (int*)malloc(triangleColSize[triangleSize - 1] * sizeof(int));
    
    // Copy last row into dp
    for(int i = 0; i < triangleColSize[triangleSize - 1]; i++) {
        dp[i] = triangle[triangleSize - 1][i];
    }
    
    // Start from second last row upwards
    for(int i = triangleSize - 2; i >= 0; i--) {
        for(int j = 0; j < triangleColSize[i]; j++) {
            if(dp[j] < dp[j + 1])
                dp[j] = triangle[i][j] + dp[j];
            else
                dp[j] = triangle[i][j] + dp[j + 1];
        }
    }
    
    int result = dp[0];
    free(dp);
    
    return result;
}