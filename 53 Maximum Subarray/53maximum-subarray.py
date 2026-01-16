class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize max_sum with the first element to handle cases with all negative numbers
        max_sum = nums[0]
        current_sum = 0
        
        for n in nums:
            # If current_sum is negative, discard it and start fresh with the current number
            if current_sum < 0:
                current_sum = 0
            
            current_sum += n
            # Update the global maximum if the current subarray sum is larger
            max_sum = max(max_sum, current_sum)
            
        return max_sum
        