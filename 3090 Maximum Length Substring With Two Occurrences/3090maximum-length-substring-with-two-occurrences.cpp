class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int max_len = 0;
        vector<int> count(26, 0); // Stores frequencies of lowercase English letters

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            // Shrink the window from the left if any character's frequency exceeds 2
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            // Update the maximum length found so far
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
