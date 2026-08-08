#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // suffix[i] stores the LARGEST index in word1 from which 
        // word2[i...m-1] can be matched as an exact subsequence.
        vector<int> suffix(m + 1, -1);
        suffix[m] = n; // Base case

        int w1_idx = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            // Find the largest index w1_idx <= suffix[i+1] - 1 where word1[w1_idx] == word2[i]
            w1_idx = min(w1_idx, suffix[i + 1] - 1);
            while (w1_idx >= 0 && word1[w1_idx] != word2[i]) {
                w1_idx--;
            }
            suffix[i] = w1_idx;
        }

        vector<int> result;
        bool used_change = false;
        int p1 = 0; // Current pointer in word1

        for (int p2 = 0; p2 < m; ++p2) {
            bool matched = false;

            while (p1 < n) {
                if (word1[p1] == word2[p2]) {
                    // 1. Direct match without using a change
                    result.push_back(p1);
                    p1++;
                    matched = true;
                    break;
                } else if (!used_change && p1 < suffix[p2 + 1]) {
                    // 2. Wildcard change at index p1
                    result.push_back(p1);
                    used_change = true;
                    p1++;
                    matched = true;
                    break;
                }
                p1++;
            }

            if (!matched) return {};
        }

        return result;
    }
};
