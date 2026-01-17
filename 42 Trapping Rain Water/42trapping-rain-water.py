class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]
        water_trapped = 0
        
        while left < right:
            # We always move the pointer pointing to the shorter bar
            if left_max < right_max:
                left += 1
                # Update the left_max
                left_max = max(left_max, height[left])
                # Water trapped is the diff between current height and max boundary
                water_trapped += left_max - height[left]
            else:
                right -= 1
                # Update the right_max
                right_max = max(right_max, height[right])
                # Water trapped is the diff between current height and max boundary
                water_trapped += right_max - height[right]
                
        return water_trapped
