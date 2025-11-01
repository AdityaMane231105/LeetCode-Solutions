class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes
        // Numbers ending with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // For even length numbers, x == reversed
        // For odd length numbers, x == reversed / 10 (middle digit ignored)
        return (x == reversed || x == reversed / 10);
    }
};