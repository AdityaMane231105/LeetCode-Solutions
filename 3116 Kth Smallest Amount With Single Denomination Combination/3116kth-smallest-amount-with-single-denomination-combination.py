import math
from typing import List

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        def countMultiples(mid: int) -> int:
            count = 0
            n = len(coins)
            for i in range(1, 1 << n):
                lcm_val = 1
                bits = 0
                for j in range(n):
                    if (i >> j) & 1:
                        bits += 1
                        lcm_val = (lcm_val * coins[j]) // math.gcd(lcm_val, coins[j])
                        if lcm_val > mid:
                            break
                if bits % 2 == 1:
                    count += mid // lcm_val
                else:
                    count -= mid // lcm_val
            return count

        low = 1
        high = k * min(coins)
        ans = high

        while low <= high:
            mid = (low + high) // 2
            if countMultiples(mid) >= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return ans
