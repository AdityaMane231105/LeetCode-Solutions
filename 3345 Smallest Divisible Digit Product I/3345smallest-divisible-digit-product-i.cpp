class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int prod = 1;
            int temp = n;
            
            // Calculate the product of the digits
            while (temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }
            
            // Check if the product is divisible by t
            if (prod % t == 0) {
                return n;
            }
            
            // Increment to test the next number
            n++;
        }
    }
};
