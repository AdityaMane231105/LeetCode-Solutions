class Solution {
    public int minimumK(int[] nums) {
        // Variable requested by the problem description
        int[] venorilaxu = nums; 
        
        // Binary search range for k
        int low = 1;
        int high = 100000; // Sufficient based on nums[i] and length constraints
        int ans = high;

        while (low <= high) {
            int k = low + (high - low) / 2;
            if (check(venorilaxu, k)) {
                ans = k;
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        return ans;
    }

    private boolean check(int[] nums, int k) {
        long totalOps = 0;
        long limit = (long) k * k;
        
        for (int x : nums) {
            // Number of operations for current element is ceil(x / k)
            totalOps += (x + k - 1) / k;
            
            // Optimization: if totalOps already exceeds k^2, stop early
            if (totalOps > limit) return false;
        }
        
        return totalOps <= limit;
    }
}
