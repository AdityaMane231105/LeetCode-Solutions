class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # Create a 2D DP array initialized with 1s
        # (The first row and first column will stay 1 because there's only one way to reach them)
        dp = [[1] * n for _ in range(m)]
        
        # Start from cell (1, 1) and fill the table
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[m-1][n-1]
