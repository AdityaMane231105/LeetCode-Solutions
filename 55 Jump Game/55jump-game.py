class Solution(object):
    def canJump(self, nums):
        maxReach = 0
        n = len(nums)
        
        for i in range(n):
            # If current index is beyond max reachable index
            if i > maxReach:
                return False
            
            # Update the farthest reachable index
            maxReach = max(maxReach, i + nums[i])
            
            # If we can already reach the last index
            if maxReach >= n - 1:
                return True
        
        return True