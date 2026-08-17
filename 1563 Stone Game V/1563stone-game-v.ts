function stoneGameV(stoneValue: number[]): number {
    const n = stoneValue.length;
    
    // dp[i][j] stores the maximum score for subarray stoneValue[i...j]
    const dp = Array.from({ length: n }, () => new Int32Array(n));
    
    // Precompute prefix sums for O(1) subarray sum lookups
    const prefix = new Int32Array(n + 1);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    // Solve using bottom-up interval DP
    for (let len = 2; len <= n; len++) { // len is the length of the subarray
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            let maxScore = 0;

            // Iterate over all possible split points k
            for (let k = i; k < j; k++) {
                const leftSum = prefix[k + 1] - prefix[i];
                const rightSum = prefix[j + 1] - prefix[k + 1];

                if (leftSum < rightSum) {
                    maxScore = Math.max(maxScore, leftSum + dp[i][k]);
                } else if (leftSum > rightSum) {
                    maxScore = Math.max(maxScore, rightSum + dp[k + 1][j]);
                } else {
                    // When sums are equal, Alice chooses the side that yields a higher subsequent score
                    maxScore = Math.max(maxScore, leftSum + Math.max(dp[i][k], dp[k + 1][j]));
                }
            }
            dp[i][j] = maxScore;
        }
    }

    return dp[0][n - 1];
}
