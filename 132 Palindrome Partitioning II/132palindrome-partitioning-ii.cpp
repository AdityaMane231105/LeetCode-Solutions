#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // isPal[i][j] will be true if substring s[i..j] is a palindrome
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));
        // cuts[i] stores the minimum cuts needed for s[0..i]
        std::vector<int> cuts(n, 0);

        for (int i = 0; i < n; ++i) {
            int minCuts = i; // Maximum cuts needed for s[0..i] is i
            for (int j = 0; j <= i; ++j) {
                // Check if s[j..i] is a palindrome
                if (s[i] == s[j] && (i - j <= 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    // If s[0..i] is a palindrome, 0 cuts are needed
                    // Otherwise, it's cuts[j-1] + 1 cut
                    minCuts = (j == 0) ? 0 : std::min(minCuts, cuts[j - 1] + 1);
                }
            }
            cuts[i] = minCuts;
        }

        return cuts[n - 1];
    }
};
