int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            // Min is in the right part
            low = mid + 1;
        } else if (nums[mid] < nums[high]) {
            // Min is at mid or in the left part
            high = mid;
        } else {
            // nums[mid] == nums[high], shrink the search space
            high--;
        }
    }
    return nums[low];
}
