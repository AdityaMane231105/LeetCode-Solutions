class Solution {
    public boolean isNumber(String s) {
        s = s.trim();  // remove leading/trailing spaces
        
        boolean seenDigit = false;
        boolean seenDot = false;
        boolean seenE = false;
        boolean digitAfterE = true;  // important for cases like "1e"
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (Character.isDigit(c)) {
                seenDigit = true;
                digitAfterE = true;
            }
            else if (c == '+' || c == '-') {
                // sign is only valid at start or just after e/E
                if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') {
                    return false;
                }
            }
            else if (c == '.') {
                // dot not allowed after e or if already seen
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // e must come after a digit and only once
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                digitAfterE = false; // must see digit after e
            }
            else {
                // any other character is invalid
                return false;
            }
        }
        
        return seenDigit && digitAfterE;
    }
}