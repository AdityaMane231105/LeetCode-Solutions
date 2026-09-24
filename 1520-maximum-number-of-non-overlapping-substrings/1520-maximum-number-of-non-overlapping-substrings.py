class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        first = {c: i for i, c in list(enumerate(s))[::-1]}
        last = {c: i for i, c in enumerate(s)}
        
        valid_intervals = []
        for c in set(s):
            left = first[c]
            right = last[c]
            
            i = left
            is_valid = True
            while i <= right:
                if first[s[i]] < left:
                    is_valid = False
                    break
                right = max(right, last[s[i]])
                i += 1
                
            if is_valid:
                valid_intervals.append((left, right))
                
        valid_intervals.sort(key=lambda x: x[1])
        
        ans = []
        prev_end = -1
        for left, right in valid_intervals:
            if left > prev_end:
                ans.append(s[left:right + 1])
                prev_end = right
                
        return ans
