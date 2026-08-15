function longestSubsequence(nums: number[]): number {
    let totalXor = 0;
    let allZeros = true;

    for (const num of nums) {
        totalXor ^= num;
        if (num !== 0) {
            allZeros = false;
        }
    }

    // Case 1: If all elements are zero, no non-zero XOR subsequence can be formed
    if (allZeros) {
        return 0;
    }

    // Case 2 & 3: If total XOR is non-zero, return full length. Otherwise, remove 1 element.
    return totalXor !== 0 ? nums.length : nums.length - 1;
}
