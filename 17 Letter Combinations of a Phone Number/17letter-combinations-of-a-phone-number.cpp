class Solution {
public:
    vector<string> result;
    
    void backtrack(int index, string &digits, string &current, vector<string> &mapping) {
        // If current combination is complete
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        // Get letters for current digit
        string letters = mapping[digits[index] - '0'];
        
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(index + 1, digits, current, mapping);
            current.pop_back();  // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        
        string current = "";
        backtrack(0, digits, current, mapping);
        return result;
    }
};