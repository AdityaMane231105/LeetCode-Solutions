#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] stores max difference (player - opponent) for sub-array piles[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: Sub-arrays of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }

        // Fill table for length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // Player chooses either left pile (i) or right pile (j)
                dp[i][j] = max(piles[i] - dp[i + 1][j], 
                               piles[j] - dp[i][j - 1]);
            }
        }

        // Alice wins if the net score difference for full array > 0
        return dp[0][n - 1] > 0;
    }
};
