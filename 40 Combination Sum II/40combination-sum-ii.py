class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        candidates.sort()  # Sort to handle duplicates easily

        def backtrack(start, target, path):
            if target == 0:
                res.append(list(path))
                return
            
            for i in range(start, len(candidates)):
                # If the current number is greater than the remaining target, 
                # no need to check further because the list is sorted.
                if candidates[i] > target:
                    break
                
                # Skip duplicates: if the current element is the same as the 
                # previous one and we are in the same recursive level.
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                
                path.append(candidates[i])
                # i + 1 ensures we don't reuse the same element
                backtrack(i + 1, target - candidates[i], path)
                path.pop()

        backtrack(0, target, [])
        return res
