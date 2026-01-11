class Solution(object):
    def residuePrefixes(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        seen_chars = set()
        
        # Iterate through the string to evaluate each prefix
        for i in range(len(s)):
            # Add current character to the set of distinct characters
            seen_chars.add(s[i])
            
            # length of current prefix is i + 1
            length = i + 1
            distinct_count = len(seen_chars)
            
            # Check the condition: distinct characters == length % 3
            if distinct_count == (length % 3):
                count += 1
                
        return count
        