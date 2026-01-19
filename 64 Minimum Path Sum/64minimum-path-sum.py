class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])

        # Fill the first row (only can come from left)
        for j in range(1, n):
            grid[0][j] += grid[0][j-1]

        # Fill the first column (only can come from above)
        for i in range(1, m):
            grid[i][0] += grid[i-1][0]

        # Fill the rest of the grid
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])

        return grid[-1][-1]
