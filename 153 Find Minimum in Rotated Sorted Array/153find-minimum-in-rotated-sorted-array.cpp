class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum is in the right part, mid can't be the min
                left = mid + 1;
            } else {
                // Minimum is mid or in the left part
                right = mid;
            }
        }
        return nums[left];
    }
};
