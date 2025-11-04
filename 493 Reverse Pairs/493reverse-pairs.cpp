#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        long long count = 0;
        int j = mid + 1;

        // Count valid reverse pairs
        for (int i = left; i <= mid; ++i) {
            // advance j while condition holds
            while (j <= right && (long long)nums[i] > 2LL * (long long)nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }

        // Merge the two sorted halves into temp
        vector<int> temp;
        temp.reserve(right - left + 1);
        int i = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        // copy back
        for (int k = left; k <= right; ++k) nums[k] = temp[k - left];

        return count;
    }

    long long mergeSortCount(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        long long cnt = 0;
        cnt += mergeSortCount(nums, left, mid);
        cnt += mergeSortCount(nums, mid + 1, right);
        cnt += mergeAndCount(nums, left, mid, right);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;              // guard against empty vector
        long long res = mergeSortCount(nums, 0, (int)nums.size() - 1);
        return (int)res;
    }
};