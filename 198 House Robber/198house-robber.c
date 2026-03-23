#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    // rob_prev2 represents max money up to two houses ago
    // rob_prev1 represents max money up to the previous house
    int rob_prev2 = 0;
    int rob_prev1 = 0;

    for (int i = 0; i < numsSize; i++) {
        // At each house, we decide:
        // 1. Skip this house (take the max money from the previous house)
        // 2. Rob this house (take money from 2 houses ago + current house)
        int current = MAX(rob_prev1, rob_prev2 + nums[i]);
        
        // Update pointers for the next iteration
        rob_prev2 = rob_prev1;
        rob_prev1 = current;
    }

    return rob_prev1;
}
