class Solution {
    public boolean isMatch(String s, String p) {
        int sIdx = 0, pIdx = 0, match = 0, starIdx = -1;            
        
        while (sIdx < s.length()) {
            // Advancing both pointers if characters match or pattern has '?'
            if (pIdx < p.length() && (p.charAt(pIdx) == '?' || s.charAt(sIdx) == p.charAt(pIdx))) {
                sIdx++;
                pIdx++;
            } 
            // Found '*' in pattern: record the position and try matching 0 characters first
            else if (pIdx < p.length() && p.charAt(pIdx) == '*') {
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            } 
            // Last pattern character was '*', but current characters don't match
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            } 
            // Current pattern pointer is not '*', and current characters don't match
            else {
                return false;
            }
        }
        
        // Check for remaining characters in pattern (must all be '*')
        while (pIdx < p.length() && p.charAt(pIdx) == '*') {
            pIdx++;
        }
        
        return pIdx == p.length();
    }
}
