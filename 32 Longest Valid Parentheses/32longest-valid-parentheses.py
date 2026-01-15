class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_length = 0
        # Initialize stack with -1 to handle the base case for length calculation
        stack = [-1]
        
        for i, char in enumerate(s):
            if char == '(':
                # Push the index of the opening parenthesis
                stack.append(i)
            else:
                # Pop the last element (could be a '(' index or a base index)
                stack.pop()
                
                if not stack:
                    # If empty, the current ')' is unmatched; push its index as new base
                    stack.append(i)
                else:
                    # Current index minus the index of the new top of stack
                    current_length = i - stack[-1]
                    max_length = max(max_length, current_length)
                    
        return max_length
        