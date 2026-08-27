#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int best_i = -1;
        int best_char = -1;
        
        vector<int> current_count = count;
        
        for (int i = 0; i < n; ++i) {
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (current_count[c] > 0) {
                    best_i = i;
                    best_char = c;
                    break;
                }
            }
            
            int t_char = target[i] - 'a';
            if (current_count[t_char] > 0) {
                current_count[t_char]--;
            } else {
                break;
            }
        }
        
        if (best_i == -1) {
            return "";
        }
        
        string ans = target.substr(0, best_i);
        
        vector<int> final_count = count;
        for (int i = 0; i < best_i; ++i) {
            final_count[target[i] - 'a']--;
        }
        
        ans += (char)('a' + best_char);
        final_count[best_char]--;
        
        for (int c = 0; c < 26; ++c) {
            while (final_count[c] > 0) {
                ans += (char)('a' + c);
                final_count[c]--;
            }
        }
        
        return ans;
    }
};
