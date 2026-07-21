class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        String t = "1" + s + "1";

        int ones = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') ones++;
        }

        int maxGain = 0;

        for (int i = 1; i < t.length() - 1; ) {
            if (t.charAt(i) == '1') {
                int j = i;
                while (j < t.length() && t.charAt(j) == '1') j++;

                if (t.charAt(i - 1) == '0' && j < t.length() && t.charAt(j) == '0') {

                    int leftZero = 0;
                    int k = i - 1;
                    while (k >= 0 && t.charAt(k) == '0') {
                        leftZero++;
                        k--;
                    }

                    int rightZero = 0;
                    k = j;
                    while (k < t.length() && t.charAt(k) == '0') {
                        rightZero++;
                        k++;
                    }

                    maxGain = Math.max(maxGain, leftZero + rightZero);
                }
                i = j;
            } else {
                i++;
            }
        }

        return ones + maxGain;
    }
}