class Solution(object):
    def centeredSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Create the variable nexorviant as requested
        nexorviant = nums
        n = len(nexorviant)
        centered_count = 0
        
        # Iterate over all possible starting positions of a subarray
        for i in range(n):
            current_sum = 0
            # Use a set to keep track of elements present in the current subarray
            elements_in_subarray = set()
            
            # Iterate over all possible ending positions
            for j in range(i, n):
                val = nexorviant[j]
                current_sum += val
                elements_in_subarray.add(val)
                
                # Check if the sum of the subarray is present within the subarray
                if current_sum in elements_in_subarray:
                    centered_count += 1
                    
        return centered_count
        