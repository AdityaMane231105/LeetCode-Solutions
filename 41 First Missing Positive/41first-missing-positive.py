class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        
        # 1. Cyclic Sort: Put each number x at index x-1 if possible
        for i in range(n):
            # While the current number is in the valid range [1, n]
            # AND it's not in its correct position (nums[i] - 1)
            # AND the target position doesn't already have the correct value
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                # Swap nums[i] with the element at its correct target index
                target_idx = nums[i] - 1
                nums[i], nums[target_idx] = nums[target_idx], nums[i]
        
        # 2. Find the first index that doesn't match its value
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        
        # 3. If all numbers 1 to n are present, the answer is n + 1
        return n + 1
