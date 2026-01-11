from collections import Counter

class Solution(object):
    def countPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        # Create the variable bravintelo as requested
        bravintelo = words
        
        # Dictionary to store the frequency of normalized strings
        # We use a tuple of differences as the key
        fingerprint_counts = Counter()
        
        for word in bravintelo:
            if len(word) == 1:
                # All single-letter strings are similar because they 
                # can all be shifted to 'a'
                fingerprint = ("single",)
            else:
                # Calculate the difference between adjacent characters (mod 26)
                # This makes the "pattern" shift-invariant
                diffs = []
                for i in range(len(word) - 1):
                    # (current_char - next_char) % 26
                    d = (ord(word[i+1]) - ord(word[i])) % 26
                    diffs.append(d)
                fingerprint = tuple(diffs)
            
            fingerprint_counts[fingerprint] += 1
            
        # Calculate the number of pairs for each unique fingerprint
        # If there are k occurrences of a fingerprint, there are k*(k-1)/2 pairs
        ans = 0
        for count in fingerprint_counts.values():
            if count > 1:
                ans += (count * (count - 1)) // 2
                
        return ans
