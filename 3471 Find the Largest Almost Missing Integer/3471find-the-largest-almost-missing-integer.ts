function largestInteger(nums: number[], k: number): number {
    const subarrayCounts = new Map<number, number>();
    const n = nums.length;

    // Iterate through all possible subarrays of size k
    for (let i = 0; i <= n - k; i++) {
        const uniqueInSubarray = new Set<number>();
        
        // Add elements of the current subarray to the set
        for (let j = i; j < i + k; j++) {
            uniqueInSubarray.add(nums[j]);
        }
        
        // Increment the subarray appearance count for each unique element
        for (const num of uniqueInSubarray) {
            subarrayCounts.set(num, (subarrayCounts.get(num) || 0) + 1);
        }
    }

    let maxAlmostMissing = -1;

    // Find the largest element that appeared in exactly one subarray
    for (const [num, count] of subarrayCounts.entries()) {
        if (count === 1) {
            maxAlmostMissing = Math.max(maxAlmostMissing, num);
        }
    }

    return maxAlmostMissing;
}
