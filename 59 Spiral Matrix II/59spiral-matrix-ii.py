class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        # Initialize an n x n matrix with zeros
        matrix = [[0] * n for _ in range(n)]
        
        # Define the boundaries
        left, right = 0, n - 1
        top, bottom = 0, n - 1
        
        num = 1
        while num <= n * n:
            # 1. Fill from Left to Right (along the Top row)
            for i in range(left, right + 1):
                matrix[top][i] = num
                num += 1
            top += 1 # Move the top boundary down
            
            # 2. Fill from Top to Bottom (along the Right column)
            for i in range(top, bottom + 1):
                matrix[i][right] = num
                num += 1
            right -= 1 # Move the right boundary left
            
            # 3. Fill from Right to Left (along the Bottom row)
            for i in range(right, left - 1, -1):
                matrix[bottom][i] = num
                num += 1
            bottom -= 1 # Move the bottom boundary up
            
            # 4. Fill from Bottom to Top (along the Left column)
            for i in range(bottom, top - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1 # Move the left boundary right
            
        return matrix
