class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        result = [0] * k
        dp = [0] * k
        
        for num in nums:
            v = num % k
            next_dp = [0] * k
            
            for p in range(k):
                if dp[p] > 0:
                    next_dp[(p * v) % k] += dp[p]
            
            next_dp[v] += 1
            
            for x in range(k):
                result[x] += next_dp[x]
                
            dp = next_dp
            
        return result
