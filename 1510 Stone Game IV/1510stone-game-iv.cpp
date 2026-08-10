class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores whether the player whose turn it is can win with i stones left
        vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                // If removing j*j stones leaves the opponent in a losing state, we win
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break; // No need to check other moves for this state
                }
            }
        }
        
        return dp[n];
    }
};
