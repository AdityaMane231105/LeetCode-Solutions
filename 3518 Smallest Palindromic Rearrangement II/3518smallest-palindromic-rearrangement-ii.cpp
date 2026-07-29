class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                mid += char('a' + i);
            }
            half[i] = freq[i] / 2;
        }

        int halfLen = 0;
        for (int x : half) halfLen += x;

        auto countWays = [&](vector<int>& cnt) -> long long {
            int total = 0;
            for (int x : cnt) total += x;

            long double res = 1.0;

            for (int i = 0; i < 26; i++) {
                int c = cnt[i];
                for (int j = 1; j <= c; j++) {
                    res *= (total - c + j);
                    res /= j;

                    if (res > 1e18)
                        return (long long)1e18;
                }
                total -= c;
            }

            return (long long)(res + 0.5);
        };

        if (countWays(half) < k)
            return "";

        string firstHalf;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    firstHalf += char('a' + ch);
                    break;
                } else {
                    k -= ways;
                    half[ch]++;
                }
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + mid + secondHalf;
    }
};