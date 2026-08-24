from typing import List

class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        n = len(stones)
        
        # Compute prefix sums
        pref = [0] * n
        pref[0] = stones[0]
        for i in range(1, n):
            pref[i] = pref[i - 1] + stones[i]
            
        # Base case: if only the last option remains, the player must take it
        # dp[n-1] = pref[n-1]
        res = pref[-1]
        
        # Traverse backwards from n-2 down to 1
        for i in range(n - 2, 0, -1):
            res = max(res, pref[i] - res)
            
        return res
