#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];
        unordered_set<int> present_elements;
        
        // Find min, max and store existing numbers
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
            present_elements.insert(num);
        }
        
        vector<int> missing;
        // Check for missing integers within the range [min_val, max_val]
        for (int i = min_val + 1; i < max_val; ++i) {
            if (present_elements.find(i) == present_elements.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};
