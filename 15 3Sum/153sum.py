class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()  # Sort the array to use two pointers and handle duplicates

        for i in range(len(nums)):
            # If the current value is greater than 0, no triplet can sum to 0
            if nums[i] > 0:
                break
            
            # Skip duplicate values for the first element of the triplet
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            # Initialize two pointers
            l, r = i + 1, len(nums) - 1
            while l < r:
                three_sum = nums[i] + nums[l] + nums[r]
                
                if three_sum > 0:
                    r -= 1
                elif three_sum < 0:
                    l += 1
                else:
                    res.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    # Skip duplicate values for the second element to avoid duplicate triplets
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                        
        return res
