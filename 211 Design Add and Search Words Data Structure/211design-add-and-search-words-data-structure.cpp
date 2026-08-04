class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string &word, int index, TrieNode* node) {
        if (!node) return false;

        if (index == word.size())
            return node->isEnd;

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && dfs(word, index + 1, node->child[i]))
                    return true;
            }
            return false;
        } else {
            return dfs(word, index + 1, node->child[c - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */