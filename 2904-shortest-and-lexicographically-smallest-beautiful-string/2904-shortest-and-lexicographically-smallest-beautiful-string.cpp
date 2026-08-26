class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, count = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') count++;

            while (count >= k) {
                if (count == k) {
                    int len = right - left + 1;
                    string sub = s.substr(left, len);
                    if (len < minLen || (len == minLen && sub < ans)) {
                        minLen = len;
                        ans = sub;
                    }
                }
                if (s[left] == '1') count--;
                left++;
            }
        }
        return ans;
    }
};
