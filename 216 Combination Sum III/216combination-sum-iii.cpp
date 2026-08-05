class Solution {
public:
    void backtrack(int target, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if combination has k elements and targets exactly matches
        if (current.size() == k) {
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }
        
        // Loop through candidate numbers 1 to 9
        for (int i = start; i <= 9; ++i) {
            // Pruning: if current number exceeds remaining target, stop further exploration
            if (i > target) break;
            
            current.push_back(i); // Choose
            backtrack(target - i, k, i + 1, current, result); // Recurse with next number
            current.pop_back(); // Undo choice (Backtrack)
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
};
