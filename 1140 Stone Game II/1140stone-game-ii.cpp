#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    vector<int> suffix_sum;
    vector<vector<int>> memo;

    int solve(int i, int M, const vector<int>& piles) {
        // Base case: If we can take all remaining piles, take them all
        if (i + 2 * M >= n) {
            return suffix_sum[i];
        }
        
        // Return cached result if already calculated
        if (memo[i][M] != 0) {
            return memo[i][M];
        }

        int max_stones = 0;
        // Try taking X piles where 1 <= X <= 2M
        for (int X = 1; X <= 2 * M; ++X) {
            int next_stones = solve(i + X, max(M, X), piles);
            // Current player's score is total remaining minus opponent's optimal score
            max_stones = max(max_stones, suffix_sum[i] - next_stones);
        }

        return memo[i][M] = max_stones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix_sum.resize(n + 1, 0);
        // Precompute suffix sums for O(1) remaining stone calculation
        for (int i = n - 1; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }

        // M can grow up to n, so we size the memo table accordingly
        memo.resize(n, vector<int>(n + 1, 0));

        return solve(0, 1, piles);
    }
};
