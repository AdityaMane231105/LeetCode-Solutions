class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 2:
            return len(nums)
        
        # 'k' is the pointer where the next valid element should be placed.
        # The first two elements are always allowed.
        k = 2
        
        for i in range(2, len(nums)):
            # Compare the current element with the element two positions
            # behind the current 'k' pointer.
            if nums[i] != nums[k - 2]:
                nums[k] = nums[i]
                k += 1
                
        return k
