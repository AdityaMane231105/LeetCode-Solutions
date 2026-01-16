class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        
        def backtrack(open_n, closed_n, current_str):
            # Base case: if we have used all n pairs
            if open_n == closed_n == n:
                res.append(current_str)
                return
            
            # Rule 1: We can always add an opening bracket if we haven't reached n
            if open_n < n:
                backtrack(open_n + 1, closed_n, current_str + "(")
            
            # Rule 2: We can only add a closing bracket if it doesn't exceed open brackets
            if closed_n < open_n:
                backtrack(open_n, closed_n + 1, current_str + ")")
        
        backtrack(0, 0, "")
        return res
