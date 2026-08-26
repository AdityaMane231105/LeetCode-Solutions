class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0
        zeros = 0
        max_len = 0
        
        for right in range(len(nums)):
            # If we encounter a 0, increase the zero counter
            if nums[right] == 0:
                zeros += 1
                
            # If there are more than 1 zeros, shrink the window from the left
            while zeros > 1:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
                
            # The length of the window minus 1 element (the deleted one) is right - left
            max_len = max(max_len, right - left)
            
        return max_len
