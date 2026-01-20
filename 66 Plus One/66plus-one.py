class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        
        # Traverse the list from right to left
        for i in range(n - 1, -1, -1):
            # If the current digit is less than 9, just add 1 and return
            if digits[i] < 9:
                digits[i] += 1
                return digits
            
            # If the digit is 9, it becomes 0 and the loop continues to the next digit
            digits[i] = 0
        
        # If the loop finishes, it means all digits were 9 (e.g., [9, 9, 9])
        # We need to add a 1 at the beginning (e.g., [1, 0, 0, 0])
        return [1] + digits
