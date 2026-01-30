class Solution {
    public boolean isIsomorphic(String s, String t) {
        // Arrays to store the last seen positions (ASCII size 256)
        int[] mapS = new int[256];
        int[] mapT = new int[256];
        
        for (int i = 0; i < s.length(); i++) {
            char charS = s.charAt(i);
            char charT = t.charAt(i);
            
            // If the last seen positions don't match, it's not isomorphic
            if (mapS[charS] != mapT[charT]) {
                return false;
            }
            
            // Update positions (using i + 1 because default array value is 0)
            mapS[charS] = i + 1;
            mapT[charT] = i + 1;
        }
        
        return true;
    }
}
