class Solution:
    def missingInteger(self, nums: list[int]) -> int:
        # Step 1: Find the longest sequential prefix
        prefix_sum = nums[0]
        i = 1
        while i < len(nums) and nums[i] == nums[i - 1] + 1:
            prefix_sum += nums[i]
            i += 1
            
        # Step 2: Use a set for fast O(1) lookups
        num_set = set(nums)
        
        # Step 3: Find the smallest missing integer >= prefix_sum
        while prefix_sum in num_set:
            prefix_sum += 1
            
        return prefix_sum
