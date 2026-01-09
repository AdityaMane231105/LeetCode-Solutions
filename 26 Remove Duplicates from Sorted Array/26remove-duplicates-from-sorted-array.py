class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        # 'k' is the pointer for the position of the last unique element found
        k = 1 
        
        # Iterate through the array starting from the second element
        for i in range(1, len(nums)):
            # If the current element is different from the previous unique element
            if nums[i] != nums[i - 1]:
                # Move it to the 'k'th position
                nums[k] = nums[i]
                # Increment the count of unique elements
                k += 1
        
        # Return the number of unique elements
        return k
        