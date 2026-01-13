#include <string.h>

int numDecodings(char* s) {
    if (s == NULL || s[0] == '0') {
        return 0;
    }

    int n = strlen(s);
    // dp[i] will store the number of ways to decode the prefix of length i
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    // Base cases
    dp[0] = 1; // An empty string has 1 way to be decoded (doing nothing)
    dp[1] = 1; // We already checked s[0] != '0'

    for (int i = 2; i <= n; i++) {
        // Single digit decode: Check if the character at s[i-1] is valid (1-9)
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // Two digit decode: Check if s[i-2]s[i-1] is between 10 and 26
        int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}
