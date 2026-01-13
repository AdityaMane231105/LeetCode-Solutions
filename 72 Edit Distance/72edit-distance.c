#include <string.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    // Create a 2D array for DP
    int dp[m + 1][n + 1];

    // Base cases: 
    // Converting a string to an empty string requires i deletions
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    // Converting an empty string to a string requires j insertions
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                // If characters match, no new operation is needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // If characters don't match, take the minimum of:
                // 1. Replace: dp[i-1][j-1] + 1
                // 2. Delete:  dp[i-1][j] + 1
                // 3. Insert:  dp[i][j-1] + 1
                dp[i][j] = 1 + MIN3(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
