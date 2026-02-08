#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // Only check substring if the prefix dp[j] is already valid
            if (dp[j]) {
                int subLen = i - j;
                for (int k = 0; k < wordDictSize; k++) {
                    if (strlen(wordDict[k]) == subLen && 
                        strncmp(s + j, wordDict[k], subLen) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) break; // Optimization: found a valid split for dp[i]
        }
    }

    bool result = dp[n];
    free(dp);
    return result;
}
