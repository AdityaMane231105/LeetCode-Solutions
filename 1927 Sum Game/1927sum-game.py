class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        mid = n // 2
        
        # Split into left and right halves
        left_half = num[:mid]
        right_half = num[mid:]
        
        # Calculate sums and count '?' for both sides
        L_sum = sum(int(c) for c in left_half if c != '?')
        R_sum = sum(int(c) for c in right_half if c != '?')
        
        L_q = left_half.count('?')
        R_q = right_half.count('?')
        
        # Bob wins if the differences perfectly balance out via pairs of 9
        # Otherwise, Alice wins
        return (L_sum - R_sum) != (R_q - L_q) / 2 * 9
