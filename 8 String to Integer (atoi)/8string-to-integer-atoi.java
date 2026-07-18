
class Solution {
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int i = 0;
        int n = s.length();

        // 1. Skip leading whitespaces
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        // Check if string was only spaces
        if (i == n) {
            return 0;
        }

        // 2. Check for optional sign
        int sign = 1;
        if (s.charAt(i) == '+') {
            i++;
        } else if (s.charAt(i) == '-') {
            sign = -1;
            i++;
        }

        int result = 0;

        // 3. Convert characters to integer and prevent overflow
        while (i < n) {
            char ch = s.charAt(i);
            
            // Stop parsing if a non-digit character is encountered
            if (ch < '0' || ch > '9') {
                break;
            }

            int digit = ch - '0';

            // 4. Over/Underflow protection before actual multiplication
            // Integer.MAX_VALUE is 2147483647. Max_Value / 10 is 214748364.
            if (result > Integer.MAX_VALUE / 10 || 
               (result == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
}
