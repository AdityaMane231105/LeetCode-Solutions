#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class SparseTable {
    vector<vector<int>> st;
    vector<int> lg;
public:
    SparseTable(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        int max_log = log2(n) + 1;
        st.assign(max_log, vector<int>(n));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < n; ++i) st[0][i] = nums[i];

        for (int j = 1; j < max_log; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        int j = lg[r - l + 1];
        return max(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

class Solution {
    struct Group {
        int start, length;
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pref_ones(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref_ones[i + 1] = pref_ones[i] + (s[i] == '1');
        }
        int totalOnesInS = pref_ones[n];

        vector<Group> zeroGroups;
        vector<int> zeroGroupIdx(n, -1);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }
            zeroGroupIdx[i] = (int)zeroGroups.size() - 1;
        }

        int m = zeroGroups.size();
        vector<int> adjacentSums(max(0, m - 1));
        for (int i = 0; i < m - 1; ++i) {
            adjacentSums[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        }

        SparseTable st(adjacentSums);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int onesInRange = pref_ones[r + 1] - pref_ones[l];
            int maxOnesInRange = onesInRange;

            int gL = zeroGroupIdx[l];
            int gR = zeroGroupIdx[r];

            int left = (gL != -1 && s[l] == '0') ? (zeroGroups[gL].length - (l - zeroGroups[gL].start)) : 0;
            int right = (gR != -1 && s[r] == '0') ? (r - zeroGroups[gR].start + 1) : 0;

            int startAdj = gL + 1;
            int endGroup = (s[r] == '1') ? gR : (gR - 1);
            int endAdj = endGroup - 1;

            // 1. Two zero groups split inside [l, r]
            if (s[l] == '0' && s[r] == '0' && gL + 1 == gR) {
                maxOnesInRange = max(maxOnesInRange, onesInRange + left + right);
            } 
            // 2. Query sparse table for fully contained zero groups
            else if (startAdj <= endAdj) {
                maxOnesInRange = max(maxOnesInRange, onesInRange + st.query(startAdj, endAdj));
            }

            // 3. Truncated left group + next full group
            if (s[l] == '0' && gL + 1 <= endGroup) {
                maxOnesInRange = max(maxOnesInRange, onesInRange + left + zeroGroups[gL + 1].length);
            }

            // 4. Truncated right group + previous full group
            if (s[r] == '0' && gL < gR - 1) {
                maxOnesInRange = max(maxOnesInRange, onesInRange + right + zeroGroups[gR - 1].length);
            }

            // Total active sections across the entire string s
            int totalActiveSections = (totalOnesInS - onesInRange) + maxOnesInRange;
            ans.push_back(totalActiveSections);
        }

        return ans;
    }
};
