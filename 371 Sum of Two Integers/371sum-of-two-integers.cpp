class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Calculate carry: bits that are 1 in both a and b
            // Cast to unsigned to handle potential overflow with negative numbers
            unsigned int carry = (unsigned int)(a & b) << 1;
            
            // Sum without carry: bits that are 1 in either a or b, but not both
            a = a ^ b;
            
            // Update b to the carry to add it in the next iteration
            b = carry;
        }
        return a;
    }
};
