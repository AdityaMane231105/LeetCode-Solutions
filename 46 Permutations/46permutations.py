class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        
        def backtrack(current_path):
            # Base case: if current path is same length as nums, we found a permutation
            if len(current_path) == len(nums):
                result.append(list(current_path))
                return
            
            for num in nums:
                # If number is already used in the current permutation, skip it
                if num in current_path:
                    continue
                
                # Choose the number
                current_path.append(num)
                # Recurse to build the next level
                backtrack(current_path)
                # Backtrack: remove the number to explore other options
                current_path.pop()
        
        backtrack([])
        return result
