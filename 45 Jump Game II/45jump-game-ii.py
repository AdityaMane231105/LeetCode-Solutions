class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # If the array has only one element, 0 jumps are needed
        if len(nums) <= 1:
            return 0
        
        jumps = 0
        current_end = 0
        farthest = 0
        
        # Iterate to n-1 because we don't need to jump once we reach the last element
        for i in range(len(nums) - 1):
            # Update the farthest index we can reach from the current position
            farthest = max(farthest, i + nums[i])
            
            # If we've reached the end of the range for the current jump
            if i == current_end:
                jumps += 1
                current_end = farthest
                
                # Optimization: if current_end already reaches or passes the last index, break
                if current_end >= len(nums) - 1:
                    break
                    
        return jumps
