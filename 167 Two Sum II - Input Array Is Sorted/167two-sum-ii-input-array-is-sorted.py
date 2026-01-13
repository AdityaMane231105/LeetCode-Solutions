class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            current_sum = numbers[left] + numbers[right]
            
            if current_sum == target:
                # The problem uses 1-based indexing, so add 1 to each index
                return [left + 1, right + 1]
            elif current_sum < target:
                # Sum is too small, move the left pointer forward to increase it
                left += 1
            else:
                # Sum is too large, move the right pointer backward to decrease it
                right -= 1
                