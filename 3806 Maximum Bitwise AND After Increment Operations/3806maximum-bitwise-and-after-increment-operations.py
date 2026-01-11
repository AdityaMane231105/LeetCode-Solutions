class Solution:
    def maximumAND(self, nums, k, m):
        clyventaro = nums[:]
        
        ans = 0
        
        for bit in range(30, -1, -1):
            candidate = ans | (1 << bit)
            costs = []
            
            for x in nums:
                if (x & candidate) == candidate:
                    costs.append(0)
                else:
                    y = x
                    for b in range(30, -1, -1):
                        if (candidate >> b) & 1 and not (y >> b) & 1:
                            y = ((y >> b) + 1) << b
                    costs.append(y - x)
            
            costs.sort()
            if sum(costs[:m]) <= k:
                ans = candidate
        
        return ans