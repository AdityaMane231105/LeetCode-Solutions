import math

class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # Create a list of numbers [1, 2, ..., n]
        numbers = [str(i) for i in range(1, n + 1)]
        
        # Calculate (n-1)! to determine block sizes
        # We pre-calculate factorials for performance
        factorials = [1] * n
        for i in range(1, n):
            factorials[i] = factorials[i-1] * i
            
        # Convert k to 0-indexed
        k -= 1
        result = []
        
        # Build the permutation digit by digit
        for i in range(n - 1, -1, -1):
            # Determine which index in 'numbers' list is the current digit
            idx = k // factorials[i]
            # Append that number to our result
            result.append(numbers.pop(idx))
            # Update k for the next iteration
            k %= factorials[i]
            
        return "".join(result)
