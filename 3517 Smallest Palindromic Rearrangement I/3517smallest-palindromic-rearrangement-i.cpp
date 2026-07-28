#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Count frequencies of each character
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        std::string first_half = "";
        char mid_char = '\0';

        // Step 2 & 3: Distribute characters greedily from 'a' to 'z'
        for (int i = 0; i < 26; ++i) {
            char current_char = 'a' + i;
            
            // Check for the single character that goes in the middle
            if (count[i] % 2 != 0) {
                mid_char = current_char;
            }
            
            // Append half of the occurrences to the first half
            first_half.append(count[i] / 2, current_char);
        }

        // Step 4: Reconstruct the full palindrome
        std::string second_half = first_half;
        std::reverse(second_half.begin(), second_half.end());

        if (mid_char != '\0') {
            return first_half + mid_char + second_half;
        }
        
        return first_half + second_half;
    }
};
