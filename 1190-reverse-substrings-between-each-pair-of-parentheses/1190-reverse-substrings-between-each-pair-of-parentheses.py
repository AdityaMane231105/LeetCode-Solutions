class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        for char in s:
            if char == ')':
                reversed_sub = []
                while stack and stack[-1] != '(':
                    reversed_sub.append(stack.pop())
                stack.pop()
                stack.extend(reversed_sub)
            else:
                stack.append(char)
        return "".join(stack)
