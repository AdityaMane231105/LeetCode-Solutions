class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        # XOR x and y to find differing bits
        xor_result = x ^ y
        
        # Count the number of set bits (1s)
        # bin() converts the number to a binary string, e.g., '0b101'
        return bin(xor_result).count('1')
