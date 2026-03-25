#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int res = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int temp = currMax; // Store current max because we update it
        
        // Update max and min by comparing three possibilities
        currMax = MAX(nums[i], MAX(nums[i] * currMax, nums[i] * currMin));
        currMin = MIN(nums[i], MIN(nums[i] * temp, nums[i] * currMin));

        // Keep track of the best result seen so far
        res = MAX(res, currMax);
    }
    return res;
}
