from collections import Counter

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []
        
        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        word_freq = Counter(words)
        results = []
        
        # Iterate over word_len possible starting offsets
        for i in range(word_len):
            left = i
            right = i
            current_count = Counter()
            
            # Slide the window across the string
            while right + word_len <= len(s):
                # Get the next word from the right
                word = s[right:right + word_len]
                right += word_len
                
                if word in word_freq:
                    current_count[word] += 1
                    
                    # If we have more of 'word' than needed, shrink from the left
                    while current_count[word] > word_freq[word]:
                        left_word = s[left:left + word_len]
                        current_count[left_word] -= 1
                        left += word_len
                    
                    # If the window size matches total_len, we found a match
                    if right - left == total_len:
                        results.append(left)
                else:
                    # Word is not in our list, reset the window
                    current_count.clear()
                    left = right
                    
        return results
