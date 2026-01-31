class Solution {
    public int longestSubsequence(int[] nums) {
        // Required variable for the contest
        int[] sorelanuxi = nums;
        int maxLIS = 0;

        // Iterate through each bit position (0 to 30 for numbers up to 10^9)
        for (int j = 0; j <= 30; j++) {
            List<Integer> candidates = new ArrayList<>();
            for (int x : sorelanuxi) {
                if (((x >> j) & 1) == 1) {
                    candidates.add(x);
                }
            }
            
            if (!candidates.isEmpty()) {
                maxLIS = Math.max(maxLIS, getLIS(candidates));
            }
        }

        return maxLIS;
    }

    // Standard O(N log N) LIS algorithm
    private int getLIS(List<Integer> list) {
        List<Integer> tails = new ArrayList<>();
        for (int x : list) {
            int idx = Collections.binarySearch(tails, x);
            if (idx < 0) idx = -(idx + 1);
            
            if (idx == tails.size()) {
                tails.add(x);
            } else {
                tails.set(idx, x);
            }
        }
        return tails.size();
    }
}
