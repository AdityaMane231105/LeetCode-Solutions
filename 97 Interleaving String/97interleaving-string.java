import java.util.*;

class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length();
        int n = s2.length();
        
        // Logical check: If combined lengths don't match s3, it's impossible.
        if (m + n != s3.length()) {
            return false;
        }

        // dp[j] will represent if s3[0...i+j-1] can be formed by s1[0...i-1] and s2[0...j-1]
        boolean[] dp = new boolean[n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    // Base case: empty strings match empty s3
                    dp[j] = true;
                } else if (i == 0) {
                    // First row: can we form s3 using only s2?
                    dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
                } else if (j == 0) {
                    // First column: can we form s3 using only s1?
                    // Note: dp[j] here still holds the value from the previous i (i-1, 0)
                    dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i - 1);
                } else {
                    // Current cell depends on:
                    // 1. Top cell (using s1): dp[j]
                    // 2. Left cell (using s2): dp[j-1]
                    dp[j] = (dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || 
                            (dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
        }

        return dp[n];
    }
}
