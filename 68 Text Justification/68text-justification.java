class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int n = words.length;
        int i = 0;
        
        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            StringBuilder sb = new StringBuilder();
            int numWords = j - i;
            int numSpaces = maxWidth - (lineLength - (numWords - 1));
            
            // Case 1: Last line or only one word in line (Left Justified)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    sb.append(words[k]);
                    if (k < j - 1) sb.append(" ");
                }
                while (sb.length() < maxWidth) sb.append(" ");
            } 
            // Case 2: Fully Justified
            else {
                int spacesBetween = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);
                
                for (int k = i; k < j; k++) {
                    sb.append(words[k]);
                    if (k < j - 1) {
                        int spacesToApply = spacesBetween + (k - i < extraSpaces ? 1 : 0);
                        for (int s = 0; s < spacesToApply; s++) sb.append(" ");
                    }
                }
            }
            
            res.add(sb.toString());
            i = j;
        }
        return res;
    }
}
