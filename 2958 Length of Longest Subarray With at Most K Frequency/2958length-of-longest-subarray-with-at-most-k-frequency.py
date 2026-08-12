from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        count = defaultdict(int)
        left = 0
        max_len = 0
        
        for right in range(len(nums)):
            # Expand the window and include the current element
            count[nums[right]] += 1
            
            # Shrink the window if the frequency of the current element exceeds k
            while count[nums[right]] > k:
                count[nums[left]] -= 1
                left += 1
                
            # Update the maximum length found so far
            max_len = max(max_len, right - left + 1)
            
        return max_len
