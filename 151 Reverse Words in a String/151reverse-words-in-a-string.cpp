class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int index = 0; // Tracks where to write the next character

        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // If we aren't at the beginning, add a single space before the word
                if (index != 0) s[index++] = ' ';

                // 2. Identify the end of the current word
                int end = start;
                while (end < n && s[end] != ' ') {
                    s[index++] = s[end++];
                }

                // 3. Reverse the word back to its original orientation
                // index - (end - start) is the beginning of the word just written
                reverse(s.begin() + index - (end - start), s.begin() + index);

                // Move start pointer to the end of the word
                start = end;
            }
        }
        
        // Resize the string to remove trailing old characters
        s.erase(s.begin() + index, s.end());
        return s;
    }
};
