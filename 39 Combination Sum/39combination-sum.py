class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results = []

        def backtrack(remaining, combo, start_index):
            # Base Case: If remaining target is 0, we found a valid combination
            if remaining == 0:
                results.append(list(combo))
                return
            # Base Case: If remaining target is negative, this path is invalid
            if remaining < 0:
                return

            for i in range(start_index, len(candidates)):
                # Add the number to the current combination
                combo.append(candidates[i])
                
                # Recursively call with the same index 'i' (allows reuse of the same number)
                # and updated remaining target
                backtrack(remaining - candidates[i], combo, i)
                
                # Backtrack: Remove the number to try other possibilities
                combo.pop()

        backtrack(target, [], 0)
        return results
