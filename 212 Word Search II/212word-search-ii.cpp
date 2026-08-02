#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = ""; // Stores the complete word at the leaf node
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;
    int m, n;

    // Helper to insert words into the Trie
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word; // Mark the end of a valid word
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        int idx = ch - 'a';

        // Base cases: invalid cell or character not in Trie branch
        if (ch == '#' || !node->children[idx]) return;

        node = node->children[idx];

        // Found a matching word
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Prevent duplicate entries in result
        }

        // Mark cell as visited
        board[r][c] = '#';

        // Explore 4-directional neighbors
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] != '#') {
                dfs(board, nr, nc, node);
            }
        }

        // Backtrack: Restore original character
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        m = board.size();
        n = board[0].size();

        // Step 1: Build the Trie with all words
        for (const string& w : words) {
            insert(w);
        }

        // Step 2: Start DFS from every cell on the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
