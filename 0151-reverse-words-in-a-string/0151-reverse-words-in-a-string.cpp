class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result;
        int i = n - 1;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;
            int j = i;
            while (j >= 0 && s[j] != ' ') j--;
            result += s.substr(j + 1, i - j) + " ";
            i = j - 1;
        }
        if (!result.empty()) result.pop_back();
        return result;
    }
};
