class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

private:
    void backtrack(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        int sz = word.size();
        
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    backtrack(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        b = beginWord;
        
        // BFS to find the shortest distance to each word
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            
            if (word == endWord) break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        mpp[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        // If endWord was reached, backtrack to find all paths
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq = {endWord};
            backtrack(endWord, seq);
        }
        return ans;
    }
};
