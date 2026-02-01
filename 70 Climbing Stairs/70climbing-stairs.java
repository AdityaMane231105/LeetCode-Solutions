class Solution {
    public int climbStairs(int n) {
        // Base cases: 1 way for n=1, 2 ways for n=2
        if (n <= 2) return n;
        
        int first = 1;  // Ways to reach step 1
        int second = 2; // Ways to reach step 2
        
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        
        return second;
    }
}
