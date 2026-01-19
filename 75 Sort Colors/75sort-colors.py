class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        low = 0          # Pointer for the next position of 0
        mid = 0          # Current element being inspected
        high = len(nums) - 1  # Pointer for the next position of 2

        while mid <= high:
            if nums[mid] == 0:
                # Swap current element with the low pointer
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                # If it's 1, it's already in the "middle", just move mid
                mid += 1
            else: # nums[mid] == 2
                # Swap current element with the high pointer
                nums[mid], nums[high] = nums[high], nums[mid]
                # Do not increment mid here because the swapped element 
                # from high hasn't been inspected yet
                high -= 1
