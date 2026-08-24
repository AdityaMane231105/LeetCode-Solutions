from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        # dp[i] stores the max relative score a player can get starting from index i
        dp = [0] * (n + 1)
        
        # Build the table bottom-up from the end of the array
        for i in range(n - 1, -1, -1):
            take = 0
            best = float('-inf')
            
            # The player can take 1, 2, or 3 stones
            for k in range(1, 4):
                if i + k <= n:
                    take += stoneValue[i + k - 1]
                    best = max(best, take - dp[i + k])
            
            dp[i] = best
        
        # dp[0] represents Alice's max relative score at the start of the game
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"
