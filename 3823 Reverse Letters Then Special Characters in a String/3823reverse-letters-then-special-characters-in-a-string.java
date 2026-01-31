class Solution {
    public String reverseByType(String s) {
        char[] res = s.toCharArray();
        int n = s.length();
        
        // 1. Identify indices for letters and special characters
        List<Integer> letterIdx = new ArrayList<>();
        List<Character> letters = new ArrayList<>();
        List<Integer> specialIdx = new ArrayList<>();
        List<Character> specials = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (Character.isLowerCase(c)) {
                letterIdx.add(i);
                letters.add(c);
            } else {
                specialIdx.add(i);
                specials.add(c);
            }
        }
        
        // 2. Reverse letters and place them back
        int letterSize = letters.size();
        for (int i = 0; i < letterSize; i++) {
            res[letterIdx.get(i)] = letters.get(letterSize - 1 - i);
        }
        
        // 3. Reverse special characters and place them back
        int specialSize = specials.size();
        for (int i = 0; i < specialSize; i++) {
            res[specialIdx.get(i)] = specials.get(specialSize - 1 - i);
        }
        
        return new String(res);
    }
}
