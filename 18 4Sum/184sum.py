class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        res = []
        
        for i in range(n):
            # Skip duplicate values for the first number
            if i > 0 and nums[i] == nums[i-1]:
                continue
                
            for j in range(i + 1, n):
                # Skip duplicate values for the second number
                if j > i + 1 and nums[j] == nums[j-1]:
                    continue
                
                # Two-pointer approach for the remaining two numbers
                left, right = j + 1, n - 1
                while left < right:
                    curr_sum = nums[i] + nums[j] + nums[left] + nums[right]
                    
                    if curr_sum == target:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        # Skip duplicates for left and right pointers
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif curr_sum < target:
                        left += 1
                    else:
                        right -= 1
                        
        return res
