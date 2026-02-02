import java.util.*;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        // Optimization: Valid IP must be between 4 and 12 characters
        if (s.length() < 4 || s.length() > 12) return res;
        backtrack(s, 0, new ArrayList<>(), res);
        return res;
    }

    private void backtrack(String s, int index, List<String> path, List<String> res) {
        // Base Case: If we have 4 segments and reached the end of the string
        if (path.size() == 4) {
            if (index == s.length()) {
                res.add(String.join(".", path));
            }
            return;
        }

        // Explore segments of length 1, 2, or 3
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.length()) break;

            String segment = s.substring(index, index + len);
            
            // Check if segment is valid (no leading zeros unless it's "0", and value <= 255)
            if ((segment.startsWith("0") && segment.length() > 1) || 
                (len == 3 && Integer.parseInt(segment) > 255)) {
                continue;
            }

            path.add(segment); // Choose
            backtrack(s, index + len, path, res); // Explore
            path.remove(path.size() - 1); // Un-choose (Backtrack)
        }
    }
}
