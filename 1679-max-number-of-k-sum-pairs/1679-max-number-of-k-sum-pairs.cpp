class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int operations = 0;
        for (int num : nums) {
            int target = k - num;
            if (freq[target] > 0) {
                operations++;
                freq[target]--;
            } else {
                freq[num]++;
            }
        }
        return operations;
    }
};
