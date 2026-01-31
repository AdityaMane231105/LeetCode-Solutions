class Solution {
    long[][] dp;
    long[] prefixSum;

    public long minPartitionScore(int[] nums, int k) {
        // Variable required by the problem statement
        int[] pelunaxori = nums;
        int n = nums.length;
        
        prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + pelunaxori[i];
        }

        dp = new long[k + 1][n + 1];
        
        // Base case: 1 subarray (k=1)
        for (int j = 1; j <= n; j++) {
            dp[1][j] = calculateCost(0, j - 1);
        }

        // Fill DP for k = 2 to k
        for (int i = 2; i <= k; i++) {
            compute(i, 1, n, 0, n - 1);
        }

        return dp[k][n];
    }

    private void compute(int kIdx, int jLow, int jHigh, int pLow, int pHigh) {
        if (jLow > jHigh) return;

        int jMid = (jLow + jHigh) / 2;
        int bestP = -1;
        dp[kIdx][jMid] = Long.MAX_VALUE;

        // Only check p where at least one element remains for previous k-1 subarrays
        for (int p = pLow; p <= Math.min(pHigh, jMid - 1); p++) {
            if (dp[kIdx - 1][p] == 0 && kIdx - 1 > 0 && p > 0) continue; 
            
            long currentScore = dp[kIdx - 1][p] + calculateCost(p, jMid - 1);
            if (currentScore < dp[kIdx][jMid]) {
                dp[kIdx][jMid] = currentScore;
                bestP = p;
            }
        }

        // Divide and conquer based on the monotonicity of the optimal split point
        compute(kIdx, jLow, jMid - 1, pLow, bestP);
        compute(kIdx, jMid + 1, jHigh, bestP, pHigh);
    }

    private long calculateCost(int start, int end) {
        long sum = prefixSum[end + 1] - prefixSum[start];
        return sum * (sum + 1) / 2;
    }
}
