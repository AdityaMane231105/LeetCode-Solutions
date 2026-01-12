class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones = 0
        twos = 0
        
        for num in nums:
            # Update 'ones' only if the bit is not in 'twos'
            ones = (ones ^ num) & ~twos
            
            # Update 'twos' only if the bit is not in the new 'ones'
            twos = (twos ^ num) & ~ones
            
        return ones
        