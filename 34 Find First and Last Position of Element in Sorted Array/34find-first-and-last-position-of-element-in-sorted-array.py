class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def findBound(isFirst):
            low, high = 0, len(nums) - 1
            bound = -1
            
            while low <= high:
                mid = (low + high) // 2
                
                if nums[mid] == target:
                    bound = mid
                    if isFirst:
                        # If looking for the first index, look to the left
                        high = mid - 1
                    else:
                        # If looking for the last index, look to the right
                        low = mid + 1
                elif nums[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
            return bound

        start = findBound(isFirst=True)
        # If the start is -1, the target isn't in the array at all
        if start == -1:
            return [-1, -1]
        
        end = findBound(isFirst=False)
        
        return [start, end]
