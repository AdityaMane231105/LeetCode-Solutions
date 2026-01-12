class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        # k will keep track of the index for elements not equal to val
        k = 0
        
        for i in range(len(nums)):
            # If the current element is not the value we want to remove
            if nums[i] != val:
                # Move it to the front of the array at index k
                nums[k] = nums[i]
                # Increment k to the next available position
                k += 1
        
        # k represents the number of elements not equal to val
        return k
