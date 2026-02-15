#include <string.h>
#include <stdint.h>

int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    // Use unsigned long long to prevent overflow during intermediate steps,
    // though the problem guarantees the final result fits in a 32-bit int.
    unsigned long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    
    // Base case: An empty t can be formed by any prefix of s in exactly 1 way.
    dp[0] = 1;
    
    for (int i = 1; i <= m; i++) {
        // Iterate backwards to use the results from the previous 's' character
        for (int j = n; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    
    return (int)dp[n];
}
